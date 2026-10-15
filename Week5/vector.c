/**********************************************************************************
 * @file vector.c
 * @brief  
 * @author Jonathan Cortes
 * @date 10/15/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/

#include "vector.h"

vect add(vect a, vect b)
{
    vect result = a;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

vect subtract(vect a, vect b)
{
    vect result =a;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

vect multiply(vect a, double scalar)
{
    vect result = a;

    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;

    return result;
}
