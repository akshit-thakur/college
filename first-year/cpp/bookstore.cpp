#include<iostream>
#include<string.h>
using namespace std;
const int size=50;
int i=3;
class Book{
	char* author;
	char* title;
	char* publisher;
	float price;
	int stock;
	public:
	static int success;
	static int fail;
	Book(){
		author=new char[1];
		title=new char[1];
		publisher=new char[1];
	    price=0;
		stock=0;		
	}
	Book(const char* str1,const char* str2,const char* str3,float cost,int st){
		author=new char[strlen(str1)+1];
		strcpy(author,str1);
		title=new char[strlen(str2)+1];
		strcpy(title,str2);
		publisher=new char[strlen(str3)+1];
		strcpy(publisher,str3);
		price=cost;
		stock=st;	
	}
	int search(const char* ptr1,const char* ptr2){
		if((strcmp(author,ptr1)==0)&&(strcmp(title,ptr2)==0))
		return 1;
		else
		return 0;	
	}
	void request(int n){
		char k;
		if(stock>=n){
			cout<<"Total cost of book = "<<(n*(price))<<"\n";
			cout<<"Do you want to buy? (y/n) \n";
			cin>>k;
			if(k=='y'||k=='Y'){
				cout<<"Query processed"<<"\n";
				success++;
				stock-=n;
				cout<<"Final stock available: "<<stock<<"\n";			
			}
			else if(k=='n'||k=='N'){
				cout<<"You opt to not buy any book \n";
				fail++;			
			}
			else
			cout<<"Enter correct key";
		}
		else if(n>stock){
			cout<<"Not in stock"<<"\n";
			fail++;
		}
		else if(n==0){
			cout<<"You didn't purchase any book";
			fail++;
		}
	}
	int modifyPrice(char* str1,char* str2,float cost){	
		if((strcmp(author,str1)==0)&&(strcmp(title,str2)==0)){
			price=cost;
			cout<<"Price updated successfully"<<"\n";
			return 1;
		}
		else
			return 0;	
	}
	void details(){
		cout<<"The details of the book are:\n";
		cout<<"Title: "<<title<<"\n"<<"Author: "<<author<<"\n"<<"Publisher: "<<publisher<<"\n"
			<<"Price: "<<price<<"\n"<<"Stock: "<<stock<<"\n";
	}
};
int Book::success;
int Book::fail;
int main(){
	Book *obj[size];
	obj[0]=new Book("ABC","DEF","XYZ",500,50);
	obj[1]=new Book("PQR","LMN","IJK",1000,20);	
	obj[2]=new Book("GHI","STU","BCD",200,100);
	char str1[20],str2[20],str3[20];
	float cost; int st,n,j; char choice;
	do{
		cin.sync(); //fflush in c
		cout<<"1. Enter new book "<<"\n"<<"2. Search "<<"\n"<<"3. Modify cost "<<"\n"<<"4. Transactions "<<"\n"<<"5. Exit"<<"\n";
		cin.get(choice);
		switch(choice){
			case '1':
				cout<<"Enter book author,title,publisher,cost and stock: \n";			
				cin>>str1>>str2>>str3>>cost>>st;
				obj[i++]=new Book(str1,str2,str3,cost,st);
				break;
			case '2':
				cout<<"Enter author and title\n";
				cin>>str1>>str2;
				for(j=0;j<i;j++){
					if(obj[j]->search(str1,str2)==1){
						obj[j]->details();
						cout<<"Number of copies you want to buy: ";
						cin>>n;
						obj[j]->request(n);
						break;
					}			
				}
				if(j==i){
					cout<<"Required book not available";
					Book::fail++;
				}
				break;
			case '3':
				cout<<"Enter book author and title:\n";
				cin>>str1>>str2;
				cout<<"Enter the new cost: ";
				cin>>cost;
				for(j=0;j<i;j++){
					if(obj[j]->modifyPrice(str1,str2,cost)==1)
					break;
				}
				if(j==i)
					cout<<"Required book not available";
				break;
			case '4':
				cout<<"Number of successful transcations: "<<Book::success<<"\n"
					<<"Number of unsucessful transactions: "<<Book::fail<<"\n";
				break;
		}
	}while(choice!='5');	
	return 0;
}
