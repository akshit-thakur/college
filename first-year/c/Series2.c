//error - pow not found
#include<stdio.h>
#include<math.h>
int main(){
	int x,n,nmr,sum=0,fact=1,i,j;
	printf("Enter x & number of terms:\n");
	scanf("%d%d",&x,&n);
	for(i=1;i<=n;i++){
			for(j=2;j<=i;j++)
			fact*=j;
		nmr=pow(x,i);
		sum+=(nmr/fact);
		fact=1;
	}
	printf("Sum of (x/1!)+...+(x^%d/%d!) is %d",n,n,sum);
	return 0;
}
