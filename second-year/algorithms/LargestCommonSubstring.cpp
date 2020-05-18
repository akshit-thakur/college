#include<iostream>
#include<limits>
using namespace std;

char x[100]; 
char y[100];

int** f; //the lenth of longest substring is stored in this 
int** p; //the path in f to trace the characters in the longest substring

void printLCS(int i , int j){
	if( (i == 0) || (j == 0) )
	return;
	
	if( p[i][j] == 3){
		printLCS( i-1, j-1);
		cout << x[i-1] ;
	}
	else if( p[i][j] == 2 )	
		printLCS( i-1, j);
	else
		printLCS( i, j-1 );
}
int main(){
	int m=0,n=0; //lengths of 2 strings
	int i,j; //loop counters
	/*Take input*/
	
	cout << "Enter first sequence ";
	cin.get(x,100);
	
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	cout << "Enter second sequence ";
	cin.get	(y,100);

	//intialize the lengths of x and y into m and n
	for( i = 0; x[i] != '\0'; i++ )
	m += 1;
	
	for( i = 0; y[i] != '\0'; i++ )
	n += 1;
	
	//array initialization
	f = new int*[m+1];
	
	p = new int*[m+1]; /*max path is along the edges finding no diagonal path. n ups and m rights. */
	
	for( i = 0 ; i < m+1 ; i++ ){
		f[i] = new int[n+1];
		p[i] = new int[n+1];
	}
	
	for( i = 1 ; i < m+1 ; i++ ){
		for ( j = 1 ; j < n+1 ; j++ ){ //diagonal
			if( x[i] == y[j] ){
				f[i][j] = f[i-1][j-1] +	1;
				p[i][j] = 3;
			}
			else if( f[i-1][j] >= f[i][j-1] ){ //upward
				f[i][j] = f[ i-1 ][j];
				p[i][j] = 2;
			}	
			else{ //sideward
				f[i][j] = f[i][ j-1 ];
				p[i][j] = 1;
			}
		}
	}
	
	/*cout << "The Solution matrix\n";
	
	for( i = 0 ; i < m+1 ; i ++ ){
		for( j = 0; j < n+1 ; j++)
			cout << f[i][j] << " ";
		cout << "\n";
	}
	
	cout << "\nThe Path matrix\n";
	
	for( i = 0 ; i < m+1 ; i ++ ){
		for( j = 0; j < n+1 ; j++)
			cout << p[i][j] << " ";
		cout << "\n";
	}*/
	
	cout <<	 "The common subsequence is: \n";
	printLCS(m,n);
	cout<<"\n";
	return 0;
}
