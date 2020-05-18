#include <stdio.h>
int digit(char);
int main () {
char card[] ="4567123456789129"; int so=0,se=0,i,n;
printf("Enter a card number:") ;

for (i=0;i<16;i++){
	n=digit(card[i]);
	if(i%2==0){
		n*=2;
		if(n>9) n-=9;
		so+=n;
	} 
	else se+=n;
} 
if((so+se)%10==0) printf("\nValid card number.");
else printf("\nInvalid Card number.");
} 
int digit(char ch) {
    if (ch>=48&&ch<=57)
	return ch-48;
	else 
	return -1;
}
