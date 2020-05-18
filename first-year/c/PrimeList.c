#include<stdio.h>
int main(){	
	int i,j,flag=0;
	printf("The prime numbers between 2 and 100 are: \n");
	for(i=2;i<=100;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				flag=1;	
				break;	
			}
		}
		if(flag==0)
		printf("%d ",i);
		flag=0;
	}
	return 0;
}
// 18/9/17