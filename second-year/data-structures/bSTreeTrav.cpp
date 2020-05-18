/**
11. Implement recursive traversal of tree
COMPLETED
*/
#include<iostream>
using namespace std;

struct Node{
	int info;
	Node* left;
	Node* right;
};

Node* root=NULL; //root of tree

Node* insert(Node* &n,int item){
	if(n==NULL){
		n=new Node;
		n->info=item;
		n->left=NULL;
		n->right=NULL;
	}
	else{
		if(item<=n->info)
		insert(n->left,item);
		else
		insert(n->right,item);
	}
}

void getTree(){
	insert(root,25);
	insert(root,7);
	insert(root,11);
	insert(root,89);
	insert(root,19);
	insert(root,29);
	insert(root,46);
	insert(root,31);
	insert(root,5);
	insert(root,24);
}
void intrav(Node* p){
	if(p!=NULL){
		intrav(p->left);
		cout<< p->info<<" ";
		intrav(p->right);
	}
}

void pretrav(Node* p){
	if(p!=NULL){
		cout<< p->info<<" ";		
		pretrav(p->left);
		pretrav(p->right);
	}
}

void posttrav(Node* p){
	if(p!=NULL){
		posttrav(p->left);
		posttrav(p->right);		
		cout<< p->info<<" ";
		
	}
}

int main(){
	getTree();
	cout<<"\nInorder traversal\n";
	intrav(root);
	cout<<"\nPreorder traversal\n";
	pretrav(root);
	cout<<"\nPostorder traversal\n";
	posttrav(root);
	cout<<"\n";
}
