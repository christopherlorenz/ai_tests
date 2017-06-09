// Artificial Neural Network (ANN) Test Program
// Simple ANN with 1 hidden layer
//
//
// Created by: Chris Lorenz
//
// 03/02/2017: File created
//
//
//
#include "create_dataset.h"
#include "initialize_weights.h"
#include "rescale_data.h"
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
	for(int i = 0; i < dataRows; i++)
	{
		inputData[i] = malloc(sizeof(double *)*dataSize);
		scaledData[i] = malloc(sizeof(double *)*dataSize);
	}

	create_dataset(dataSize, dataRows, inputData, bound);

	

	//Read in input
	
	//Rescale Data
	rescale_data(dataRows, dataSize, inputData, scaledData);
	
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

	int nNodes[3] = {numInputs, 4, numOutputs};
	int numLayers = sizeof(nNodes)/sizeof(nNodes[0]);
	int type = 0;
	
	double ***weights = malloc(sizeof(double *)*sizeof(nNodes)/sizeof(nNodes[0])-1);
	for(int i = 0; i < sizeof(nNodes)/sizeof(nNodes[0])-1; i++)
	{
		weights[i] = malloc(sizeof(double *)*nNodes[i]);
		for(int j = 0; j < nNodes[i]; j++)
		{
			weights[i][j] = malloc(sizeof(double *)*nNodes[i+1]);
		}
	}

	initialize_weights(numLayers, nNodes, type, weights);
	
	
	
	//Calculate predicted values with forward propagation
	
	//Calculate Mean square error
	
	//Perform backpropagation to update values
	
	

	return 0;
}





