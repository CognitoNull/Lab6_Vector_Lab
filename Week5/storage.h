/**********************************************************************************
 * @file storage.h
 * @brief  
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version 
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/

#ifndef STORAGE_H
#define STORAGE_H

#include "vector.h"

#define MAX_VECTORS 10

int addvect(vect newvect);
vect *findvect(char *name);
void list_vectors(void);
void clear_vectors(void);

#endif