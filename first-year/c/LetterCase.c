#include<stdio.h>
int main(){
	printf("Enter a character: \n");
	char ch=getchar();
	if((ch>=65)&&(ch<=90)){
		printf("Uppercase Letter. \n");
		ch+=32;
		printf("%c\n",ch);	
	}
	else if((ch>=97)&&(ch<=122)){
		printf("Lowercase Letter. \n");
		ch-=32;
		printf("%c\n",ch);	
	}
	else
	printf("Not a letter.\n");
	return 0;
}
