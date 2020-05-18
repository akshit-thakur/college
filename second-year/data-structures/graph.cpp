/**
15. DFS and BFS on Graph
*/
#include<iostream>
using namespace std;

void dispMat(int** &mat,int n){
	cout<<"The adjacency matrix is\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<mat[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

struct qNode{
	int info;
	qNode* next;
};

qNode* qStart=NULL;
int* visited;
int n;

void insert(int item){
	if(qStart==NULL){
		qNode* nq=new qNode;
		nq->info=item;
		nq->next=qStart;
		qStart=nq;
	}
	else{
		qNode* nq=new qNode;
		qNode* ptr=qStart;
		nq->info=item;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=nq;
		nq->next=NULL;			
	}
}

void remove(){
	if(qStart==NULL)
	return;
	else{
		qNode* ptr=qStart;
		qStart=ptr->next;		
		cout<<ptr->info<<" ";
		delete ptr;		
	}
}

void traverse(){
	qNode* ptr=qStart;
	while(ptr!=NULL){
		cout<<ptr->info<<" ";
		ptr=ptr->next;
	}
}

int* stack;
int top=0;

void push(int item,int maxStack){
	if(top==maxStack+1)
	return;
	top+=1;
	stack[top]=item;
}

int pop(){
	if(top==0)
	return -1;	
	top-=1;
	return stack[top+1]-1;
}

void peek(){
	cout<<stack[top]<<"\n";
}

void DFS(int** G,int i){
	int j;
   	cout<<" "<<i+1;
    visited[i]=1;
    for(j=0;j<n;j++)
		if(visited[j]==0&&G[i][j]==1)
        	DFS(G,j);
}

int main(){

	int i,j;

	cout<<"Enter number of nodes in graph: ";
	cin>>n;
	
	
	int** adjMat = new int*[n];
	for(i = 0; i < n; i++)
	    adjMat[i] = new int[n];

	for(i=0;i<n;i++){ //initialize to 0
		for(j=0;j<n;j++)
		adjMat[i][j]=2;
	}

	for(i=0;i<n;i++){ //enter the adjacency matrix
		cout<<"For node number "<<i+1<<"\n";
		for(j=0;j<n;j++){
			do{
				cout<<"Is it adjacent to node number "<<j+1<<"? 1 for yes 0 for no: ";
				cin>>adjMat[i][j];
			}while(adjMat[i][j]!=0&&adjMat[i][j]!=1);
		}
	}

	/*int adjMat[][8]={{0,1,1,0,0,0,0,0},{1,0,0,0,1,0,0,1},{1,0,0,1,0,0,0,0},{0,0,1,0,0,0,0,0},{0,1,0,0,0,1,0,1},{0,0,0,0,1,0,1,1},	  
{0,0,0,0,0,1,0,1},
			{0,1,0,0,1,1,1,0}};*/
	
	dispMat(adjMat,n);
	
	/*cout<<"The adjacency matrix is\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<adjMat[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";*/

	int* status=new int[n];

	for(i=0;i<n;i++)
		status[i]=1;

	i=0;
	insert(1);
	status[0]=2;
	cout<<"The BFS traversal is:\n";
	while(qStart!=NULL){		
		remove();
		status[i]=3;
		for(j=0;j<n;j++){
			if(adjMat[i][j]==1&&status[j]==1){
				insert(j+1);
				status[j]=2;
			}				
		}
		i+=1;
	}
	cout<<"\n";

	visited=new int[n];
	visited=0;
	cout<<"The DFS traversal is:\n";
	DFS(adjMat,0);
	cout<<"\n";
	/*stack=new int[n+1]; //stack[0] is not filled
	for(i=0;i<n;i++)
		status[i]=1;
	push(1,n);

	status[0]=2;
	i=0;
	while(top!=0){
		i=pop();
		status[i]=3;
		for(j=0;j<n;j++){
			if(adjMat[i][j]==1&&status[j]==1){
				push(j+1,n);
				status[j]=2;
			}
		}
		cout<<i+1<<" ";
	}
	cout<<"\n";*/
		
	return 0;
}
