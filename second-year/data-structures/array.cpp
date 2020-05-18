/**
1. Traversal,Insertion and Deletion at and from a given location in array
ERRORS PERSIST
*/
#include<iostream>
using namespace std;
class Array{
	int* arr;
	int size;
	public:
	Array(){
		size=0;
		arr=new int[size];
	}
	Array(int s){
		size = s;
		arr=new int[size];	
	}
	void initialize(){
		for(int i=0;i<size;i++)
		cin>>arr[i];
	}
	void insert(int val,int index){
		if(index>size)
		cout<<"Index out of bound\n";		
		else if(arr[size-1]!=-1)
			cout<<"Array already full\n";
		else{
			int i;
			for(i=size-1;i>index-1;i--)
				arr[i]=arr[i-1];
			arr[index-1]=val;
		}
	}
	void remove(int index){
		for(int i=index-1;i<size-1;i++)	
			arr[i]=arr[i+1];
		arr[size-1]=-1;
	}
	void traverse(){
		cout<<"The array is:\n";
		for(int i=0;i<size;i++)
			cout<<arr[i]<<" ";
		cout<<"\n-1 means empty\n";	
	}
};
int main (){
	int n,choice,val,index;
	cout<<"Enter size of array\n";
	cin>>n;
	Array arr(n);
	cout<<"Enter the array:\n";
	arr.initialize();
	do{
		cout<<"1. Insert\n2. Delete\n3. Traverse\n4. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the value to be inserted:\n";
				cin>>val;
				cout<<"Enter the index at which to insert(start at 1):\n";
				cin>>index;
				arr.insert(val,index);
				break;
			case 2:
				cout<<"Enter the index at which to remove(start at 1):\n";
				cin>>index;
				arr.remove(index);
 				break;		
			case 3:
				arr.traverse();
		}
	}while(choice!=4);
	return 0;
}
