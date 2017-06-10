// Perform backpropagation to calculate weight derivatives to improve ANN solution
// Chris Lorenz
// 6/10/2017


#include "backPropagation.h"
#include <stdlib.h>

void backPropagation(double ***dCdw, double *outputData, double **a, int numLayers, int *nNodes, double ***weights)
{
	//Instantiate Deltas
	double **delta = malloc(sizeof(double *)*numLayers);
	for(int i = 0; i < numLayers; i++)
	{
		delta[i] = malloc(sizeof(double)*nNodes[i]);
	}


	//Calculate dCdw for output layer
	//Using linear activations for output	
	for(int i = 0; i < nNodes[numLayers-1]; i++)
	{
		delta[numLayers-1][i] = (a[numLayers -1][i] - outputData[i])*a[numLayers-1][i];
		for(int j = 0; j < nNodes[numLayers - 2]; j++)
		{
			dCdw[numLayers-2][j][i] = delta[numLayers-1][i]*a[numLayers -2][j];
		}
	}	
	
}
