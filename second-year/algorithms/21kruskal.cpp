/*
0	3	5	-1	-1	-1
3	0	-1	5	7	-1
5	-1	0	-1	6	9
-1	5	-1	0	8	-1
-1	7	6	8	0	10
-1	-1	9	-1	10	0
*/

/*
0	4	-1	-1	-1	-1	-1	8	-1
4	0	8	-1	-1	-1	-1	11	-1
-1	8	0	7	-1	4	-1	-1	2
-1	-1	7	0	9	14	-1	-1 	-1
-1	-1	-1	9	0	10	-1	-1	-1	
-1	-1	4	14	10	0	2	-1	-1
-1	-1	-1	-1	-1	2	0	1	6
8	11	-1	-1	-1	-1	1	0	7
-1	-1	2	-1	-1	-1	6	7	0
*/


#define INFY 12345
#include<iostream>
using namespace std;

int** cost; /*stores all the weights/cost of edges in a given graph 
			i.e. cost[i][j] = w if there is an edge of weight w between vertices i and j*/

int** E; /**heap storing the edges' weight and vertices. 
			E => weight source destination
			Max no. of edges = n*(n-1)
			E -> weight source destination*/
			
int* parent; /*parent array which stores the parent of a vertex in a solution subset 
			   i.e. if parent[i] = j then set contains {i,j} */
		   
int** soln; /* Solution contains the source and destination vertices in MST.
	      	   Dimensions: (n-1)*2
			   soln[][0]= source
			   soln[][1] = destination
			*/

void heapify(int i,int n){
	int left = 2*i ; /*left child of node i*/
	int right = 2*i + 1 ; /*right child of node i*/
	int largest = i ; /*the index of largest of the parent or the children*/
	
	if( left < n && E [left][0] > E [i][0] ) //if the left child is larger
		largest = left;

	if( right < n && E [right][0] > E [largest][0] ) //if right child is largest
		largest = right;

	if( largest != i ){ //if the parent isn't the largest
		for(int k = 0; k < 3; k++)
			swap( E[i][k],E[largest][k] );
		heapify( largest , n );
	}
}

void buildheap( int n ){ /*builds the initial heap of edges*/
	for( int i = (n/2) ; i>0; i--) 
		heapify( i-1 , n ); // array index  = value - 1
}

void heapsort( int n ){
	for( int i = n-1 ; i >= 1; i--){ 
		for( int k = 0; k < 3; k++)
			swap( E[0][k],E[i][k] ); //swaps the last element with root
		n -= 1; //another element sorted
		heapify( 0 , n ); //heapifies the root
	}
}

int find(int i){ //finds the parent node of i
	while(parent[i] >= 0 ){
		i = parent[i];
	}
	return i;
}

void unite(int i,int j){ //makes j the parent of i
	parent[i] = j;
}

bool heapEmpty(int n){ //checks if edge heap is empty
	return n==0;
}

bool duplicate(int i,int j,int n){ //checks for duplicates prevelant in unweighted graph
	for(int x=0; x<n; x++){ 
		if( E[x][1] == j && E[x][2] == i) //if Source(any previous edge)=Destination(current edge) & vice versa
		return true; //duplicate exists
	}
	return false;
}

int main (){
	int n; /*Number of vertices*/
	int i,j; /*loop variables*/
	int k = 0; /*k is the index variable for E*/
	int mincost = 0; /*total cost of all edges in MST*/ 
	
	/*Take input*/
	cout << "How many vertices? ";
	cin >> n;

	//initialize arrays
	E = new int*[n*(n-1)];
	
	for(i=0 ; i<(n*(n-1)); i++)
	E[i] = new int[3]; //number of edges from one vertex = n-1 and there are n vertices
	
	cost = new int*[n];
	
	for(i=0; i<n; i++)
	cost[i] = new int[n]; 
	
	parent = new int[n];
	for(i=0; i<n; i++) 
	parent[i] = -1; //initially, all nodes belong to different sets
	
	soln = new int*[n-1];

	for( i=0; i< n-1; i++)
	soln[i]=new int[2]; //soln is [n-1]*[2] matrix 
		
	//fill up cost matrix
	cout<<"Enter the adjacency matrix(negative for no edge)\n";
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin >> cost[i][j];
			
			if(cost[i][j] < 0)
			cost[i][j] = INFY;

			if(i!=j){
				if(!duplicate(i+1,j+1,k) && cost[i][j] != INFY ){ //checks for double entries.
				
					E[k][0] = cost[i][j];
					E[k][1] = i+1; //source
					E[k][2] = j+1; //destination
					
					k += 1; //0<k<n*(n-1)
				}
			}
		}
	}
	
	buildheap(k);
	
	heapsort(k);
	
	i=0; // i is now the count for solution matrix
	
	int u,v; //source and destination of smallest edge(on top of heap)
	int x,y; //parents of u,v respectively(if they exist)
	
	while( (i <	n-1) && !(heapEmpty(k)) ){

		//get the source and destination of smallest edge
		u = E[0][1] - 1; 
		v = E[0][2] - 1;
		
		//sort the remaining k-1 edges.
		k -= 1;
		
		heapsort(k);
		
		//find the parents(root node) of u and v
		x = find(u);
		y = find(v);

		//if u and v don't belong to same set, their root nodes will be different
		if( x!=y ){
			//add u and v to solution
			soln[i][0] = u+1;
			soln[i][1] = v+1;
			
			//add their cost to that of MST
			mincost += cost[u][v];
			
			//increment counter
			i += 1;
			
			//make x the child of y
			unite( x,y );
		}
		
		else if ( x==-1 || y==-1){
			/*Special case when one or both the vertices belong to single value set i.e. number of elements in that set = 1*/
			soln[i][0] = u+1;
			soln[i][1] = v+1;
			
			mincost += cost[u][v];
			
			i += 1;
			//if both are belonging to different sets,we just unite the children which are roots of their respective trees
			if( x == -1 && y == -1 ) 
			unite(u,v);
			
			//else check which vertex belongs to single set and unite its child with the other parent(root) node
			else if( x == -1 ) 
			unite(u,y);
			
			else		
			unite(x,v);
			
		}
	}
	
	if( i != n-1 )
	cout << "No spanning tree formed\n";

	else{
		cout << "\nThe spanning tree has minimum cost : " << mincost << "\n";
		cout << "\nThe MST has edges\n";
		for(i=0; i < n-1; i++)
			cout << soln[i][0] << " -> " << soln[i][1] << "\n";
	}

	return 0;

}
