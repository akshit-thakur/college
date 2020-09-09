%{ 
	#include <stdio.h> 
	#include <stdlib.h> 
	#include "y.tab.h" 
%}
%% 

[01]+ {yylval.f = yytext; return STR;} 
[-+()*/] {return yytext[0];} 
[ \t\n]	 {;} 

%% 

int yywrap() 
{ 
return -1; 
}
