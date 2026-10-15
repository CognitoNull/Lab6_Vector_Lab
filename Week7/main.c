/**********************************************************************************
 * @file main.c
 * @brief  
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/
#include <stdio.h>
#include <string.h>
#include "interface.h"

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "-h") == 0)
    {
        print_help();
        return 0;
    }

    run_interface();

    return 0;
}