// Create Data function for ANN test
// Created by: Chris Lorenz
//
//
// 03/02/2017: Created file
//
//
//

#include "createDataset.h"
#include <stdlib.h>

void createDataset(int num_inputs, int dataset_size, double **data, int bound)
{
	srand(23);
	
	for(int i = 0; i < dataset_size; i++)
	{
		for(int j = 0; j < num_inputs; j++)
		{
			data[i][j] = 2*bound*((double)rand()/RAND_MAX-0.5);
		}
	}
}

