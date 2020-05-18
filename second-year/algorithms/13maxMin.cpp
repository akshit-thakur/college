#include<iostream>
using namespace std;

int* a; //One-dimensional input array

void maxMin(int i,int j,int &maxi,int &mini){
	if(i==j){	//if there is only one element, it is the maximum and minimum
		maxi=a[i];
		mini=a[i];
	}
	
	else if(i == j-1){ //if there are 2 elements then
	
		maxi = max( a[i],a[j] ); //stores the larger number of the two
		mini = min( a[i],a[j] ); //stores the smaller number of the two
				
	}
	
	else{ //partition the array at the middle and go to left and right subarray
	
		int mid=(i+j)/2;
		int max1,min1;
		//go to left subarray
		maxMin(i,mid,maxi,mini);

		//go to right sub array
		maxMin(mid+1,j,max1,min1);
		
		//compare the left and the right sub array max and min
		maxi = max( maxi,max1);
		mini = min(mini,min1);
	
	}
	
	
}	

int main (){
	int n;	//size of input array
	int maxi,mini;	
	/*Take input*/
	cout<<"Enter size of array:\n";
	cin>>n;	
	
	//Array initialization
	a=new int[n];
	
	//fill up the array
	cout<<"Enter the array:\n";
	for(int i=0; i<n; i++)
		cin>>a[i];
	
	//find max and min
	maxMin(0,n-1,maxi,mini);

	/*Print output*/	
	cout<<"The largest number in array is: " << maxi << "\n";
	cout<<"The smallest number in array is: " << mini << "\n";
	
	return 0;
}
