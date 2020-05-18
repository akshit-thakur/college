/**
2. To perform PUSH and POP operations on Stack
COMPLETED
*/
#include<iostream>
using namespace std;

class Stack{
	int top;
	int maxLength; //of stack	
	int* stack;
	public:
	Stack(int s){ //s is for size of stack
		top = 0;
		maxLength = s;
		stack=new int[maxLength];
	}
	void push(int);
	int pop();
	int isEmpty();
};

void Stack::push(int x){
	if(top==maxLength){
		cout<<"\nThe stack is full\n";
	}
	else{
		stack[top]=x;
		top += 1;
		cout<<"\nPushed\n";
	}
}

int Stack::pop(){
	if( isEmpty() ) {
		cout<<"Stack empty\n";
		return -1;
	}
	else{
		top -= 1;
		int temp=stack[top];
		return temp;
	}
}

int Stack::isEmpty(){
	return top==0;
}

int main (){
	int size,choice,item;
	cout<<"Enter the size of stack: ";
	cin>>size;
	Stack* stack=new Stack(size);
	do{
		cout<<"\n1. Push \n2. Pop \n3. Exit\n"; 
		cout<<"Enter your choice: ";	
		cin>>choice;
		switch(choice){
			case 1: 
			cout<<"Enter the number to be pushed ";
			cin>>item;
			stack->push(item);
				break;
			case 2: 
			cout<<"The number popped is: "<<stack->pop()<<"\n";
				break;
		}
	}while(choice!=3);
	return 0;
}
