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

void createDataset(int dataSize, int dataRows, double **inputData, double **outputData, int bound)
{
	
	for(int i = 0; i < dataRows; i++)
	{
		for(int j = 0; j < dataSize; j++)
		{
			inputData[i][j] = 2*bound*((double)rand()/RAND_MAX-0.5);
		}
		outputData[i][0] = inputData[i][0]*inputData[i][1];//inputData[i][0] + inputData[i][1]*inputData[i][1];
	}
}

