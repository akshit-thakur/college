#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
	float height[4]={170.4,180.6,210.3,115.2};
	fstream f;
	int i;
	f.open("Binary.txt",ios::binary);
	f.write((char*)&height,sizeof(height));
	for(i=0;i<4;i++)
		height[i]=0;
	f.read((char*)&height,sizeof(height));
	for(i=0;i<4;i++){
		cout.setf(ios::showpoint);
		cout<<setw(10)<<setprecision(2)<<height[i];	
	}
	cout<<"\n";
	f.close();
	return 0;
}
