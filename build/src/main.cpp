#include <iostream>
#include <vector>
#include "rapidcsv.h"
#include <cstdio>
#include <string.h>
#include <unordered_map>
#include <set>
#include "a_forest.h"

#include <stdio.h>

//#define DEBUG

int main(int argc,char** argv)
{
	if (argc < 3) {exit(0);}

	char* file_path = argv[1];
	char delimiter = argv[2][0];
	
	printf("FILE : %s \n",file_path);
	printf("DELIMITER : %c \n",delimiter);




	// assume input has id ranging from 0...n-1 (continous)
	//get input data in csv format (no header)
	//
	// integer,integer
	//     .  ,   .
	//     .  ,   .
	//     .  ,   .
	// integer,integer
	
	rapidcsv::Document* doc = new rapidcsv::Document(file_path,rapidcsv::LabelParams(-1,-1),rapidcsv::SeparatorParams(delimiter));


	std::vector<unsigned int> edge_a = doc->GetColumn<unsigned int>(0);
	std::vector<unsigned int> edge_b = doc->GetColumn<unsigned int>(1);

	
	delete doc;

	std::cout << "Part 2" << std::endl;

	std::cout << "Read " << edge_a.size() << " values." << std::endl;
	std::cout << "Read " << edge_b.size() << " values." << std::endl;



	// matrix with graph edges

	std::unordered_map<unsigned int,std::unordered_map<unsigned int,char>> matrix;


	std::cout << "Creating Matrix" << std::endl;

	for(unsigned int i = 0; i < edge_a.size(); i++){
		matrix[edge_a[i]][edge_b[i]] = 1;
		matrix[edge_b[i]][edge_a[i]] = 1;
	}


	// id's of nodes 

	std::set<unsigned int> ids;

	std::cout << "Getting Node IDs" << std::endl;

	for(unsigned int i = 0; i < edge_a.size(); i++){
		ids.insert(edge_a[i]);
		ids.insert(edge_b[i]);
	}

	edge_a.clear();
	edge_b.clear();

	// easy lock free non-zero data-structure
	unsigned int   id_count  = (unsigned int) ids.size();
	unsigned int*  adj_count = (unsigned int *)  malloc(sizeof(unsigned int  )*ids.size());
	unsigned int** adj_list  = (unsigned int **) malloc(sizeof(unsigned int *)*ids.size());


	std::cout << "Creating A-List" << std::endl;
	//initialize tables 
	//#pragma omp parallel for
	for(unsigned int i = 0; i < ids.size(); i++){
		int j = 0;
		adj_list[i] = (unsigned int*) malloc(sizeof(unsigned int )*matrix[i].size());
		adj_count[i]= matrix[i].size();

		for(const auto& n : matrix[i]){
			adj_list[i][j] = n.first;
			j++;
		}
	}


	matrix.clear();

	#ifdef DEBUG	
	for(unsigned int i = 0; i < id_count; i++){
		std::cout << i << " : ";

		for(unsigned int j = 0; j < adj_count[i];j++){
			std::cout << adj_list[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	#endif

	a_forest(id_count,adj_count,adj_list);
	a_forest_sample(id_count,adj_count,adj_list,2,1024);


	for(unsigned int i = 0; i < ids.size(); i++){
		free(adj_list[i]);
	}

	free(adj_list);
	free(adj_count);
	
}
