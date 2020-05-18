/*
0   3	1	5	9	-1	-1	-1	-1	-1	-1
-1	0	-1	-1 	-1	1	2	-1	-1	-1	-1
-1	-1	0	-1	-1	2	-1	-1	-1	-1	-1	
-1	-1	-1	0	-1	-1	4	-1	-1	-1	-1
-1	-1	-1	-1	0	-1	-1	6 	-1	-1	-1
-1	-1	-1	-1	-1	0	-1	-1	8	-1	-1	
-1	-1	-1	-1	-1	-1	0	-1	4	9	-1	
-1	-1	-1	-1	-1	-1	-1	0	-1	6	-1
-1	-1	-1	-1	-1	-1	-1	-1	0	-1	3
-1	-1	-1	-1	-1	-1	-1	-1	-1	0	4 
-1	-1	-1	-1	-1	-1	-1	-1	-1	-1	0

No of stages = 5
Cost = 13
Path = 1 2 7 9 11

0	1       2	5	-1	-1	-1	-1	
-1	0	-1	-1	4	11	-1	-1	
-1	-1	0	-1	9	5	16	-1
-1	-1	-1	0	-1	-1	2	-1
-1	-1	-1	-1	0	-1	-1	18
-1	-1	-1	-1	-1	0	-1	13
-1	-1	-1	-1	-1	-1	0	2
-1	-1	-1	-1	-1	-1	-1	0

No of stages = 4
Cost = 7
Path = 1 4 7 8

*/

#include<iostream>
#include<limits.h>
using namespace std;

int** cost; //the adjacency matrix
int* stage; //the stage of each vertex
int* dist; //the final answer
int* path; //final answer path

int findStages(int n){
	int k = 1;
	
	for( int i = 0; i < n; i++){
		k = stage[i];
		for( int j = 0; j < n; j++){ 
			
			if( cost[i][j] == INT_MAX )
			continue;
			
			stage[j] = k+1;
		
		}
	}
	return k;
}

int findMin(int p,int k,int n){
	int j,x,y,r=0;
	
	//cout << "Searching first node:\n";
	
	//linear search the first vertex of next stage
	for( j = p-1; j >=0; j-- ){
		//cout << j << " " << stage[j] << "..\n";
		
		if( stage[j] == k-1 )
			break;
	
	}
	x = j;
	
	// cout << "Searching last node:\n";
	//linear search the last vertex of next stage
	for( ; j >= 0; j--){
		//cout << j << " " << stage[j] << "..\n";
		if( stage[j] == k-2 )
			break;
	}
	y = j+1;
	
	
	cout << "For p : " << p <<" k : " << k << " ,we have ";
	cout << "x : " << x << " , stage[x] : " << stage[x] <<" y : " << y << " , stage[y] : " << stage[y] << "\n";
	
	int min = dist[p];
	if( min == 0 )
	min = INT_MAX;
	
	for( j = y; j <= x; j++){
		//cout << cost[j][p] << " is the cost of edge from  " << j+1 <<" to " << p+1 <<"\n";
		//cout << min << "is the min\n";
		//cout << dist[j] << "is distance of j from n\n";
		if( cost[j][p] == INT_MAX ) //if edge doesn't exist,continue
			continue;
		if( cost[j][p] + dist[j] < min){ //if new distance is less than original distance, distance is updated
			r = j;
			min = cost[j][p] + dist[j];
		}
	}
	
	cout << r << " is returned.\n";
	return r;
}

void fGraph(int k,int n){
	int r;
	int* d = new int[n-1]; //some temporary array in use for finding min cost path
	//compute dist[j]
	for( int j = n-1; j >0; j--){
		if( stage[j] == k-1)
		k -= 1;
		r = findMin(j,k,n);
		dist[j] = cost[j][r] + dist[r];
		d[j] = r;
	}
	//find a minimum cost path
	path[0] = 0;
	path[n-1] = n-1;
	
	/*cout << "d array:\n";
	for( int j=0; j < n ; j++)
		cout << d[j] << " ";
	cout << "\n";	
	*/
	
	/*
	for( int i = 1; i < n-1; i++ ){
		path[i] = d[path[i-1]];
		cout << i << " " << path[i] << "\n";	
	}
	*/
}

int main(){
	int n; //no. of vertices in the graph
	int i,j; //loop counters
	int k; //no of stages
	
	
	/*Take input*/
	cout << "Enter the number of vertices\n";
	cin >> n;
	
	//Array initialization
	
	cost = new int*[n];
	dist = new int[n];
	stage = new int[n];
	
	for( i = 0 ; i < n ; i++){
		cost[i] = new int[n];
		stage[i] = 1; 	//by default,all vertices are in first stage of graph
	}
	
	//fill up adjacency matrix
	cout << "Enter the adjacency matrix ( -1 for no edge )\n";
	
	for( i = 0 ; i < n ; i++){
		for( j = 0 ; j < n ; j++){
			cin >> cost[i][j];
			if( cost[i][j] <= 0 )
			cost[i][j] = INT_MAX;
		}
	}
	
	k = findStages(n);

	cout << "Number of stages : " << k << "\n";	
	
	/*
	cout << "Stage array:\n";
	
	for( i = 0; i<n ; i++ )
		cout << stage[i]<<" ";
	cout << "\n";
	*/
	
	path = new int [k] ;
	
	fGraph(k,n);
	
	cout << "The final graph cost is: " << dist[n-1] << "\n";
	
	cout << "The path is:\n";
	for( i = 0 ; i < k ; i++ )
		cout << path[i]+1 << " ";
	cout << "\n";

	return 0;
}
