/**
9. Insertion and Deletion from BST
COMPLETED FOR STATIC INPUT
*/
#include<iostream>
using namespace std;
struct Node{
	int info;
	Node* left;
	Node* right;
};

Node* root=NULL; //root of tree
Node* loc=NULL; //node at which operation is to be performed mostly
Node* par=NULL; //parent of node shown by loc

Node* getnode(){
	return new Node;
}

void freenode(Node* p){
	delete p;
}

void findNode(int item){ //location and parent of node
	if(root == NULL){ //if tree is empty
		loc=NULL;
		par=NULL;
		return;	
	}
	if(item == root->info){ //if item exists at root
		loc=root;
		par=NULL;
		return;
	}
	Node* ptr;
	Node* save;
	if(item<=root->info){ //go to left sub tree
		ptr=root->left;
		save=root;
	}
	else{ //go to right sub tree
		ptr=root->right;
		save=root;			
	}
	while(ptr!=NULL){
		if(item==ptr->info){ //item found
			loc=ptr;
			par=save;
			return;		
		}
		save=ptr;
		if(item<=ptr->info) //go to left sub tree
			ptr=ptr->left;
		else	//go to right sub tree
			ptr=ptr->right;
	} 
	//if item doesn't exist, insert
	loc=NULL;
	par=save;
}

void insert(int item){
	
	findNode(item);

	Node* n;
	n = getnode();
	n->info = item;
	if(par == NULL) //if insertion at root
	root = n;
	else if(item<=par->info) //if new item is less than parent
	par->left = n;
	else //if new item is greater than parent
	par->right = n;

}

void deleteCaseA(Node* &loc,Node* &par){ //less than 2 children of node to be deleted
	Node* child;

	if(loc->left!=NULL) //if child is to the left
	child=loc->left;
	else if(loc->right!=NULL) //if child is to the right
	child=loc->right;
	else //no child
	child=NULL;

	if(par!=NULL){ //if root is NOT to be deleted
		if(loc==par->left)
		par->left=child;
		else
		par->right=child;
	}
	else //delete root
		root=child;
}

void deleteCaseB(int info){  //equal to 2 children
	
	Node* suc; //in-order successor
	Node* parsuc; //parent of in-order successor
	Node* ptr;
	Node* save;
	ptr=loc->right;
	save=loc;
	while(ptr->left!=NULL){
	//find suc and parsuc
		save = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = save;

	//deletes inorder successor,using caseA(0 or 1 child)
	deleteCaseA(suc,parsuc);
	//replace node to be deleted(loc) with its inorder successor

    if(par!=NULL){
		if(par->left==loc)
		par->left=suc;
		else
		par->right=suc;
	}
	else
		root=suc;
	suc->left=loc->left;
	suc->right=loc->right;
}

void remove(int info){
	findNode(info); //finds node to be deleted
	if(loc==NULL){
		cout<<"Item not in tree";
		return;	
	}
	if(loc->right!=NULL&&loc->left!=NULL)
		deleteCaseB(info);
	else
		deleteCaseA(loc,par);
	freenode(loc);
}

void intrav(Node* p){
	if(p!=NULL){
		intrav(p->left);
		cout<< p->info<<" ";
		intrav(p->right);
	}
}

int main(){
	insert(23);
	insert(18);
	insert(12);
	insert(20);
	insert(44);
	insert(35);
	insert(52);
	intrav(root);
	cout<<"\n";
	remove(23);
	cout<<"After removing 23,\n";
	intrav(root);
	cout<<"\n";
	return 0;
}
