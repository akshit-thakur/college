#include<iostream>
using namespace std;
class Vector{
  float arr[10];
  int index,k;
  public:
  void create();
  void modify(){
	cout<<"Enter the index you want to multiply at(starting from 1): \n";
    cin>>index;
	cout<<"Enter the number you want to multiply with: ";
    cin>>k;
    arr[index-1]*=k;
  }
  void multiply();
  void display();
};
void Vector::create(){
	cout<<"Enter 10 numbers:\n";
    for(int i=0;i<10;i++)
	cin>>arr[i];
}
void Vector::multiply(){
	cout<<"Enter the scalar to be multiplied with: \n";
    cin>>k;
    for(int i=0;i<10;i++)
	arr[i]*=k;
}
void Vector::display(){
	cout<<"The array is:\n("; 
    for(int i=0;i<9;i++)
		cout<<arr[i]<<" , ";
	cout<<arr[9]<<")\n";
}
int main(){
	Vector obj;
	obj.create();
	obj.display();
	obj.modify();
	obj.display();
	obj.multiply();
	obj.display();
	return 0;
}
