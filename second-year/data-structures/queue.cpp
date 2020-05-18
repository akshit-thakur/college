	/**
	4. Insertion and Deletion from Queue
	*/
	#include<iostream>
	using namespace std;
	struct qNode{
		int info;
		qNode* next;
	};

	qNode* qStart=NULL;

	void insert(int item){
		if(qStart==NULL){
			qNode* n=new qNode;
			n->info=item;
			n->next=qStart;
			qStart=n;
		}
		else{
			qNode* n=new qNode;
			qNode* ptr=qStart;
			n->info=item;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=n;
			n->next=NULL;			
		}
	}

	void remove(){
		if(qStart==NULL)
		return;
		else{
			qNode* ptr=qStart;
			qStart=ptr->next;
			delete ptr;				
		}
	}

	void traverse(){
		qNode* ptr=qStart;
		while(ptr!=NULL){
			cout<<ptr->info<<" ";
			ptr=ptr->next;
		}
		cout<<"\n";
	}

	int main(){
		int choice,item;
		do{
			cout<<"1.Insert\n2.Delete\n3.Traverse\n4.Exit\nEnter choice: ";
			cin>>choice;
			switch(choice){
				case 1:
					cout<<"Enter item to insert: ";
					cin>>item;
					insert(item);
					cout<<"Inserted\n";
					break;
				case 2:
					remove();
					cout<<"Deleted\n";
					break;
				case 3:
					traverse();
					break;		
			}
		}while(choice!=4);
		return 0;
	}
