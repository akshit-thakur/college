/**
14 Different sorting algorithms 
Bubble Sort
Selection Sort
Insertion Sort
Merge Sort 
Quick Sort
COMPLETED
*/
#include<iostream>
#define INFY 247000000; 
using namespace std;

void swap(int &i,int &j){
	int t=i;
	i=j;
	j=t;
}

void traverse(int* arr){
	for(int i=0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}

/*merge sort*/
void merge(int* mergeArr,int s,int m,int e){
	int i,j,n1,n2;
	n1=m-s+1;
	n2=e-m;
	int* L; //left side of array merge
	int* R; //right side of array merge
	L=new int[n1+1];
	R=new int[n2+1];
	for(i=0;i<n1;i++)
		L[i]=mergeArr[s+i];
	for(j=0;j<n2;j++)
		R[j]=mergeArr[m+j+1];
	L[n1]=INFY;
	R[n2]=INFY;
	i=0; j=0;
	for(int k=s;k<e+1;k++){
		if(L[i]<R[j]){
			mergeArr[k]=L[i];
			i+=1;
		}
		else{
			mergeArr[k]=R[j];
			j+=1;
		}
	}
}

void mergeSort(int* mergeArr,int s,int e){ //s=start,e=end
	if(s<e){
		int m=(s+e)/2;
		mergeSort(mergeArr,s,m);
		mergeSort(mergeArr,m+1,e);
		merge(mergeArr,s,m,e);
	}
}

/**quick sort*/
int partition(int* quick,int s,int e){
	int pivot=quick[e];
	int i=s-1 , temp;
	for(int j=s;j<=e-1;j++){
		if(quick[j]<=pivot){
			i+=1;
			temp=quick[i];
			quick[i]=quick[j];
			quick[j]=temp;
		}	
	}
	temp=quick[i+1];
	quick[i+1]=quick[e];
	quick[e]=temp;
	return i+1;
}

void quickSort(int* quick,int s,int e){
	if(s<e){
		int m=partition(quick,s,e);
		quickSort(quick,s,m-1);
		quickSort(quick,m+1,e);
	}
}

int main (){
	int i,j,k;	
	int bubble[]={4,3,2,1,7,6,5,10,9,8};
	int selection[]{4,3,2,1,7,6,5,10,9,8};
	int insertion[]={4,3,2,1,7,6,5,10,9,8};
	int mergeArr[]={4,3,2,1,7,6,5,10,9,8};
	int quick[]={4,3,2,1,7,6,5,10,9,8};
	cout<<"All arrays before sorting are:\n"; //all are given same pattern
	traverse(bubble); //size=10
	traverse(selection);
	traverse(insertion);
	traverse(mergeArr);
	traverse(quick);
	/**bubble sort*/
	for(i=0;i<10;i++){
		for(j=0;j<10-i-1;j++){
			if(bubble[j]>bubble[j+1])
			swap(bubble[j],bubble[j+1]);
		}
	}
	/**selection sort*/
	for(i=0;i<10;i++){
		for(j=i+1;j<10;j++){
			if(selection[i]>selection[j])
			swap(selection[i],selection[j]);
		}	
	}
	
	/**insertion sort*/
	for(i=1;i<10;i++){
		int key=insertion[i];
		for(int j=i-1;j>=0;j--){
			if(insertion[j]<key){
				insertion[j+1]=key;
				break;
			}
			if(insertion[j]>=key&&j==0){
				insertion[j+1]=insertion[j];
				insertion[j]=key;
			}
			else if(insertion[j]>=key)
				insertion[j+1]=insertion[j];
		}
	}
	/**merge sort*/
	mergeSort(mergeArr,0,9);
	
	/**quick sort*/
    quickSort(quick,0,9);
	cout<<"Bubble sort\n";
	traverse(bubble); //size=10
	cout<<"Selection sort\n";
	traverse(selection);
	cout<<"Insertion Sort\n";	
	traverse(insertion);
	cout<<"Merge Sort\n";	
	traverse(mergeArr);
	cout<<"Quick Sort\n";
	traverse(quick);

	return 0;
}
