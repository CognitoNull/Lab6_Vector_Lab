/**********************************************************************************
 * @file storage.c
 * @brief  
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include "storage.h"

static vect vectors[MAX_VECTORS];

/* function to find a given vector by name*/
vect *findvect(char *name)
{
    int i;

    for (i = 0; i < MAX_VECTORS; i++)
    {
        if (strcmp(vectors[i].name, name) == 0)
        {
            return &vectors[i];
        }
    }

    return NULL;
}

/* function to add a vector to an array*/
int addvect(vect newvect)
{
    int i;
    vect *existing;

    existing = findvect(newvect.name);

    if (existing != NULL)
    {
        *existing = newvect;
        return 0;
    }

    for (i = 0; i < MAX_VECTORS; i++)
    {
        if (vectors[i].name[0] == '\0')
        {
            vectors[i] = newvect;
            return 0;
        }
    }

    return -1;
}

/* one word command function to list 
 * vectors name and xyz coords*/
void list_vectors(void)
{
    int i;
    
    for (i = 0; i < MAX_VECTORS; i++)
    {
        if (vectors[i].name[0] != '\0')
        {
            printf("%s = %.2f %.2f %.2f\n",
                vectors[i].name,
                vectors[i].x,
                vectors[i].y,
                vectors[i].z);
        }
    }
}

/* one word command function to clear vectors*/
void clear_vectors(void)
{
    int i;

    for (i = 0; i < MAX_VECTORS; i++)
    {
        vectors[i].name[0] = '\0';
    }
}