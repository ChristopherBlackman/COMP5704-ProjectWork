#ifndef A_FOREST_H
#define A_FOREST_H

#include <iostream>
#include <cstdio>
#include <math.h>
#include <atomic>

/*
 * input : const unsigned int size
 *		- size of all id's
 * input : const unsigned int*
 * 		- size of all lists of lists
 * input : const unsigned int**
 * 		- graph represented as a adjacany list
 */
void a_forest(unsigned int size, unsigned int* adj_count, unsigned int** adj_list);

#endif
