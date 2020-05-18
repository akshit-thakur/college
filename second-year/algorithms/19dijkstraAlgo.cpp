/*
0 -1 -1 -1 3 4 -1
-1 0 8 -1 -1 9 -1
-1 -1 0 -1 -1 -1 -1
-1 -1 7 0 -1 -1 -1
-1 -1 -1 -1 0 -1 -1
-1 -1 6 -1 -1 0 2
-1 -1 -1 5 10 -1 0
*/
/*
0	9	4	5	-1	-1
9	0	-1	7	-1	2 
4	-1	0	-1	-1	2 
5	7	-1	0	4	-1
-1  -1	-1	4	0	6
-1	2	2	-1	6	0
*/

#include<iostream>
#define INFY 12345
using namespace std;

int** cost; /**cost matrix containing all the weights of edges from i to j*/

int* dist; /*stores the minimum distance from a given source to the vertex*/

int** path; /*stores the path along which the minimum distance from source is obtained*/

//chooses the index of the smallest unvisited vertex(by distance) from v
int choose(bool flag[],int n){
	int i = 0;
	while( flag[i] == true){ //finds first unvisited
		i++;
	}
	
	int small = i; //index of the smallest unvisited vertex in the dist array
	
	for(int j=0;j<n;j++){ //search the entire vertices
	
		if(flag[j] == true) //if vertex is already visited,skip
		continue;
		
		else if(small != j){ //taking care of repetition
		
			if(dist[small] > dist[j]) //updates the index of unvisited vertex to the smallest value in dist array
			small = j;
			
		}
	}
	
	return small;
	
}

void dijkastra(int v,int n){
	
	int i, j , w = 0, u;

	//Array initialization
	bool flag[n] = {false};	//flag array contains info about whether the vertex is visi

	dist = new int[n];

	//Initialize the dist array taking dist[i] = cost[v,i] and add the edge from i -> v to the path from v to i
	for( i=0; i<n; i++){
		dist[i] = cost[v-1][i];
		path[i][v-1] = -1;
	}
	
	dist[v-1] = 0;
	flag[v-1] = true;
	
	for(i=1; i<n-1; i++){ 		//choose w such that flag[w]=false and dist[w] is minimum;
		w = choose(flag,n);
		flag[w] = true;
		for(u=0; flag[u] == false || u<n; u++){ //all neighbours u of w such that flag[u]=false
			if(dist[u] > dist[w] + cost[w][u]){ //if distance through w (i.e. v -> w -> u) is less than that of path between u and v ( v -> u )
				dist[u] = dist[w] + cost[w][u];
				path[u][w] = 1; //the edge from w to u exists in the minimum distance graph/tree
				for(j=0; j<w; j++){ //check for preceding vertices
					if(path[w][j] == 1) //if a path exists between j and w ( from j to w)
					path[u][j]=1; //then a path exists from j to u as it is the smallest
				}
			}
		}
	}
	
	/*print results*/
	cout<<"The distances from "<<v<<" are:(12345 means infinity)\n";
	for(i=0;i<n;i++)
		cout << i+1 << ": " << dist[i] << "\n";
	cout<<"Path matrix:\n";
	for(i = 0 ;i < n; i++){
		for(j = 0; j<n; j++)
		cout << path[i][j] << " ";
		cout << "\n";
	}
	for(i=0; i<n; i++){
		cout << "The extra vertices in path from " << v << " to " << i+1 << " is: ";
		for(j=0; j<n; j++){
			if(path[i][j] == 1 && dist[i]!=INFY)
			cout<<j+1<<" ";
			else if(dist[i] == INFY){ cout << "None."; break; }
		}
		cout << "\n";
	}
}
int main (){
	int n,v,i,j; //n-> number of vertices v->the vertex from which min dist is to be calculated i,j->loop counters
	
	/*Take input*/
	cout << "Enter number of vertices: ";
	cin >> n;
	
	//array initializations
	cost = new int*[n];
	path = new int*[n];
	for(i=0; i<n; i++){
		cost[i] = new int[n];
		path[i] = new int[n];	
	}
	
	//fill the cost matrix
	cout << "Enter the cost matrix(negative value for no edge):\n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>cost[i][j];
			if(cost[i][j]<0)
			cost[i][j]=INFY;		
		}
	}
	//get the source vertex
	cout<<"Enter the vertex from which you want to find shortest distances: ";
	cin>>v;
	
	//do dijkastra
	dijkastra(v,n);
	
	return 0;
}
