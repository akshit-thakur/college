%{ 
#include<stdio.h> 
int flag=0; 
extern int yylval;
%} 

%token NUMBER 

%left '+' '-'

%left '*' '/' '%'

%left '(' ')'

/* Rule Section */
%% 

ArithmeticExpression: E{ 

		printf("\nResult is: %d\n", $$); 

		return 0; 

		}; 
E:E'+'E {$$=$1+$3;} 

|E'-'E {$$=$1-$3;} 

|E'*'E {$$=$1*$3;} 

|E'/'E {$$=$1/$3;} 

|E'%'E {$$=$1%$3;} 

|'('E')' {$$=$2;} 

| NUMBER {$$=$1;} 

; 

%% 

void main() 
{ 
	printf("\nEnter arithmetic expression to be evaluated:\n"); 
	yyparse();
} 

void yyerror() 
{ 
	printf("\nError\n\n"); 
	flag=1; 
}
