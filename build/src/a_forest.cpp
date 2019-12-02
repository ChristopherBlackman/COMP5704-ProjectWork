#include "a_forest.h"
#include <random>
#include <algorithm>
#include <unordered_map>
#include "utils.h"



void link(unsigned int a, unsigned int b,std::atomic<unsigned int>* arr);
void compress(unsigned a,std::atomic<unsigned int>* arr);
unsigned int sample_frequent_element(std::atomic<unsigned int>* arr,const unsigned int& size, unsigned int num_samples = 1024);

/* func  : a_forest
 * input : const unsigned int size
 *		- size of all id's
 * input : const unsigned int*
 * 		- size of all lists of lists
 * input : const unsigned int**
 * 		- graph represented as a adjacany list
 * Description : a_forest without random sampling
 */

void a_forest(unsigned int size, unsigned int* adj_count, unsigned int** adj_list){

	std::atomic<unsigned int>* directed_tree = new std::atomic<unsigned int>[size];

	// set each id, to it's self
	std::cout << "Init : Afforest No Sampling" << std::endl;
	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int i = 0; i < size; i++){
		directed_tree[i].store(i,std::memory_order_relaxed);
	}

	// i : node
	// j : neigbour
	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int i = 0; i < size; i++){
		#pragma omp parallel for num_threads(NUM_CORES)
		for (unsigned int j = 0; j < adj_count[i]; j++){
			link(i,adj_list[i][j],directed_tree);
		}
	}
	// i : node
	// j : neigbour
	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int i = 0; i < size; i++){
		compress(i,directed_tree);
	}

	#ifdef DEBUG
	for(unsigned int i = 0; i < size; i++){
		std::cout << directed_tree[i] << std::endl;
	}
	#endif
	delete[] directed_tree;

}



/* func  : a_forest_sample
 * input : const unsigned int size
 *		- size of all id's
 * input : const unsigned int*
 * 		- size of all lists of lists
 * input : const unsigned int**
 * 		- graph represented as a adjacany list
 * input : unsigned int neigbour_rounds
 * 		- number of samples
 * input : unsigned int sample_count
 * 		- number of samples taken
 * Description : a_forest with random sampling
 */

void a_forest_sample(unsigned int size, unsigned int* adj_count, unsigned int** adj_list,unsigned int neigbour_rounds,unsigned int sample_count){

	std::atomic<unsigned int>* directed_tree = new std::atomic<unsigned int>[size];

	// set each id, to it's self
	std::cout << "Init : Afforest Sampling" << std::endl;

	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int i = 0; i < size; i++){
		directed_tree[i].store(i,std::memory_order_relaxed);
	}

	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int n = 0; n < neigbour_rounds; n++){
		#pragma omp parallel for num_threads(NUM_CORES)
		for(unsigned int i = 0; i < size; i++){
			if(adj_count[i] > n){
				link(i,adj_list[i][n],directed_tree);
			}
		}
	}

	// i : node
	// j : neigbour
	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int i = 0; i < size; i++){
		compress(i,directed_tree);
	}

	unsigned int most_frequent = sample_frequent_element(directed_tree,size, 1024);


	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int i = 0; i < size; i++){
		
		//skip
		if(directed_tree[i].load(std::memory_order_relaxed) == most_frequent) continue;	

		#pragma omp parallel for num_threads(NUM_CORES)
		for(unsigned int j = neigbour_rounds; j < adj_count[i]; j++){
			link(i,adj_list[i][j],directed_tree);
		}
	}

	// i : node
	// j : neigbour
	#pragma omp parallel for num_threads(NUM_CORES)
	for(unsigned int i = 0; i < size; i++){
		compress(i,directed_tree);
	}


	#ifdef DEBUG
	for(unsigned int i = 0; i < size; i++){
		std::cout << directed_tree[i] << std::endl;
	}
	#endif

	delete[] directed_tree;

}


unsigned int sample_frequent_element(std::atomic<unsigned int>* arr,const unsigned int& size, unsigned int num_samples){
	std::unordered_map<unsigned int,unsigned int> sample_counts(32);
	std::mt19937 gen;
	std::uniform_int_distribution<unsigned int> distribution(0,size-1);

	unsigned int maximum = 0;
	unsigned int id = 0;

	for(unsigned int i = 0; i < num_samples; i++){
		unsigned int j = distribution(gen);
		sample_counts[arr[j]]++;
	}

	for(std::pair<unsigned int,unsigned int> element : sample_counts){
		if(element.second > maximum){
			maximum = element.second;
			id = element.first;
		}
	}

	std::cout << "Selected Element : " << id << " with frequency : " << static_cast<float>(maximum)/static_cast<float>(num_samples) << std::endl;
	return id;

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
