/**********************************************************************************
 * @file interface.c
 * @brief  
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "interface.h"
#include "storage.h"
#include "vector.h"

/* Tells user their single word command options*/
void print_help(void)
{
    printf("Vector Calculator Commands:\n");
    printf(" help              Display this help screen\n");
    printf(" list              List stored vectors\n");
    printf(" clear             Clear stored vectors\n");
    printf(" quit              Exit program\n");
    printf(" a = 1 2 3         Assign vector\n");
    printf(" a                 Display vector\n");
    printf(" a + b             Add vectors\n");
    printf(" a - b             Subtract vectors\n");
    printf(" a * 2 or 2 * a    Scalar multiplication\n");
}

static void print_vector(vect v)
{
    printf("%s = %.2f %.2f %.2f\n",
           v.name, v.x, v.y, v.z);
}

static int read_number(const char *s, double *value)
{
    char *end;
    *value = strtod(s, &end);

    if (s == end)
        return 0;

    while (isspace((unsigned char)*end))
        end++;

    return *end =='\0';
}

static int evaluate(char *left, char op, char *right,
                    vect *result)
{
    vect *a;
    vect *b;
    double scalar;

    a = findvect(left);
    b = findvect(right);

    if (op == '+' || op == '-')
    {
        if (a == NULL || b == NULL)
        {
            printf("Vector not found.\n");
            return 0;
        }
        if (op == '+')
            *result = add(*a, *b);
        else
            *result = subtract(*a, *b);

        return 1;
    }

    if (op == '*')
    {
        if (a != NULL && read_number(right, &scalar))
        {
            *result = multiply(*a, scalar);
            return 1;
        }
        if (b != NULL && read_number(left, &scalar))
        {
            *result = multiply(*b, scalar);
            return 1;
        }

        printf("Invalid scalar multiplication.\n");
        return 0;
    }
    printf("Invalid operator.\n");
    return 0;
}

void run_interface(void)
{
    char input[100];
    char name[20];
    char left[20];
    char right[20];
    char op;
    char extra;
    char *expression;
    char *equals;
    char *p;
    double x;
    double y;
    double z;
    vect result;
    vect *found;
    vect newvect;

    while(1)
    {
        printf("minimat> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
        break;
        }

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
        else if (sscanf(input, "%19s %c %19s %c",
            left, &op, right, &extra) == 3
            && (op == '+' || op == '-' || op == '*'))
            {
                if (evaluate(left, op, right, &result))
                {
                    strcpy(result.name, "ans");
                    print_vector(result);
                }
            }
        else if (sscanf(input, "%19s %c", name, &extra) == 1)
        {
            found = findvect(name);
        
            if (found != NULL)
            {
                print_vector(*found);
            }
            else
            {
                printf("Vector not found.\n");
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
        }
    }