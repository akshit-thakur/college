#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std; 
class staff{
   //public:
   int code;
   char name[100];
   public:
   void set_info(char *n,int c){
		strcpy(name,n);
        code=c;
   }
};
class teacher : public staff{
        protected:
        char sub[100],publication[100];
        public:
        void set_details(char *s,char *p){
               strcpy(sub,s);strcpy(publication,p);
         }
         void show(){
               cout<<"name"<<setw(8)<<"code"<<setw(15)<<"subject"<<setw(25)
				<<"publication"<<endl<<name<<setw(8)<<code<<setw(25)<<sub
				<<setw(22)<<publication<<endl;
           }
};
class officer:public staff{
    char grade[100];
    public:
    void set_details(char *g){
       strcpy(grade,g);
    }
    void show(){
       cout<<" name "<<setw(15)<<"code"<<setw(15)<<"Catagory "<<endl
       <<name<<setw(10)<<code<<setw(15)<<grade<<endl;
    }
}; 
class typist: public staff{
       protected:
        float speed;
        public:
        void set_speed(float s){
                 speed=s;
        }
        void show(){
           cout<<" name "<<setw(15)<<"code"<<setw(15)<<"speed"<<endl
           <<name<<setw(10)<<code<<setw(15)<<speed<<endl<<endl;
        }
};
int main(){
 	teacher t;
    t.set_info("Ataur",420);
    t.set_details("programming with c++"," Tata McGraw Hill");
 	officer o;
    o.set_info("Md. Rashed",222);
    o.set_details("First class");
    typist tp;
    tp.set_info("Robiul Awal",333);
    tp.set_speed(85.5);
    cout<<"  About teacher: "<<endl;
    t.show();
    cout<<" About officer:"<<endl;
    o.show();
    cout<<" About  typist :"<<endl;
    tp.show();
    return 0;
}
