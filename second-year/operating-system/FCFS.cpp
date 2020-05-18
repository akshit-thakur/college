#include<iostream>
using namespace std;

int** pTable;
int** gantt;
int* wait;
int* turn;

void sortP(int n){		
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(pTable[j][1]<pTable[i][1]){
				for(int k=0;k<3;k++)
				swap(pTable[i][k],pTable[j][k]);
			}
		}
	}
}

int main (){
	int i,n;
	float waitSum=0,turnSum=0;
	
	cout<<"Enter number of processes\n";
	cin>>n;
	pTable=new int*[n];
	gantt=new int*[n];
	for(i=0;i<n;i++){
		pTable[i]=new int[3];
		pTable[i][0]=i+1;
		gantt[i]=new int[3];
	}
	wait=new int[n];
	turn=new int[n];
	
	cout<<"Enter the process arrival,burst time\n";
	for(i=0;i<n;i++)
	cin>>pTable[i][1]>>pTable[i][2];
	
	sortP(n);

	for(i=0;i<n;i++){
		gantt[i][0]=pTable[i][0];
		
		if(i==0)
		gantt[i][1]=pTable[i][1];
		else
		gantt[i][1]=gantt[i-1][2];

		gantt[i][2]=gantt[i][1]+pTable[i][2];
		
		wait[i]=gantt[i][1]-pTable[i][1];
		waitSum+=wait[i];
		
		turn[i]=gantt[i][2]-pTable[i][1];
		turnSum+=turn[i];

	}
	cout<<"\nGantt Chart as Table:\nProcess\tEnter\tExit\n";
	for(i=0;i<n;i++)
		cout<<gantt[i][0]<<"\t"<<gantt[i][1]<<"\t"<<gantt[i][2]<<"\n";
	cout<<"WT\tTAT:\n";
	for(i=0;i<n;i++)
	cout<<wait[i]<<"\t"<<turn[i]<<"\n";
	cout<<"Average waiting time: "<<(float)(waitSum/n)<<"\n";
	cout<<"Average turn around time: "<<(float)(turnSum/n)<<"\n";	
	return 0;
}

/*struct pNode{
	int p_id;
	int arrival;
	int burst;
	pNode* next;
};

pNode* pStart=NULL;
pNode* pPtr=NULL;

void insertNodeP(int p,int a,int b){
	pNode* n=new pNode;
	n->p_id=p;
	n->arrival=a;
	n->burst=b;
	n->next=NULL;
	if(pStart==NULL)
		pStart=n;
	else{
		pPtr=pStart;
		while(pPtr->next!=NULL)
			pPtr=pPtr->next;
		pPtr->next=n;
	}		
}

void sort(int n){
	pPtr=pStart;
	for(i=0;i<n;i++){
		if(pPtr->arrival>(pPtr->next)->arrival){
			pNode* t=pPtr;
			pPtr->next=(pPtr->next)->next;
			(pPtr->next)->next=t;
		}
		
	}
}

struct rNode{
	int p_id;
	int burst;
	rNode* next;
};

rNode* rStart=NULL;
rNode* rPtr=NULL;

int main (){
	int n,i,p,a,b;
	cout<<"How many processes? ";
	cin>>n;
	cout<<"Enter Process id,Arrival Time,Burst Time: \n";
	for(i=0;i<n;i++){
		cin>>p>>a>>b;
		insertNodeP(p,a,b);
	}
	sort(n);	
	return 0;
}*/