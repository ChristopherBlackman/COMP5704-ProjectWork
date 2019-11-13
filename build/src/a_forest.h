#ifndef A_FOREST_H
#define A_FOREST_H

/*
 * input : size   -- the number of unique ID's (assume from 0..n-1)
 * input : matrix -- the input graph (might change an adjacancy list or CSR lock free)
 */
void a_forest(	const unsigned int  	size, 
		const unsigned int* 	adj_count,
		const unsigned int** 	adj_list);

#endif
