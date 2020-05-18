#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
	int x,n;
	float sum=0,fact=1;
	clrscr();
	printf("Enter x and number of terms:\n");
	scanf("%d%d",&x,&n);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=i;j++)
			fact*=j;
		sum+=(pow(x,i)/fact);
		fact=1;
	}
	printf("Sum of (x/1!)+(x^2/2!)+....+(x^%d/%d!) is %f",n,n,sum);
	getch();
	return 0;
}
// 18/9/2017