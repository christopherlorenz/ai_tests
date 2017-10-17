// Artificial Neural Network (ANN) Test Program
// Simple ANN with 1 hidden layer
//
//
// Created by: Chris Lorenz
//
// 03/02/2017: File created
// 06/06/2017: Uniform data rescaling and uniform weight initialization added
// 06/10/2017: Forward propagation added, backpropagation started
// 06/18/2017: Backpropagation completed (untested)

#include "createDataset.h"
#include "initializeWeights.h"
#include "rescaleData.h"
#include "calcPredicted.h"
#include "backPropagation.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	srand(0);
	int dataSize = 2;
	int dataRows = 2;

	int outputSize = 1;

	// Upper and lower bound on random values in training data (-bound is lower bound)
	int bound = 10;

	double **inputData = malloc(sizeof(double *)*dataRows);
	double **scaledData = malloc(sizeof(double *)*dataRows);
	double **outputData = malloc(sizeof(double *)*dataRows);
	for(int i = 0; i < dataRows; i++)
	{
		inputData[i] = malloc(sizeof(double)*dataSize);
		scaledData[i] = malloc(sizeof(double)*dataSize);
		outputData[i] = malloc(sizeof(double)*outputSize);
	}

	createDataset(dataSize, dataRows, inputData, outputData, bound);
	

	//Read in input
	
	//Rescale Data
	rescaleData(dataRows, dataSize, inputData, scaledData);

	//Print rescaled data
	for(int i = 0; i < dataRows; i++)
	{
		for(int j = 0; j < dataSize; j++)
		{
			printf("%f\t",inputData[i][j]);
			printf("%f\t\n",scaledData[i][j]);
		}
		printf("\n");
	}
	
	//Initialize Weights
	int numInputs = 3;
	int numOutputs = 1;	

	double eta = 0.05;
	int epochs = 1;

	int nNodes[3] = {numInputs, 3, numOutputs};
	int numLayers = sizeof(nNodes)/sizeof(nNodes[0]);
	int type = 0;

	srand(0);	
	//Allocate weight matrix
	double ***weights = malloc(sizeof(double *)*(numLayers-1));
	for(int i = 0; i < numLayers-1; i++)
	{
		weights[i] = malloc(sizeof(double *)*nNodes[i]);
		for(int j = 0; j < nNodes[i]; j++)
		{
			if(i == numLayers-2)
			{
				weights[i][j] = malloc(sizeof(double)*nNodes[i+1]);
			}
			else
			{
				weights[i][j] = malloc(sizeof(double)*nNodes[i+1]-1);
			}
		}
	}
	
	//Initialize weights to random values
	initializeWeights(numLayers, nNodes, type, weights);
	
		
	//Instantiate a's (node values in neural net)
	double **a = malloc(sizeof(double *)*numLayers);
	for(int i = 0; i < numLayers; i++)
	{
		a[i] = malloc(sizeof(double)*nNodes[i]);
	}

	//Instantiate weight derivatives
	double ***dCdw = malloc(sizeof(double *)*(numLayers-1));
	for(int i = 0; i < numLayers-1; i++)
	{
		dCdw[i] = malloc(sizeof(double *)*nNodes[i]);
		for(int j = 0; j < nNodes[i]; j++)
		{
			if(i == numLayers - 2)
			{
				dCdw[i][j] = malloc(sizeof(double)*nNodes[i+1]);
			}
			else
			{
				dCdw[i][j] = malloc(sizeof(double)*nNodes[i+1]-1);
			}
		}
	}
	printf("\nWeights\n");
	for(int i = 0; i < numLayers-1; i++)
	{
		for(int j = 0; j < nNodes[i]; j++)
		{
			if(i == numLayers-2)
			{
				for(int k = 0; k < nNodes[i+1];k++)
				{
					printf("%f\t",weights[i][j][k]);
				}
			}
			else
			{
				for(int k = 0; k < nNodes[i+1]-1;k++)
				{
					printf("%f\t",weights[i][j][k]);
				}
			}
			printf("\n");
		}
	}

	//Main loop that optimizes node weights using input data
	for(int i = 0; i < dataRows*epochs; i++)
	{
		// Pack inputs into first row of a matrix
		a[0][0] = 1.0;
		for(int j = 0; j < dataSize; j++)
		{
			a[0][j+1] = scaledData[i % dataRows][j];
		}

		//Calculate predicted values with forward propagation
		calcPredicted(a, numLayers, nNodes, weights);
		printf("\nA Matrix\n");
		for(int i = 0; i < numLayers; i++)
		{
			for(int j = 0; j < nNodes[i]; j++)
			{
				printf("%f\t",a[i][j]);
			}
			printf("\n");
		}
		//Calculate weight derivatives for update
		backPropagation(dCdw, outputData[i % dataRows], a, numLayers, nNodes, weights);
//		printf("%f\n",weights[1][0][0]);
		//Iterate through all weights to update
		for(int j = 0; j < numLayers - 1; j++)
		{
			for(int k = 0; k < nNodes[j]; k++)
			{
				if (j == numLayers-2)
				{
					for(int l  = 0; l < nNodes[j+1]; l++)
					{
						weights[j][k][l] = weights[j][k][l] - eta*dCdw[j][k][l];
//						printf("%f\t",dCdw[j][k][l]);
					}

				}
				else
				{
					for(int l  = 0; l < nNodes[j+1] - 1; l++)
					{
						weights[j][k][l] = weights[j][k][l] - eta*dCdw[j][k][l];
//						printf("%f\t",dCdw[j][k][l]);
					}
				}
			}
		}
	}
/*
	printf("\nWeights\n");
	for(int i = 0; i < numLayers-1; i++)
	{
		for(int j = 0; j < nNodes[i]; j++)
		{
			if(i == numLayers-2)
			{
				for(int k = 0; k < nNodes[i+1];k++)
				{
					printf("%f\t",weights[i][j][k]);
				}
			}
			else
			{
				for(int k = 0; k < nNodes[i+1]-1;k++)
				{
					printf("%f\t",weights[i][j][k]);
				}
			}
			printf("\n");
		}
	}
*/
	
	//Print actual output values and calculated outputs from NN
	printf("\n\nScaled Input 1\tScaled Input 2\tTrue Outputs\tPredictions\n");
	for(int i = 0; i < dataRows; i++)
	{
		printf("%f\t%f\t%f\t",scaledData[i][0],scaledData[i][1],outputData[i][0]);
		a[0][0] = 1.0;
		for(int j = 0; j < dataSize; j++)
		{
			a[0][j+1] = scaledData[i][j];		
		}
		calcPredicted(a, numLayers, nNodes, weights);
		printf("%f\n", a[2][0]);
	}
/*
	printf("\nA Matrix\n");
	for(int i = 0; i < numLayers; i++)
	{
		for(int j = 0; j < nNodes[i]; j++)
		{
			printf("%f\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
*/
}





