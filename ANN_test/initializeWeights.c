// Function to initialize weights for backpropagation
// Chris Lorenz
// 6/8/17

#include "initializeWeights.h"
#include <stdlib.h>

void initializeWeights(int numLayers, int *nNodes, int type, double ***weights)
{
	int bound = 1;	

	//Uniformly distributed values
	if(type == 0)
	{
		for(int i = 0; i < numLayers-1; i++)
		{
			for(int j = 0; j < nNodes[i]; j++)
			{
				for(int k = 0; k < nNodes[i+1]-1; k++)
				{
					weights[i][j][k] = 2*bound*((double)rand()/RAND_MAX-0.5);
				}
			}
		}	
	}
	//NOT IMPLEMENTED
	//Normally distributed initial weights
	else if(type == 1)
	{
	}
	else
	{
	}
}

