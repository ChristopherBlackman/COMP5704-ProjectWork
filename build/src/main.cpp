#include <iostream>
#include <vector>
#include "rapidcsv.h"
#include <cstdio>
#include <string.h>
#include <unordered_map>
#include <set>

int main(int argc,char** argv)
{
	if (argc < 3) {exit(0);}

	char* file_path = argv[1];
	char delimiter = argv[2][0];
	
	printf("FILE : %s \n",file_path);
	printf("DELIMITER : %c \n",delimiter);





	//get input data in csv format (no header)
	//
	// integer,integer
	//     .  ,   .
	//     .  ,   .
	//     .  ,   .
	// integer,integer
	
	rapidcsv::Document doc(file_path,rapidcsv::LabelParams(-1,-1),rapidcsv::SeparatorParams(delimiter));

	std::vector<unsigned int> edge_a = doc.GetColumn<unsigned int>(0);
	std::vector<unsigned int> edge_b = doc.GetColumn<unsigned int>(1);

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
}
