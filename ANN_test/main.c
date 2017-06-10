// Artificial Neural Network (ANN) Test Program
// Simple ANN with 1 hidden layer
//
//
// Created by: Chris Lorenz
//
// 03/02/2017: File created
// 06/06/2017: Uniform data rescaling and uniform weight initialization added
// 06/10/2017: Forward propagation added

#include "createDataset.h"
#include "initializeWeights.h"
#include "rescaleData.h"
#include "calcPredicted.h"
#include "backPropagation.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	int dataSize = 2;
	int dataRows = 22;

	// Upper and lower bound on random values in training data (-bound is lower bound)
	int bound = 10;

	double **inputData = malloc(sizeof(double *)*dataRows);
	double **scaledData = malloc(sizeof(double *)*dataRows);
	double **outputData = malloc(sizeof(double *)*dataRows);
	for(int i = 0; i < dataRows; i++)
	{
		inputData[i] = malloc(sizeof(double)*dataSize);
		scaledData[i] = malloc(sizeof(double)*dataSize);
		outputData[i] = malloc(sizeof(double)*1);
		outputData[i][0] = i;
	}

	createDataset(dataSize, dataRows, inputData, bound);
	

	//Read in input
	
	//Rescale Data
	rescaleData(dataRows, dataSize, inputData, scaledData);
	
	for(int i = 0; i < dataRows; i++)
	{
		for(int j = 0; j < dataSize; j++)
		{
			printf("%f\t",scaledData[i][j]);
		}
		printf("\n");
	}
	
	//Initialize Weights
	int numInputs = 3;
	int numOutputs = 1;	

	double eta = 0.05;

	int nNodes[3] = {numInputs, 4, numOutputs};
	int numLayers = sizeof(nNodes)/sizeof(nNodes[0]);
	int type = 0;
	
	double ***weights = malloc(sizeof(double *)*(numLayers-1));
	for(int i = 0; i < numLayers-1; i++)
	{
		weights[i] = malloc(sizeof(double *)*nNodes[i]);
		for(int j = 0; j < nNodes[i]; j++)
		{
			weights[i][j] = malloc(sizeof(double)*nNodes[i+1]-1);
		}
	}

	initializeWeights(numLayers, nNodes, type, weights);
	
	
	
	//Calculate predicted values with forward propagation
	
	//Instantiate a's (node values in neural net)
	double **a = malloc(sizeof(double *)*numLayers);
	for(int i = 0; i < numLayers; i++)
	{
		a[i] = malloc(sizeof(double)*nNodes[i+1]);
	}

	//Instantiate weight derivatives
	double ***dCdw = malloc(sizeof(double *)*(numLayers-1));
	for(int i = 0; i < numLayers-1; i++)
	{
		dCdw[i] = malloc(sizeof(double *)*nNodes[i]);
		for(int j = 0; j < nNodes[i]; j++)
		{
			dCdw[i][j] = malloc(sizeof(double)*nNodes[i+1]-1);
		}
	}

	for(int i = 0; i < dataRows; i++)
	{
		for(int j = 0; j < dataSize; j++)
		{
			a[0][j] = scaledData[i][j];
		}
		calcPredicted(a, numLayers, nNodes, weights);
		backPropagation(dCdw, outputData[i], a, numLayers, nNodes, weights);

		//Iterate through all weights to update
		for(int j = 0; j < numLayers - 1; j++)
		{
			for(int k = 0; k < nNodes[j]; k++)
			{
				for(int l  = 0; l < nNodes[j+1] - 1; l++)
				{
					weights[j][k][l] = weights[j][k][l] - eta*dCdw[j][k][l];
				}
			}
		}
	}

	//Calculate Mean square error
	
	//Perform backpropagation to update values
	
	

	return 0;
}





