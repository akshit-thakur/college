/**
6. Insertion and Deletion from Linked List
COMPLETED
*/
#include<iostream>
using namespace std;
struct Node{
	int info;
	Node* link;
};

struct Node* start=NULL;

Node* getNode(){
	Node* p;
	p=new Node;
	return p;
}

void freeNode(Node* p){
	delete p;
}

void insertValue(int item){
	Node* loc;
	if(start==NULL)
		loc=NULL;
	else if(item<start->info)
		loc=NULL;
	else{
		Node* save=start;
		Node* ptr=start->link;
		while(ptr!=NULL){
			if(item<ptr->info){
				loc=save;
				break;	
			}
			save=ptr;
			ptr=ptr->link;	
		}
		loc=save;
	}
	struct Node* n=getNode();
	n->info=item;
	if(loc==NULL){
		n->link=start;
		start=n;
	}
	else{
		n->link=loc->link;
		loc->link=n;
	}
}
void deleteVal(int item,Node* &loc,Node* &locp){
	Node* save;
	Node* ptr;
	if(start==NULL){
		locp=NULL;
		loc=NULL;
	}
	else if(item==start->info){
		loc=start;
		locp=NULL;
	}
	else{
		save=start; 
		ptr=start->link;
		while(ptr!=NULL){
			if(ptr->info==item){
				loc=ptr;
				locp=save;
				break;
			}	
			save=ptr;
			ptr=ptr->link;
		}
		if(ptr==NULL)
			loc=NULL;
	}
}

void deleteNode(int item){
	struct Node* loc=NULL;
	struct Node* locp=NULL;
	deleteVal(item,loc,locp);
	if(loc==NULL)
		cout<<"Node not found\n";
	else if(locp==NULL)
		start=start->link;
	else
		locp->link=loc->link;
	if(loc!=NULL){
		freeNode(loc);
		cout<<"Node deleted\n";
	}
}

void traverse(){
	Node* ptr=start;
	while(ptr!=NULL){
		cout<<ptr->info<<" ";
		ptr=ptr->link;
	}
	cout<<"\n";
}

int main (){
	int choice,val;
	do{
		cout<<"Welcome to Linked List\n";
		cout<<"1. Insert Node \n2. Delete Node \n3. Traverse List \n4. Exit\n\nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1: 
				cout<<"Enter the value of node to be inserted\n";
				cin>>val;
				insertValue(val);
			break;
			case 2: 
				cout<<"Enter value of node to be deleted\n";
				cin>>val;
				deleteNode(val);
			break;
			case 3: 
				traverse();
			break;
		}
	}while (choice!=4);
	return 0;
}
