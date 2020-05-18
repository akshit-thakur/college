#include<stdio.h>
int main(){
	int i;
	int r[5]; 
	int m1[5];
	int m2[5];
	int t[5];
	int a[5];
	for(i=0;i<5;i++){
		printf("Enter roll number: ");
		scanf("%d",&r[i]);
		printf("Enter marks of 2 subjects:\n");
		scanf("%d%d",&m1[i],&m2[i]);
		t[i]=m1[i]+m2[i];
		a[i]=t[i]/2;
	}
	printf("R num\tMarls 1\tMarks 2\tTotal\tAverage\n");
	for(i=0;i<5;i++)
		printf("%d    \t %d \t  %d   \t %d \t   %d\n",r[i],m1[i],m2[i],t[i],a[i]);
	return 0;
}
//23/10/17