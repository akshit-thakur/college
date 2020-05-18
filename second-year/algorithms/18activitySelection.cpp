#include<iostream>
using namespace std;

int* solution; //contains the solution sequence of events

int c=0; //counter of solution array

/*
bubble sort the input matrix on basis of finishing time
A: start time finish time event_no
*/
void bubbleSort(int** &A,int n){ 
    for( int i=0; i<n; i++){
    	for( int j=0; j<n-i-1; j++ ){
    		if( A[1][j] > A[1][j+1] ){ 
    			for( int k=0; k<3; k++){ //swapping 3 rows of 2 columns
                	float t=A[k][j];
                	A[k][j]=A[k][j+1];
                	A[k][j+1]=t;
                }
            }
        }
    }
}

void activity(int** &sf,int n){
	int i,j=0;
	
	solution[c++]=sf[2][0]; //id of first-finishing activity
	
	while(j<n){ //till all n activities are checked
		for( i=j+1; i<n; i++){ //start from the one next to last added activity to solution
			if( sf[0][i]>=sf[1][j] ){ //if the two activities are compatible then add activity i to solution  
				solution[c++]=sf[2][i];
				j=i; //updates id of last-added-activity to solution
				break;
			}
		}
		if(i==n) //if end of list is reached inside for loop
		break; //all activities are checked
	}
}


int main (){

	int n; //no. of activities
	int i; //array index
	
	/*Take input*/
	cout<<"Enter the number of activities: ";
	cin>>n;
	
	//Array initialization
	int** event;
	event = new int*[3];
	
	for(i=0;i<n;i++)
	event[i] = new int[n];
	
	solution = new int[n];
	
	//Fill the event matrix
	cout << "Enter start and finish times for\n";
	for( i=0; i<n; i++){
		cout << "activity " << i+1 << ": ";
		cin >> event[0][i] >> event[1][i];
		event[2][i] = i+1;
	}

	//sort the activities based on finish time
	bubbleSort(event,n);
	
	//select the maximum number of activities
	activity(event,n);
	
	/*Display the result*/
	cout << "The solution sequence for activities:\n";
	
	for( i=0; i<c; i++)
	cout << solution[i] << "  ";
	cout<<"\n";
	
	return 0;
}
