#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char* a="oley";
	char* b="le";
	/*cout<<"Enter string A: ";
	cin.getline(a,1000);
	cout<<"Enter string B: ";
	cin.getline(b,999);*/
	int len1=strlen(a),len2=strlen(b);
	char* rev;
	rev=new char[len1+1];
	int i,j,k=0,start=0,flag=0;
	for(i=len1-1;i>0;i--)
	rev[k++]=a[i];
	rev[k]='\0';
	for(i=0;i<len2;i++){
	    char ch=b[i];
            cout<<"1 "<<start<<"\n";
	    for(j=start;j<len1;j++){
		if(a[j]!=ch)
		continue;
		if(j==len1-1){
		   flag=1;
		   break;
		}
		else{
		    if(flag==1)
		    break;
		    start=j;
		    break;			
		}		
	    }
            if(flag==1)
	    break;
	}
	int flag1=0;
	start=0;
	if(flag!=1){
	   	for(i=0;i<len2;i++){
		   cout<<start<<"\n";	
		   for(j=start;j<len1;j++){
			if(rev[j]!=b[i])
			continue;
			if(j==len1-1){
		    	   flag1=1;
		           break;
		    	}
			else{
		    	   if(flag1==1)
	                    break;
		           start=j;
		   	   break;			
		        }
                   }
                   if(flag1==1)
		   break;
		}
	}
	if(flag==0&&flag1==0)
	cout<<"GOOD STRING\n";
	else
	cout<<"BAD STRING\n";	
	return 0;
}
