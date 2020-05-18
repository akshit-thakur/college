#include<iostream>
using namespace std;
class Vector{
	float* arr; int size,index,number,k;
	public:
	void create();
	void imultiply(){
		cout<<"Enter the index you want to multiply at: (starting from 1)\n";
			cin>>index;
		cout<<"Enter the number you want to multiply with: ";
			cin>>number;
		arr[index-1]*=number;
	}
	void multiply();
	void display();
};
void Vector::create(){
	cout<<"Enter size of array: ";
	cin>>size;
	arr=new float[size];
	cout<<"Enter "<<size<<" numbers:\n";
	for(int i=0;i<size;i++)
		cin>>arr[i];
}
void Vector::multiply(){
	cout<<"Enter the scalar to be multiplied with: ";
		cin>>k;
	for(int i=0;i<size;i++)
		arr[i]*=k;
}
void Vector::display(){
	cout<<"The array is:\n(";
	cout.precision(2);
	for(int i=0;i<size-1;i++)
	cout<<arr[i]<<",";
	cout<<arr[i]<<")\n";
}
int main(){
	Vector obj;
	obj.create();
	obj.display();
	obj.imultiply();
	obj.display();
	obj.multiply();
	obj.display();
	return 0;
}
