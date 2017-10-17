// Use forward propagation to calculate outputs from neural net
// Chris Lorenz
// 6/8/17

#include "calcPredicted.h"
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

void calcPredicted(double **a, int numLayers, int *nNodes, double ***weights)
{
	
	for(int i = 0; i < numLayers; i++)
	{
		if(i == 0)
		{
		}
		else if (i == numLayers - 1)
		{
			for(int j = 0; j < nNodes[i]; j++)
			{
				a[i][j] = 0;
				for(int k = 0; k < nNodes[i-1]; k++)
				{
					a[i][j] = a[i][j] + weights[i-1][k][j]*a[i-1][k];
				}
				a[i][j] = a[i][j];
			}
		}
		else
		{
			a[i][0] = 1.0;
			for(int j = 1; j < nNodes[i]; j++)
			{
				a[i][j] = 0;
				for(int k = 0; k < nNodes[i-1]; k++)
				{
					a[i][j] = a[i][j] + weights[i-1][k][j-1]*a[i-1][k];
				}
				printf("\n%f",a[i][j]);
				a[i][j] = 1.0/(1.0+exp(-a[i][j]));
			}
		
		}
	}
}


