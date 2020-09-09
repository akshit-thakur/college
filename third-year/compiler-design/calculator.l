%{ 
/* Definition section */
#include<stdio.h> 
#include "y.tab.h" 
extern int yylval; 
%} 

%% 
[0-9]+ { 
		yylval=atoi(yytext); // convert string to number
		return NUMBER; // for numbers
	} 
[\t] return 0;

[\n] return 0; 

. {
    return yytext[0]; //for operators
}; 

%% 

int yywrap() 
{ 
return 1; 
}
