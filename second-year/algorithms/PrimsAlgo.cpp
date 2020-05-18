/*
0	-1	-1	-1	3	4	-1
-1	0	8	-1	-1	9	-1 
-1	8	0	7	-1	6	-1
-1	-1	7	0	-1	-1	5  
3	-1	-1	-1	0	-1	10 
4	9	6	-1	-1	0	2
-1	-1	-1	5	10	2	0
*/
/*
0	6	4	9
6	0	2	1
4	2	0	5
9	1	5	0
*/

#define INFY 12345
#include <iostream>

using namespace std;

int **cost;

int **soln; /* (n-1) * 2 */

void prim(int n)
{
	int i, j;	 /*loop counters*/
	int k;		  /*pointer related to graph as well as counter for solution matrix*/
	int l, u = 0; /*pointer related to the graphs*/

	int mincost; /*sum of cost of all edges included in the solution*/

	int min = cost[0][1];

	int *near = new int[n];

	//find k,l such that k and l are the vertices of edge having minimum cost and add that cost to mincost;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (cost[i][j] < min && cost[i][j] > 0)
			{
				k = i;
				l = j;
				min = cost[i][j];
			}
		}
	}

	mincost = cost[k][l];

	//initialize near
	for (i = 0; i < n; i++)
	{
		if (cost[i][l] > cost[i][k])
			near[i] = k; //k is nearer to i than l
		else
			near[i] = l;
	}
	//near[i]=-1 implies that node is already visited.
	near[k] = -1;
	near[l] = -1;
	soln[0][0] = k + 1;
	soln[0][1] = l + 1;

	k = 1;

	for (i = 1; i < n - 1; i++)
	{
		//choose u such that near[u]!=0 and cost[u,near[u]] is min
		min = cost[0][1];

		for (j = 0; j < n; j++)
		{

			if (near[j] >= 0)
			{
				if (cost[j][near[j]] < min && cost[j][near[j]] > 0)
				{
					u = j;
					min = cost[j][near[j]];
				}
			}
		}

		mincost += cost[u][near[u]];

		//add (u,near[u]) to the solution tree
		soln[k][0] = u + 1;
		soln[k++][1] = near[u] + 1;

		for (int w = 0; w < n; w++)
		{
			if (near[w] >= 0 && cost[w][near[w]] > cost[u][w] && cost[w][near[w]] != INFY && cost[u][w] != INFY)
				near[w] = u;
		}
	}
	cout << "The cost of MST is: " << mincost << "\n";
}

int main()
{
	int n;	/*The number of vertices in the graph*/
	int i, j; /*loop counters*/

	/*Take input*/
	cout << "Enter the number of vertices: ";
	cin >> n;

	//initialize arrays
	cost = new int *[n];

	for (i = 0; i < n; i++)
		cost[i] = new int[n];

	soln = new int *[n - 1];
	for (i = 0; i < n - 1; i++)
		soln[i] = new int[2];

	//fill the cost matrix
	cout << "Enter the cost matrix:(negative for no edge)\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> cost[i][j];
			if (cost[i][j] < 0)
				cost[i][j] = INFY;
		}
	}

	//apply Prim's algorithm for MST
	prim(n);

	//print the solution MST
	cout << "The MST has edges \n";
	for (i = 0; i < n - 1; i++)
		cout << soln[i][0] << "->" << soln[i][1] << "\n";
	return 0;
}