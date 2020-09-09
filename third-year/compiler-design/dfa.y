%{ 
	#include <stdio.h> 
	#include <string.h> 
	#include <stdlib.h> 
	extern int yylex(); 
	
	void yyerror(char *msg); 
	int flag; 
	
	int i; 
	int k =0;	 
%} 

%union { 
	char* f; 
} 

%token <f> STR 
%type <f> E 

/* Rule Section */
%% 

S : E { 
		flag = 0; 
		k = strlen($1); 
		if ($1[0] != $1[k-1]) {
			printf("String is rejected\n");
		} 
		else {
			printf("String is accepted\n");
		}
	} 
; 

E : STR {$$ = $1;} 
; 

%% 

void yyerror(char *msg) 
{ 
	printf("ERROR\n");
	exit(1); 
} 

int main() 
{ 
	printf("Enter input string: \n");
	yyparse(); 
	return 0; 
}
