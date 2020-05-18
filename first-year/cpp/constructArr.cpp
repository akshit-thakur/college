#include<>
class Matrix{
	int r,c;
	int **p;
	public:
	Matrix(int,int);
	void getEle(int i,int j,int val){
		p[i][j]=value;
	}
	int &putEle(int i,int j){
		return p[i][j];		
	}
};
Matrix::Matrix(int a,int b){
	r=a;
	c=b;
	p=new int*[r];
	for(int i=0;i<r;i++)
		p[i]=new int[c];
}
int main(){
	int x,y,value;
	cout<<"Enter rows and columns: ";
	cin>>x>>y;
	Matrix m(x,y);
	for(int i=0;i<x;)
	return 0;
}
