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

    return;
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