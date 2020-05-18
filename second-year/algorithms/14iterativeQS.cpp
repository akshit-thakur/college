#include<iostream>
using namespace std;
int indexStack[100];
int top=0;
int a[10];

int push(int x){
    indexStack[top] = x;
    top = top+1;
}

int pop(){
    top-=1;
    int item=indexStack[top];
    return item;
}

bool isEmpty(){
    return top==0;
}

int part(int m,int p){
    int i=m; int j=p; int v=a[m];
    do{
        do{ i+=1; }while(a[i]<v);
        do{ j-=1; }while(a[j]>v);
        if(i<=j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }while(i<=j);
    a[m]=a[j];
    a[j]=v;
    return j;
}

void qSort(int p,int q){
    while(true){
        while(p<q){
                int j=part(p,q+1);
                if((j-p)<(q-j)){
                    push(j+1);
                    push(q);
                    q=j-1;
                }
                else{
                    push(p);
                    push(j-1);
                    p=j+1;
                }
            }
            if(isEmpty())
                return;
            q=pop();
            p=pop();
    }
}

int main(){


    cout<"\nEnter the array:\n";

    for(int i=0;i<10;i++)
    cin>>a[i];

    cout<<"The array is:\n";

    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
    cout<<"\n";

    qSort(0,9);


    cout<<"The array is:\n";

    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}
