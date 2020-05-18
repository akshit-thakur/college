/*
4	0	1    
1	1	2
3	2	3
2	3	4
16	4	5
9	5 	6
10	6	7
14	7	8
8 	8	9
7 	9 	10
*/
#include<iostream>
using namespace std;

int** heap; /** [n]*[3] heap*/

void heapify(int i , int n){
	
	int left = 2*i ;
	int right = 2*i + 1 ;
	int largest = i;
	
	if( left < n && heap [left][0] > heap [i][0] )
		largest = left;
			
	if( right < n && heap [right][0] > heap [largest][0] )
		largest = right;
		
	if( largest != i ){
		for(int k = 0; k < 3; k++)
			swap( heap[i][k],heap[largest][k] );
		heapify( largest , n);
	}
}

void buildheap(int n){
	for( int i = (n/2)-1 ; i>=0; i--)
		heapify( i , n );
}

void heapsort(int n){
	for( int i = n-1 ; i >= 1; i--){
		for( int k = 0; k < 3; k++)
			swap( heap[0][k],heap[i][k] );
		n -= 1;
		heapify( 0 , n );
	}
}

void show(int n){
	for( int j = 0; j < n; j++)
		cout << heap[j][0]<<" "<< heap[j][1] <<" "<< heap[j][2] <<"\n";
}

int main (){

	int n; /* size of the heap*/
	int i,j,k; /**loop counters*/
	
	/**Take input*/
	cout << "Enter the size of heap: ";
	cin >> n;

	//Array initialization
	heap = new int*[n];	
	for( i = 0; i < n; i++ )
		heap [ i ] = new int [ 3 ];
		
	//Fill up the heap
	cout <<	"Enter the "<<n<<"*3 heap:\n";
	for( i = 0; i < n; i++ ){
		for( j = 0; j < 3; j++ )
			cin >> heap[i][j];
	}
	
	//Apply heapsort
	buildheap(n);
	heapsort(n);
	
	cout << "After sorting, the heap is :\n";
	show(n);
	
	return 0;

}
