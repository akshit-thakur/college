#include<iostream>
using namespace std;

void interchange(float &x,float &y){
        float temp=x;
        x=y;
        y=temp;
}

void disp(float** &A,int n){
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
}

void bubbleSort(float** &A,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[2][j]<A[2][j+1]){
                interchange(A[0][j],A[0][j+1]);
                interchange(A[1][j],A[1][j+1]);
                interchange(A[2][j],A[2][j+1]);
            }
        }
    }
}

int main(){
    int n,i,j;
    cout<<"Enter the array size:\n";
    cin>>n;
    float** a=new float*[3];
    for(i=0;i<3;i++)
    a[i]=new float[n];
    
    cout<<"Enter the array:\n";
    for(i=0;i<2;i++){
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    for(i=0;i<n;i++)
        a[2][i]=a[0][i]/a[1][i];

	cout<<"The array is:\n";
	disp(a,n);
    bubbleSort(a,n);
    cout<<"\nThe array after sorting is:\n";
    disp(a,n);
    /*
    for(i=0;i<3;i++){
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";

    

    for(i=0;i<2;i++){
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";*/

}
