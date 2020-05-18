#include <stdio.h>
void shift(int*, int*, int*);
int main(){
	int x=5,y=8,z=10;
	shift (&x, &y, &z);
	printf ("%d %d %d",x,y,z);
}
void shift (int *x, int *y, int *z){
	int temp=*x;
	*x=*z;
	*z=*y;
	*y=temp;
}