#include<iostream>
using namespace std;
class Matrix{
	int d1,d2;
	int** p;
	public:
	Matrix(int r,int c);
	void getElement(int i,int j,int val){
		p[i][j]=val;
	}
	int &putElement(int i,int j){
		return p[i][j];
	}
};
Matrix::Matrix(int r,int c){
	d1=r;
	d2=c;
	p=new int*[d1];
	for(int i=0;i<d1;i++)
	p[i]=new int[d2];
}
int main(){
    int r,c,val,i,j;
    cout<<"Enter rows: "; cin>>r;
    cout<<"Enter column: "; cin>>c;
    Matrix m(r,c);
    cout<<"Enter the matrix:\n";
    for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>val;
			m.getElement(i,j,val);
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
		cout<<m.putElement(i,j)<<" ";
		cout<<"\n";
	}
	return 0;
}
