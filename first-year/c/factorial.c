#include<stdio.h>
int fact(int);
int factorial(int*);
int factRec(int);
int main(){
	int n,*j;
	j=&n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Factorial using call by value: %d\n",fact(n));
	printf("Factorial using call by reference: %d\n",factorial(&n));
	printf("Factorial using recursion: %d\n",factRec(n));
	return 0;
}
int fact(int x){
	int i,fact=1;
	for(i=2;i<=x;i++)
		fact*=i;
	return fact;
}
int factorial(int *j){
	int i,fact=1;
	for(i=2;i<=*j;i++)
		fact*=i;
	return fact;
}
int factRec(int p){
	if(p==0||p==1)
		return 1;
	else
		return p*factRec(p-1);
}
