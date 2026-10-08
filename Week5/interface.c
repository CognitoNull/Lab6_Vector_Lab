/**********************************************************************************
 * @file interface.c
 * @brief  
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "storage.h"

/* Tells user their single word command options*/
void print_help(void)
{
    printf("Vector Calculator Commands:\n");
    printf(" help          Display this help screen\n");
    printf(" list          List stored vectors\n");
    printf(" clear         Clear stored vectors\n");
    printf(" quit          Exit program\n");
}


void run_interface(void)
{
    char input[100];
    char name[20];
    double x;
    double y;
    double z;
    vect newvect;

    while(1)
    {
        printf("minimat> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0)
        {
            break;
        }
        else if (strcmp(input, "help") == 0)
        {
            print_help();
        }
        else if (strcmp(input, "list") == 0)
        {
            list_vectors();
        }
        else if (strcmp(input, "clear") == 0)
        {
            clear_vectors();
        }
        else if (sscanf(input, "%19s = %lf %lf %lf",
                        name, &x, &y, &z) == 4)
        {
            strcpy(newvect.name, name);
            newvect.x = x;
            newvect.y = y;
            newvect.z = z;

            if (addvect(newvect) == 0)
            {
                printf("%s = %.2f %.2f %.2f\n",
                    newvect.name,
                    newvect.x,
                    newvect.y,
                    newvect.z);
            }
            else
            {
                printf("Vector memory full.\n");
            }
        }
    }
}