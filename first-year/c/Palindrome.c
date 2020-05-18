#include<stdio.h>
int main(){
	int n,rev=0,temp,d;
	printf("Enter a number: ");
	scanf("%d",&n);
	temp=n;
	while(n>0){
		d=n%10;
		rev=(rev*10)+d;
		n/=10;
	}
	if(temp==rev)
	printf("Palindrome.\n");
	else
	printf("Not a palindrome.\n");
	return 0;
}
// 18-09-2017
