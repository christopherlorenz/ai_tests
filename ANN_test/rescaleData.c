// Rescales input data to -1 to 1 range for numerical ease of convergence
// Chris Lorenz
// 6/8/17

#include "rescaleData.h"
#include <float.h>
#include <stdlib.h>

void rescaleData(int dataRows, int dataSize, double **inputData, double **scaledData)
{
	double *max = malloc(sizeof(double*)*dataSize);
	double *min = malloc(sizeof(double*)*dataSize);

	//Find max and min values for each input
	for(int i = 0; i < dataSize; i++)
	{
		max[i] = -DBL_MAX;
		min[i] = DBL_MAX;
		for(int j = 0; j < dataRows; j++)
		{
			if(inputData[j][i] > max[i])
			{
				max[i] = inputData[j][i];
			}
			if(inputData[j][i] < min[i])
			{
				min[i] = inputData[j][i];
			}
		}
	}

	//Scale based on max and min values
 	for(int i = 0; i < dataSize; i++)
	{
		for(int j = 0; j < dataRows; j++)
		{
			scaledData[j][i] = (inputData[j][i]-0.5*(max[i]+min[i]))/(0.5*(max[i]-min[i]));
		}
	}	
}
