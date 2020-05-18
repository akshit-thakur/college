#include<iostream>
using namespace std;

int timeT=0; //global variable for total burst elapsed

struct pNode{ //process queue
	int p_id;
	int arrive;
	int burst;
	pNode* next;
};

pNode* pStart=NULL;
pNode* pPtr=NULL;
pNode* pPre=NULL;

struct rNode{	//ready queue
	int p_id;
	int burst;
	rNode* next;
};

rNode* rStart=NULL;
rNode* rPtr=NULL;

struct gNode{	//gantt chart
	int p_id;
	int start;
	int end;
	gNode* next;
};

gNode* gStart=NULL;
gNode* gPtr=NULL;

void insertProcess(int p,int a,int b){
	pNode* n=new pNode;
	
	n->p_id=p;
	n->arrive=a;
	n->burst=b;

	if(pStart==NULL){		
		n->next=pStart;
		pStart=n;
	}
	else{
		pPtr=pStart;
		while(pPtr->next!=NULL)
			pPtr=pPtr->next;
		pPtr->next=n;
		n->next=NULL;
	}
}

void createProcess(){
	int count,p,a,b;
	cout<<"Enter number of processes: ";
	cin>>count;
	cout<<"Enter Process id,Arrival Time and Burst Time:\n";
	for(int i=0;i<count;i++){
		cin>>p>>a>>b;
		insertProcess(p,a,b);
	}
}


void showProcess(){
	cout<<"\nThe process queue is: \n";
	cout<<"\nProcess id\tArrival Time\tBurst Time\n";
	pPtr=pStart;
	while(pPtr!=NULL){
		cout<<pPtr->p_id<<"\t\t"<<pPtr->arrive<<"\t\t"<<pPtr->burst<<"\n";
		pPtr=pPtr->next;
	}
}

void insertReady(){
	//removes first process and inserts at last of ready queue
	/*remove first process*/
	pNode* t = pStart;
	if(pStart->next!=NULL){
		pStart = pStart->next;
		rNode* n = new rNode;	
		n->p_id = t->p_id;	
		n->burst = t->burst;
		if(rStart==NULL){
			n->next=rStart;
			rStart=n;
		}
		else{
			rPtr=rStart;
			while(rPtr->next!=NULL)
				rPtr=rPtr->next;
			rPtr->next=n;
			n->next=NULL;
		}
		delete t;
		//showProcess();
	}
}
void showReady(){
	cout<<"\nThe ready queue is: \n";
	cout<<"\nProcess id\tBurst Time\n";
	rPtr=rStart;
	while(rPtr!=NULL){
		cout<<rPtr->p_id<<"\t\t"<<rPtr->burst<<"\n";
		rPtr=rPtr->next;
	}
}

void insertGantt(int p,int s,int e){
	gNode* n=new gNode;
	n->p_id=p;
	n->start=s;
	n->end=e;
	if(gStart==NULL){
		n->next=gStart;
		gStart=n;
	}
	else{
		gPtr=gStart;
		while(gPtr->next!=NULL)
			gPtr=gPtr->next;
		gPtr->next=n;
		n->next=NULL;
	}
}

void showGantt(){

	cout<<"\nThe gantt chart is: \n";
	cout<<"\nProcess id\tStart Time\tEnd Time\n";
	gPtr=gStart;
	
	while(gPtr!=NULL){
		cout<<gPtr->p_id<<"\t\t"<<gPtr->start<<"\t\t"<<gPtr->end<<"\n";
		gPtr=gPtr->next;
	}
	
}

void calcFCFS(){
	gPtr=gStart;
	int sum=0;
	int count=0;
	while(gPtr!=NULL){
		sum+= (gPtr->start) - (pPtr->arrive) ;
		count+=1;
		gPtr=gPtr->next;
	}
	cout<<"Average waiting time : "<<sum/count<<"\n";
}

int main (){
	int choice=0;
	
	cout<<"1. FCFS \n2. SJF\n3. SRTF\n4.Priority\n";
	cout<<"Enter scheduling type:\n";
	do{
		cin>>choice;
	}while(choice<1||choice>4);
	
	createProcess();
	
	showProcess();
	
	int startT=0;
	
	switch(choice){
		case 1:
			pPtr=pStart->next;
			pPre=pStart;
			insertReady();
			while(pPtr!=NULL){
				//cout<<(pPre->burst)+startT<<"..."<<pPre->p_id;
				if(pPtr->arrive==timeT){
					insertReady();
				}
				else if((pPre->burst)+startT==timeT){
					insertGantt(pPre->p_id,startT,timeT);
					//showGantt();
					startT=timeT;
					pPre=pPtr;
					pPtr=pPtr->next;
				}
				timeT+=1;
			}
			showReady();
			cout<<timeT<<"\n";
			showGantt();
			//calcFCFS();
		break;
		case 2:
		break;
		case 3: break;
		case 4: break;
	}
	return 0;
}
