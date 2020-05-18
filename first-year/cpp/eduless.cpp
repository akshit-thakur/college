#include<iostream>
#include<string.h>
using namespace std;
class Staff{
	protected:
	int code;
	char* name;
	public:
	void setStaff(int c,char* n);
	void putStaff();
};
class Education{
	/**protected:
    char gen[30]; 
	char pro[30];
	public:
	void getEdu();
	void putEdu();*/
};
class Teacher:public Staff,public Education{
	protected:
	char* subject;
	char* publication;
	public:
	void setTeacher(char* s,char* p);
	void putTeacher();
};
class Typist:public Staff{
	protected:
	float speed;
	public:
	void setTypist(float s);
	void putTypist();
};
class Officer:public Staff,public Education{
	protected:
	char grade;
	public:
	void setOfficer(char g);
	void putOfficer();
};
class Regular:public Typist{
	protected: 
	float wage;
	public:
	void setRegular(float w);
	void putRegular();
};
class Casual:public Typist{
	protected:
	float wage;
	public:
	void setCasual(float w);
	void putCasual();
};
void Staff::setStaff(int c,char* n){
	code=c;
	strcpy(name,n);
}
void Staff::putStaff(){
	cout<<"Employee code: "<<code<<"\n";
	cout<<"Employee name: "<<name<<"\n";
}
/**void Education::getEdu(){
	cout<<"Enter highest qualification in general education: \n";
	cin.getline(gen,30);
	cout<<"Enter highest professional qualification: \n";
	cin.getline(pro,30);
}
void Education::putEdu(){
	cout<<"Highest qualification(Genearl education) : "<<gen<<"\n";
	cout<<"Highest professional qualification: "<<pro<<"\n";
}*/
void Teacher::setTeacher(char* s,char* p){
	//getEdu();
	strcpy(subject,s);
	strcpy(publication,p);
}
void Teacher::putTeacher(){
	putStaff();
	//putEdu();
	cout<<"Subject: "<<subject<<"\n";
	cout<<"Number of publications: "<<publication<<"\n";
}
void Typist::setTypist(float s){
	speed=s;
}
void Typist::putTypist(){
	putStaff();
	cout<<"Speed : "<<speed<<" words per minute.\n";
}
void Officer::setOfficer(char g){
	//getEdu();
	grade=g;
}
void Officer::putOfficer(){
	putStaff();
	//putEdu();
	cout<<"Grade of officer: "<<grade<<"\n";
}
void Regular::setRegular(float w){
	wage=w;
}
void Regular::putRegular(){
	putTypist();	
	cout<<"Wage: "<<wage<<"\n";
}
void Casual::setCasual(float w){
	wage=w;
}	
void Casual::putCasual(){
	putTypist();
	cout<<"Daily wage: "<<wage<<"\n";
}
int main(){
	Teacher t;
	t.setStaff(1,(char*)"RP Jain");
	t.setTeacher((char*)"Electronics",(char*)"TMH");
	cout<<"About teacher: \n";
	t.putTeacher();
	Officer o;
	o.setStaff(2,(char*)"JK Goswamy");
	o.setOfficer('A');
	cout<<"\nAbout Officer: \n";
	o.putOfficer();
	Regular r;
	r.setStaff(3,(char*)"Anand Mishra");
	r.setTypist(40);
	r.setRegular(7000);
	cout<<"About regular typist: \n";
	r.putRegular();
	Casual c;
	c.setStaff(4,(char*)"Aniket Tomar");
	c.setTypist(40);
	c.setCasual(7000);
	cout<<"About regular typist: \n";
	c.putCasual();
	return 0;
}
