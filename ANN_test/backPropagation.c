// Perform backpropagation to calculate weight derivatives to improve ANN solution
// Chris Lorenz
// 6/10/2017


#include "backPropagation.h"
#include <stdlib.h>
#include <stdio.h>

void backPropagation(double ***dCdw, double *outputData, double **a, int numLayers, int *nNodes, double ***weights)
{
	//Instantiate Deltas
	// Note: I realized there's an extra first index in here but I didn't want to break it trying to fix it so indexing starts with 1 and 0 can be ignored for "delta"
	double **delta = malloc(sizeof(double *)*numLayers);
	for(int i = 0; i < numLayers; i++)
	{
		delta[i] = malloc(sizeof(double)*nNodes[i]);
	}
	printf("\n");

	//Calculate dCdw for output layer
	//Using linear activations for output	
	for(int i = 0; i < nNodes[numLayers-1]; i++)
	{
		delta[numLayers-1][i] = (a[numLayers -1][i] - outputData[i]); // commented out on 8/26/17 based on matlab model response*a[numLayers-1][i];
		printf("%f\t",a[numLayers-1][i]);
		printf("%f\t",outputData[i]);
		printf("%f\t",delta[numLayers-1][i]);
		for(int j = 0; j < nNodes[numLayers - 2]; j++)
		{
			dCdw[numLayers-2][j][i] = delta[numLayers-1][i]*a[numLayers -2][j];
			printf("%f\t",dCdw[numLayers-2][j][i]);
		}
	}	
	printf("\n");

	//Calculate dCdw for hidden layers
	//Using sigmoidal activiations for hidden layers
	int layer = numLayers-1;
	while(layer > 1)
	{
		layer = layer - 1;
		for(int j = 1; j < nNodes[layer]; j++)
		{
			for(int k = 0; k < nNodes[layer-1]; k++)
			{
				double sum = 0.0;
				for(int l = 0; l < nNodes[layer+1]; l++)
				{
					sum = sum + weights[layer][j][l]*delta[layer+1][l];
				}
				delta[layer][j] = a[layer][j]*(1.0-a[layer][j])*sum;
				dCdw[layer-1][k][j-1] = delta[layer][j]*a[layer-1][k];
				printf("%f\t",a[layer-1][k]);
				printf("%f\t",weights[layer][j][0]);
				printf("%f\t\n",dCdw[layer-1][k][j-1]);
			}			
		}
	}
}
