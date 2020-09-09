%{ 
#include<stdio.h> 
int flag=0; 
extern int yylval;
%} 

%token zero one

%left '+' '-'

%left '*' '/' '%'

%left '(' ')'

/* Rule Section */
%% 
N: L {printf("\nThe decimal is: %d\n", $$);} 
L: L B {$$=$1*2+$2;}
| B {$$=$1;} 
B:zero {$$=$1;} 
|one {$$=$1;}; 
%% 

void main() 
{ 
	printf("\nEnter binary to convert to decimal:\n"); 
	while(yyparse());
} 

void yyerror() 
{ 
	printf("\nError\n\n"); 
	flag=1; 
}
