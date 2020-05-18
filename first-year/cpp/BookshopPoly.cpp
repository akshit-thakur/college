//runtime polymorphism
#include<iostream>
#include<cstring>
using namespace std;
class Media{
    protected:
    char title[50];
    float price;
    public:
    Media(char* s,float a){
        strcpy(title,s);
        price=a;    
    }
    virtual void display()=0;
};
class Book:public Media{
    int pages;
    public:
    Book(char* s,float a,int p):Media(s,a){
        pages=p;
    }
    void display(){
        cout<<"\n Title: "<<title;
        cout<<"\n Pages: "<<pages;
        cout<<"\n Price: "<<price;    
    }
};
class Tape:public Media{
    float time;
    public:
    Tape(char* s,float a,float t):Media(s,a){
        time=t;    
    }
    void display(){
        cout<<"\nTitle: "<<title<<"\n";
        cout<<"Play Time: "<<time<<" mins\n";
        cout<<"Price: "<<price<<"\n";    
    }
};
int main(){
    char title[30];
    float price,time;
    int pages;
    //Book Details
    cout<<"\nENTER BOOK DETAILS\n";
    cout<<"Title: "; cin.getline(title,30);   
    cout<<"Pages: "; cin>>pages;
    cout<<"Price: "; cin>>price; 
    Book b1(title,price,pages);
    //Tape Details
    cout<<"\nENTER TAPE DETAILS\n";
    cout<<"Title: "; cin>>title;
    cout<<"Price: "; cin>>price;
    cout<<"Play Time(mins): "; cin>>time;
    Tape t1(title,price,time);
    Media* list=&b1;
    cout<<"\nMedia details\n";
    cout<<"\n....BOOK....\n";
    list->display();
    list=&t1;
    cout<<"\n....TAPE....\n";  
    list->display();
    return 0;
}
