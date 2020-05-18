#include<iostream>
using namespace std;
class Matrix{
	int mat[3][3];
	public:
	Matrix(){}
	friend istream &operator >>(istream&,Matrix&);
	friend ostream &operator <<(ostream&,Matrix&);	
	Matrix operator *(Matrix &b){
		Matrix temp;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				temp.mat[i][j]=0;
				for(int k=0;k<3;k++)				
				temp.mat[i][j]+=mat[i][k]*b.mat[k][j];	
			}
		}		
		return temp;
	}
	friend Matrix operator +(Matrix&,Matrix&);
	friend Matrix operator -(Matrix&,Matrix&);
};
Matrix operator +(Matrix &a,Matrix &b){
	Matrix temp;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			temp.mat[i][j]=a.mat[i][j]+b.mat[i][j];
	}		
	return temp;
}
Matrix operator -(Matrix &a,Matrix &b){
	Matrix temp;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			temp.mat[i][j]=a.mat[i][j]-b.mat[i][j];
	}		
	return temp;
}
istream &operator >>(istream &din,Matrix &r){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
		din>>r.mat[i][j];	
	}	
	return din;
}
ostream &operator <<(ostream &dout,Matrix &r){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
		dout<<r.mat[i][j]<<" ";
		dout<<"\n";	
	}	
	return dout;
}
int main(){
	Matrix m,n,p,s,d;
	cout<<"Enter first 3*3 matrix: \n";
	cin>>m;
	cout<<"Enter second 3*3 matrix: \n";
	cin>>n;
	p=m*n;
	s=m+n;
	d=m-n;
	cout<<"Matrix 1\n";
	cout<<m;
	cout<<"Matrix 2\n";
	cout<<n;
	cout<<"Product Matrix\n";
	cout<<p;
	cout<<"Sum Matrix\n";
	cout<<s;
	cout<<"Difference Matrix\n";
	cout<<d;	
	return 0;
}
