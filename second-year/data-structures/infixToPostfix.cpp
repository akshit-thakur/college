/**
3. To convert infix expression into postfix
*/
#include<iostream>
#include<string.h>
using namespace std;
char stack[100];
int top=0;
bool empty(){
	return top==0;
}
void push(char ch){
	stack[top]=ch;
	top+=1;
	cout<<"pushed\n";
}
char pop(){
	char ch=stack[top];
	top-=1;
	return ch;
}
bool op(char ch){
	switch(ch){
		case '+':
		case '-':
		case '*':
		case '/':
		case '^': return true;	
	}
	return false;
}
bool precedence(char ch){
	if(ch=='+'||ch=='-'){
		if(!op(stack[top]))
		return false;
		return true; //all possible operator are >= + -	
	}
	else if(ch=='*'||ch=='/'){
		if(stack[top]=='+'||stack[top]=='-'||!op(stack[top]))
		return false;
		else
		return true;	
	}
	else if(stack[top]=='^'&&ch=='^')
	return true;
	else
	return false;
}
int main (){
	stack[top]='(';
	top+=1;
	int i=0,ctr=0;
	char* q;
	q=(char*)"A+(B*C–(D/E^F)*G)*H";
	int len=strlen(q);
	char* p=new char[len+1];
	i=0;
	while(!empty()){
		char ch=q[i];
		cout<<ch<<"\n";
		if(ch=='(')
		push(ch);
		else if(!op(ch))	//if not operator
		p[ctr++]=ch;
		else if(op(ch)){ //if character encountered is operator
			while(precedence(ch))
			p[ctr++]=pop();
			cout<<"here";
			p+=ch;
		}
		else{ //')' is encountered
			while(stack[top]!='(')
			p+=pop();
			pop();
		}
		i+=1;
		cout<<p<<".......\n\n";
	}
	cout<<q<<"\n"<<p<<"\n";
	return 0;
}
