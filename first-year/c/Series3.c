#include<stdio.h>
int main(){
	float n,nmr,sum=0,fact=1,i,j;
	printf("Enter number of terms:\n");
	scanf("%f",&n);
	for(i=1;i<=n;i++){
			for(j=2;j<=i;j++)
			fact*=j;
		sum+=(i/fact);
		fact=1.0;
	}
	printf("Sum of (1/1!)+...+(n/n!) is %f\n",sum);
	return 0;
}
