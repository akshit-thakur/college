#include<stdio.h>
int main(){
	int i,n=1;
	printf("The even numbers between 1 and 100 are:\n");
	while(n<=100){
		if(n%2==0)
		printf("%d ",n);
		n++;
	}
	printf("\nThe odd numbers between 1 and 100 are:\n");
	for(i=1;i<=100;i++){
		if(i%2!=0)
		printf("%d ",i);	
	}
	printf("\n\n");
	return 0;
}
// 11-09-2017
