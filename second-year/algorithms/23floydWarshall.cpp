/*
0   -1	2	-1
1	0	-1	-1
-1	-1	0	4
5	6	-1	0
*/
/*
0	5	-1	-1	-1
-1	0	-1	4	-1
-1	2	0	6	-1
-1	-1	-1	0	-1
1	-1	3	-1	0
*/
#define INFY 12345
#include<iostream>
using namespace std;

int** cost; //cost matrix containing the weights of the edges
int** last; //the final output is stored in this matrix
int** pred; //contains the node number visited(if any). pred[i,j] = k means path from i to j goes through k

void path( int i , int j ){ //prints the shortest path from vertex i to j
	if( last[i][j] == -1) //if no path exists, final solution will have -1/INFY to indicate that
		cout<<"No path exists\n";
	else if( pred[i][j] == 0 ) //base case
		cout << i+1 << " -> "<< j+1 << "\n";
	else{
		path( i, pred[i][j] - 1);  //find vertices in the path from i to k
		path( pred[i][j] - 1, j ); //find vertices in the path from k to j
	}
}

int main(){
	int n; //number of vertices
	int i,j,k; //loop variables
	
	/** Take input */
	cout << "Enter number of vertices: ";
	cin >> n;
	
	//Array initialization
	cost = new int*[n];
	last = new int*[n];
	pred = new int*[n];
	
	for( i = 0; i < n; i++){
		cost[i] = new int[n];
		last[i] = new int[n];
		pred[i] = new int[n];
	}
	
	//filling up cost matrix
	cout << "Enter cost matrix(negative value for no edge):\n";
	for( i = 0; i < n; i++){
		for( j = 0; j < n; j++){
			cin >> cost[i][j];
			if(cost[i][j] < 0)
			cost[i][j] = INFY;
			last[i][j] = cost[i][j]; // A(0) = cost
		}
	}
	
	for( k = 0; k < n; k++){
		for( i = 0; i < n; i++){
			for( j = 0; j <n; j++){
				if( last[i][j] > last[i][k] + last[k][j] ){ //A(k) = min ( A[i,j] , A[i,k] + A[k,j] )
					last[i][j] = last[i][k] + last[k][j];
					pred[i][j] = k+1;	//store the vertex number as path passes through k
				}
			}
		}
	}
	
	/** Display output */
	cout << "All the possible shortest paths are: \n";
	for( i = 0; i < n; i++ ){
		for( j = 0; j < n; j++ ){
			if( last[i][j] == INFY )
				last[i][j] = -1;
			cout << last[i][j] << " ";
		}
		cout << "\n";
	} 

	/*Find path between*/	
	cout << "Enter the vertices among whom you want to find the path\n";
	cin >> i >> j;
	
	cout << "The path between " << i << " and " << j << " is\n";
	
	path( i-1 , j-1);  //array index = value - 1
	
	return 0;
}
