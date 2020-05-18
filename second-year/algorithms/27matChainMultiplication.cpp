// 2 3 2 4 3 2 3 = 68
// 30	35	15	5	10	20	25 = 15,125
#define INFY 12345678
#include<iostream>
#include<limits>
using namespace std;

int* p; //order of A(i) = p(i-1)*p(i) [ n+1 entries ]

int** m; //contains the cost of least multiplication for A(i) to A(j)

int** s; //contains k such that A(i) to A(j) breaks at k

void print(int i,int j){
	if( i == j )
	cout << " A" << i+1 << " " ;
	else{
		cout << " ( ";
		print ( i , s[i][j] );
		print (s[i][j] + 1, j );
		cout << " ) ";
	}
}
int main (){
	int n; //Number of matrices
	int i,j,k,l; //loop counters
	
	/*Take input*/	
	cout<<"Enter number of matrices:\n";
	cin>>n;
	
	//Array initialization
	p = new int[n+1];

	m = new int*[n];
	s = new int*[n-1];

	for( i = 0; i < n; i++){
		m[i] = new int[n];
		s[i] = new int[n-1];
	}
	
	//fill up p
	cout<<"Enter the orders of the matrices:\n";
	for( i = 0; i < n+1; i++ )
		cin >> p[i];
		
	 for( i = 0; i < n; i++)
			s[i][i] = i;	

	 for (i=1; i<n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (l=2; l<n; l++) { 
        for (i=1; i<n-l+1; i++) { 
            j = i+l-1; 
            m[i][j] = INT_MAX; 
            for (k=i; k<=j-1; k++) 
            { 
                // q = cost/scalar multiplications 
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) {
                    m[i][j] = q; 
                    s[i][j] = k; 
        	    } 
        	} 
    	} 
	}

	/*
	//find number of scalar multiplications
	for( l = 2; l <= n; l++ ){
		for( i = 0; i < n-l+1; i++ ){
			j = i+l-1;
			m[i][j] = INFY;
			for( k = i; k <= j-1; k++){
				int q;
				if( i != 0 )
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				else
				q = m[i][k] + m[k+1][j] + p[0]*p[k]*p[j];
				
				if( q < m[i][j] ){
					s[i][j] = k;
					m[i][j] = q;
					cout << " i : " << i << "  j : " << j << " k : " << k << " q : " << q <<"\n";
				}
				
			}
		}
	}
	*/
	cout << "The multiplication matrix\n";
	for( i = 0; i < n; i++){
		for( k = 0 ; k < i ; k++ )
		cout << "\t";
		for( j = i; j < n; j++)
			cout << m[i][j] << "\t";
		cout << "\n";
	}
	
	cout << "The path matrix\n";
	for( i = 0; i < n; i++){
		for( k = 0 ; k < i ; k++ )
		cout << "\t";
		for( j = i; j < n-1; j++)
			cout << s[i][j] << "\t";
		cout << "\n";
	}
	
	cout <<	"Number of multiplications \n";
	cout << m[1][n-1] <<"\n";

	cout << "Order of multiplications \n";
	//print(0,n-1); 

	cout << "\n";	
	return 0;
}
