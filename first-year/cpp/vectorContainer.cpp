#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>&v){
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	cout<<"\n";
}
int main(){
	vector<int>v;
	cout<<"Initial size = "<<v.size()<<"\n";
	//Putting values into the vector
	int x;
	for (int i = 0;i<5;i++){
		cin>>x;
		v.push_back(x);
	}; 
	//display the contents
	cout<<"Current contents: \n";
	display(v);
	//add one more value
	v.push_back(6.6); //float value truncated to int
	cout<<"Contents now: \n";
	display(v);
	//inserting elements
	vector<int>::iterator itr=v.begin(); //iterator
	itr+=3;
	v.insert(itr,9);
	//display the contents
	cout<<"\nContents after inserting: \n";
	display(v);
	//removing 4th and 5th elements
	v.erase(v.begin()+3,v.begin()+5);
	//display the contents
	display(v);
	cout<<"END\n";
	return 0;
}
