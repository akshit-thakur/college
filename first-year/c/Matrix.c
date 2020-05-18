#include<stdio.h>
void disp(int[3][3]);
int main(){
	int i,j,a[3][3],b[3][3],s[3][3];
	printf("Enter first matrix: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		scanf("%d",&a[i][j]);
	}
	printf("Enter second matrix: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		scanf("%d",&b[i][j]);
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		s[i][j]=a[i][j]+b[i][j];
	}
	printf("First Matrix:\n");
	disp(a);	
	printf("Second Matrix:\n");
	disp(b);
	printf("Sum Matrix:\n");
	disp(s);	
	return 0;
}
void disp(int a[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n");	
}
