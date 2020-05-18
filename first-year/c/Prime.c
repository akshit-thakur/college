#include<stdio.h>
int main(){	
	int n,i;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=2;i<n;i++){
		if(n%i==0)
		break;	
	}
	if(i==n)
	printf("%d is prime.\n",n);
	else
	printf("%d is not prime.\n",n);
	return 0;
}
// 18/9/17
