#include<stdio.h>
int add(int,int);
int main(){
    int a,b;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    int sum=add(a,b);
    printf("Their sum is: %d\n",sum);
	return 0;
}
int add(int x,int y){
    return x+y;
}