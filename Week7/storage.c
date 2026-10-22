/**********************************************************************************
 * @file storage.c
 * @brief  
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "storage.h"

static vect *vectors = NULL;
static int count = 0;
static int capacity = 0;

/* function to find a given vector by name*/
vect *findvect(char *name)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(vectors[i].name, name) == 0)
        {
            return &vectors[i];
        }
    }

    return NULL;
}

/* function to add or replace a vector*/
int addvect(vect newvect)
{
    vect *existing;
    vect *temp;
    int new_capacity;

    existing = findvect(newvect.name);

    if (existing != NULL)
    {
        *existing = newvect;
        return 0;
    }
/* Increase memory when storage is full*/
    if (count == capacity)
    {
        new_capacity = (capacity == 0) ? 10 : capacity * 2;

        temp = realloc(vectors, new_capacity * sizeof(vect));

        if (temp == NULL)
        {
            return -1;
        }

        vectors = temp;
        capacity = new_capacity;
    }

    vectors[count] = newvect;
    count++;

    return 0;
}

/* one word command function to list 
 * vectors name and xyz coords*/
void list_vectors(void)
{
    int i;
    
    for (i = 0; i < count; i++)
    {
        printf("%s = %.2f %.2f %.2f\n",
            vectors[i].name,
            vectors[i].x,
            vectors[i].y,
            vectors[i].z);
    }
}

/* one word command function to clear vectors*/
void clear_vectors(void)
{
    free(vectors);

    vectors = NULL;
    count = 0;
    capacity = 0;
}

/* Release memory on exit*/
void free_vectors(void)
{
    clear_vectors();
}

/* Load vectors from a CSV file. */
int load_vectors(const char *filename)
{
    FILE *file;
    char line[256];
    char extra;
    vect newvect;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return -1;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strspn(line, " \t\r\n") == strlen(line))
            continue;

        if (strchr(line, '\n') == NULL && !feof(file))
        {
            printf("CSV line is too long.\n");
            fclose(file);
            return -1;
        }

        if (sscanf(line, " %19[^,],%lf,%lf,%lf %c",
                   newvect.name, &newvect.x, &newvect.y,
                   &newvect.z, &extra) != 4)
        {
            printf("Invalid CSV line.\n");
            fclose(file);
            return -1;
        }

        if (addvect(newvect) != 0)
        {
            printf("Not enough memory to load vectors.\n");
            fclose(file);
            return -1;
        }
    }

    if (ferror(file))
    {
        printf("Could not read file.\n");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

/* Save stored vectors to a CSV file. */
int save_vectors(const char *filename)
{
    FILE *file;
    int i;

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Could not open file for saving.\n");
        return -1;
    }

    for (i = 0; i < count; i++)
    {
        if (fprintf(file, "%s,%.17g,%.17g,%.17g\n",
                    vectors[i].name, vectors[i].x,
                    vectors[i].y, vectors[i].z) < 0)
        {
            printf("Could not write file.\n");
            fclose(file);
            return -1;
        }
    }

    if (fclose(file) != 0)
    {
        printf("Could not finish saving file.\n");
        return -1;
    }

    return 0;
}
