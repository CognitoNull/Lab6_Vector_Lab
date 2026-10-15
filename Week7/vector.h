/**********************************************************************************
 * @file vector.h
 * @brief  
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    char name[20];
    double x;
    double y;
    double z;
} vect;

vect add(vect a, vect b);
vect subtract(vect a, vect b);
vect multiply(vect a, double scalar);

#endif