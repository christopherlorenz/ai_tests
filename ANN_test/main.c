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
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	int training_data_size = 2;
	int training_data_rows = 22;

	// Upper and lower bound on random values in training data (-bound is lower bound)
	int bound = 10;

	double **training_data = malloc(sizeof(double *)*training_data_rows);
	for(int i = 0; i < training_data_rows; i++)
	{
		training_data[i] = malloc(sizeof(double *)*training_data_size);
	}

	create_dataset(training_data_size, training_data_rows, training_data, bound);

	for(int i = 0; i < training_data_rows; i++)
	{
		for(int j = 0; j < training_data_size; j++)
		{
			printf("%f\t",training_data[i][j]);
		}
		printf("\n");
	}


	return 0;
}





