#include<stdio.h>
int main(){
	int n,sum=0,fact=1,i,j;
	printf("Enter number of terms: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=2;j<=i;j++)
			fact*=j;
		sum+=fact;
		fact=1;	
	}
	printf("The sum of series 1!+2!+...+%d! is %d\n",n,sum);
	return 0;
}
// 18/9/17
