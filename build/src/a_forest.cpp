#include "a_forest.h"



void link(unsigned int a, unsigned int b,std::atomic<unsigned int>* arr);

void compress(unsigned a,std::atomic<unsigned int>* arr);

/* func  : a_forest
 * input : const unsigned int size
 *		- size of all id's
 * input : const unsigned int*
 * 		- size of all lists of lists
 * input : const unsigned int**
 * 		- graph represented as a adjacany list
 */

void a_forest(unsigned int size, unsigned int* adj_count, unsigned int** adj_list){

	std::atomic<unsigned int>* directed_tree = new std::atomic<unsigned int>[size];

	// set each id, to it's self
	std::cout << "Init Tree" << std::endl;
	#pragma omp parallel for
	for(unsigned int i = 0; i < size; i++){
		directed_tree[i].store(i,std::memory_order_relaxed);
	}

	#pragma omp parallel for
	for(unsigned int i = 0; i < size; i++){
		#pragma omp parallel for
		for (unsigned int j = 0; j < adj_count[i]; j++){
			// call link operation
		}
	}

	#pragma omp parallel for
	for(unsigned int i = 0; i < size; i++){
		#pragma omp parallel for
		for (unsigned int j = 0; j < adj_count[i]; j++){
			// call compress operation
		}
	}

}


/* func  : link
 * input : unsigned int a
 * 		- edge with vertex a
 * input : unsigned int b
 * 		- edge with vertex b
 * input/output : std::atomic<unsigned int>* arr
 */
void link(unsigned int a, unsigned int b,std::atomic<unsigned int>* arr){
	unsigned int p1 = arr[a].load(std::memory_order_relaxed);
	unsigned int p2 = arr[b].load(std::memory_order_relaxed);
	unsigned int h  = 0;
	unsigned int l  = 0;
	while (p1 != p2){
		h = std::max(p1,p2);
		l = std::min(p1,p2);
		if (std::atomic_compare_exchange_strong(arr+h,&h,l)) return;

		p1 = arr[arr[h].load(std::memory_order_relaxed)].load(std::memory_order_relaxed);
		p2 = arr[l].load(std::memory_order_relaxed);
	}
	return;
}

/* func  : compress
 * input : unsigned int a
 * 		- edge with vertex a
 * input/output : atomic<unsigned int>* arr
 * description : since algorithm goes for a per vertex, we know that the vertex we are working on will never be editied only by one thread.
 * 		 We know the last vertex in the tree will always be the root. ( so if updated, it will always point to the root)
 */
void compress(unsigned a,std::atomic<unsigned int>* arr){
	while(arr[arr[a].load(std::memory_order_relaxed)].load(std::memory_order_relaxed) != arr[a].load(std::memory_order_relaxed)){
		arr[a].store(arr[arr[a].load(std::memory_order_relaxed)].load(std::memory_order_relaxed),std::memory_order_relaxed);
	}

}
