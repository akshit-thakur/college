#include <iostream>
using namespace std;

int **soln; //n*W matrix which stores the intermediate and final result.
int *p;		//stores the profit of the items
int *wt;	//stores the weights of the items
int **keep; //keep track of whether item is included in the result of intermediate and final solution

int main()
{
	int n;	//no. of items
	int w;	//weight of knapsack
	int i, j; //loop counters

	/*Take input*/
	cout << "Enter the number of items: ";
	cin >> n;

	cout << "Enter the weight of knapsack: ";
	cin >> w;
	//Array initializations
	soln = new int *[n + 1]; //because there is also a case where 0 items are to be considered
	keep = new int *[n + 1];
	for (i = 0; i < n + 1; i++)
	{
		soln[i] = new int[w + 1]; //because there is also a case where weight of knapsack is to be zero.(intermediate result)
		keep[i] = new int[w + 1];
	}

	p = new int[n];
	wt = new int[n];

	cout << "Enter the profits and weights for " << n << " items\n";
	for (i = 0; i < n; i++)
		cin >> p[i] >> wt[i];

	//Skipping the filling with constants part soln[0,j] = 0
	/*Finding the solution*/
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < w + 1; j++)
		{
			if (i == 1)
			{
				if (wt[0] <= j)
				{
					soln[i][j] = p[0];
					keep[i][j] = 1;
				}
			}
			else
			{
				if (soln[i - 1][j] < soln[i - 1][j - wt[i - 1]] + p[i - 1] && wt[i - 1] <= j)
				{
					// soln[i-soln][1] > j[i-1][j - weight[i] ] + profit[i] && weight of item is less than or equal to weight of knapsack
					soln[i][j] = soln[i - 1][j - wt[i - 1]] + p[i - 1];
					keep[i][j] = 1;
				}
				else
					soln[i][j] = soln[i - 1][j];
			}
		}
	}

	/*
	cout << "The solution matrix\n\n";
	for( i = 0; i<=n; i++){
		for( j =0; j<=w; j++)
			cout << soln[i][j]<<" ";
		cout << "\n";
	}
	
	cout << "The keep matrix\n\n";
	for( i = 0; i<=n; i++){
		for( j =0; j<=w; j++)
			cout << keep[i][j]<<" ";
		cout << "\n";
	}
	*/
	cout << "The maximum profit for the 0/1 Knapsack is: " << soln[n][w] << "\n";
	cout << "The items included are:\n";
	j = w;
	for (i = n; i > 0, j > 0; i--)
	{
		if (keep[i][j] == 1)
		{
			cout << i << "\n";
			j -= wt[i - 1];
		}
	}
	return 0;
}	