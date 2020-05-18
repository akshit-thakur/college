//preemptive shortest job first
/*
Error:
2019-03-19 11:37:07 Ready queue not filling up properly...only last element in ready queue special case taken care of
*/
#include<iostream>
using namespace std;

int** pTable;

int** gantt;
int* wait;
int* turn;
int** ready;

void interchange(int &x,int &y){
	int t=x;
	x=y;
	y=t;
}
void sortP(int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(pTable[j][2]<pTable[i][2]&&pTable[j][1]<=gantt[i][2]){
				for(int k=0;k<3;k++)
				interchange(pTable[i][k],pTable[j][k]);
			}
		}
	}
}

void sortR(int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ready[j][1]<ready[i][1]){
				for(int k=0;k<2;k++)
				interchange(ready[i][k],ready[j][k]);
			}
		}
	}
}
void show(int n){
	for(int i=0;i<n;i++)
		cout<<"\n"<<pTable[i][0]<<" "<<pTable[i][1]<<" "<<pTable[i][2];
}

int ctr=0,j,k=0;
	float waitSum=0,turnSum=0;
	
void sjf(int i,int n,int count){
	
	/*while(pTable[i][3]!=0){
		i+=1;
		if(i==n)
		break;
	}*/
	if(count!=n-1){
		cout<<"\n"<<i<<" i..count "<<count<<"\n";
		gantt[count][0]=pTable[i][0];

		if(i==0)
		gantt[count][1]=pTable[i][1];
		else
		gantt[count][1]=gantt[count-1][2];

		gantt[count][2]=gantt[count][1]+pTable[i][2];
		
		wait[i]=gantt[count][1]-pTable[i][1];
		waitSum+=wait[i];
		
		turn[i]=gantt[count][2]-pTable[i][1];
		turnSum+=turn[i];
		
		pTable[i][3]=1;
		
		j=i+1;
		/*cout<<"\nj"<<j<<" ctr "<<ctr<<" g[i,2] "<<gantt[i][2]<<" pT[j,1] "<<pTable[j][1]<<" pT[j,3] "<<pTable[j][3]<<" pT[j,0] "
			<<pTable[j][0]<<"\n";
		cout<<"ready[0] "<<ready[0][0]+1<<"\n";*/
		do{
			if(pTable[j][3]==0){
				if(pTable[j][1]<=gantt[i][2]){
					ready[ctr][0]=pTable[j][0]-1;
					ready[ctr][1]=pTable[j][2];
					ctr+=1;
					pTable[j][3]=1;
					j+=1;
					if(j==n)
					break;
				}
				else break;
			}
			else if(j==n)
			break;
			else 
			j+=1;/*
			cout<<"\n";	
			for(k=0;k<ctr;k++)
			cout<<ready[k][0]<<" "<<ready[k][1]<<"...";
			cout<<"\n";*/
			sortR(ctr);
		}while(true);
		
					cout<<gantt[count][2]<<"...........\n";
		cout<<"\n"<<j<<" j after ctr "<<ctr<<"\n";
		cout<<"ready queue\n";
		for(k=0;k<ctr;k++)
		cout<<ready[k][0]<<" "<<ready[k][1]<<"...";
		cout<<"\n";
		i=ready[0][0];		
		for(k=0;k<ctr-1;k++){
			ready[k][0]=ready[k+1][0];
			ready[k][1]=ready[k+1][1];
		}
		cout<<"ready queue\n";
		for(k=0;k<ctr;k++)
		cout<<ready[k][0]<<" "<<ready[k][1]<<"...";
		/*
		if(i==n)
		break;
		*/
		cout<<"\n"<<i<<" i\n";
		ctr=1;
		sjf(i,n,count+1);
	}
	else if(count==n-1){
		i=ready[0][0];
		gantt[count][0]=pTable[i][0];

		if(i==0)
		gantt[count][1]=pTable[i][1];
		else
		gantt[count][1]=gantt[count-1][2];

		gantt[count][2]=gantt[count][1]+pTable[i][2];
		
		wait[i]=gantt[count][1]-pTable[i][1];
		waitSum+=wait[i];
		
		turn[i]=gantt[count][2]-pTable[i][1];
		turnSum+=turn[i];
		
		pTable[i][3]=1;
		
	}
	else
	return;
}

int main (){
	int i,n,ctr=0,j,k=0;
	/*float waitSum=0,turnSum=0;*/
	
	cout<<"Enter number of processes\n";
	cin>>n;
	pTable=new int*[n];
	ready=new int*[n];	
	gantt=new int*[n];
	for(i=0;i<n;i++){
		pTable[i]=new int[4];
		pTable[i][0]=i+1;
		pTable[i][3]=0;
		gantt[i]=new int[3];
		ready[i]=new int[2];
	}
	wait=new int[n];
	turn=new int[n];

	
	cout<<"Enter the process arrival,burst time\n";
	for(i=0;i<n;i++)
	cin>>pTable[i][1]>>pTable[i][2];
	
	cout<<"\nBefore sorting\n";
	show(n);
	
	sortP(n);
	cout<<"\nAfter sorting\n";	
	show(n);
	
	sjf(0,n,0);
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
/*0 8
2 5
5 4
9 11*/
/*0 9
7 3
1 10
11 7
25 1*/
