// Use forward propagation to calculate outputs from neural net
// Chris Lorenz
// 6/8/17

#include "calcPredicted.h"
#include <stdlib.h>

void calcPredicted(double **a, int numLayers, int *nNodes, double ***weights)
{
	
	for(int i = 0; i < numLayers; i++)
	{
		if(i == 0)
		{
			
		}
		else
		{
			for(int j = 0; j < nNodes[i+1]; j++)
			{
				a[i][j] = 0;
				for(int k = 0; k < nNodes[i]; k++)
				{
					a[i][j] = a[i][j] + weights[i][j][k]*a[i-1][k];
				} 
			}
		}
	}
}


