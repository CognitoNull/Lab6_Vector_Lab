/**********************************************************************************
 * @file storage.h
 * @brief  Lab 7 version of Vector Calculator
 * @author Jonathan Cortes
 * @date 10/01/2026
 * @version Lab 7
 * @copyright Copyright (C) 2026 Jonathan Cortes. All rights reserved.
**********************************************************************************/

#ifndef STORAGE_H
#define STORAGE_H

#include "vector.h"

int addvect(vect newvect);
vect *findvect(char *name);
void list_vectors(void);
void clear_vectors(void);
void free_vectors(void);
int load_vectors(const char *filename);
int save_vectors(const char *filename);

#endif