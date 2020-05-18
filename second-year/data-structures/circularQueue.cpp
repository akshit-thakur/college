/**
5. Insertion and Deletion from Circular Queue
*/
#include<iostream>
using namespace std;
#define INFY -123456;
class Queue{
	int front;
	int rear;
	int qLength;
	int* queue;
	public:
	Queue(){
		front = -1;
		rear = -1;
		qLength = 0;
        queue = new int[0];
	}
    Queue(int size){
		front = 0;
		rear = 0;
		qLength = size;
		queue = new int[size];
	}
	void insert(int);
	void del();
	void traverse();
	bool hasEmpty(int); //0 for single check,1 to check if all other are empty
};

void Queue::insert(int item){
	if( (front == 0 && rear == qLength) || (front == rear+1&&!hasEmpty(0)) ) //queue full
		cout<<"Queue full!\n";
	else{		
		if(rear == qLength && front!=0){
			rear = 0;
			queue[rear] = item;
			rear+=1;
			cout<<item<<" was inserted.\n\n";
		}
		else if(front == -1 && rear == -1){
			front = 0;
			rear = 0;
			queue[rear] = item;
			rear+=1;
			cout<<item<<" was inserted.\n\n";
		}
		else{
			queue[rear] = item;
			rear+=1;
			cout<<item<<" was inserted.\n\n";
		}
	}
}

void Queue::del(){
	if( front == -1 )
	cout<<"Underflow\n";
	else{
		int item = queue[front];
		if( hasEmpty(1) ){ //queue has only one element
			queue[front] = INFY;			
			front = -1;
			rear = -1;
		}		
		else if( front == qLength-1 ){
			queue[front] = INFY;
			front = 0;		
		}
		else{
			queue[front] = INFY;
			front +=1;		
		}
		cout<<item<<" deleted from queue.\n";
	}
}

void Queue::traverse(){
	int i;
	cout<<rear<<"  "<<front<<"\n\n";
	if( front == -1 ){
		cout<<"Queue empty\n";
		cout<<"The queue is:\n";
		for(i = 0; i<qLength;i++)
		cout<<queue[i]<<" ";
		cout<<"\n";
	}
	else if(rear <= front ){
			cout<<"The queue is:\n";
			for(i = front; i<qLength;i++)
			cout<<queue[i]<<" ";
			for(i = 0; i<rear; i++)
			cout<<queue[i]<<" ";
			cout<<"\n";
	}
	else{ // rear > front
		cout<<"The queue is:\n";
		for(i = 0; i<qLength;i++){
			if( queue[i] != -123456)
			cout<<queue[i]<<" ";
		}
		cout<<"\n";	
	}
}

bool Queue::hasEmpty(int choice){
	int count = 0;
	for(int i = 0;i <qLength; i++){
		if(queue[i] == -123456)
		count++;
	}	
	if(choice == 0 && count>0)
		return true;
	else if(choice == 1 && count == qLength-1)
		return true;
	else
		return false;
}

int main(){
	int choice,item,size;
	cout<<"Enter the max length of queue.\n";
	cin>>size;
	Queue* q = new Queue(size);
	do{
		cout<<"1. Insert\n2. Delete\n3. Traverse\n4. Exit\n";
		cout<<"Enter your choice: \n";
		cin>>choice;
		switch(choice){
			case 1: 
				cout<<"Enter the value to insert: ";
				cin>>item;
				q->insert(item);				
				break;
			case 2:
				q->del();
				break;
			case 3:
				q->traverse();
				break;
		}
	}while(choice!=4);
	return 0;
}
