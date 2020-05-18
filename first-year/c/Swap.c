#include<stdio.h>
int main(){
	int a,b;
	printf("Enter numbers: ");
	scanf("%d%d",&a,&b);
	printf("Before swap, first number: %d and second: %d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swap, first number: %d and second: %d\n",a,b);
	return 0;
}
//23/10/17