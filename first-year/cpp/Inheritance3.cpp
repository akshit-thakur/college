#include<iostream>
using namespace std;
class Staff{
	protected:
	int code;
	char name[30];
	public:
	void getStaff();
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
	char subject[15];
	char publication[20];
	public:
	void getTeacher();
	void putTeacher();
};
class Typist:public Staff{
	protected:
	float speed;
	public:
	void getTypist();
	void putTypist();
};
class Officer:public Staff,public Education{
	protected:
	char grade;
	public:
	void getOfficer();
	void putOfficer();
};
class Regular:public Typist{
	protected: 
	float wage;
	public:
	void getRegular();
	void putRegular();
};

class Casual:public Typist{
	protected:
	float dWage;
	public:
	void getCasual();
	void putCasual();
};
void Staff::getStaff(){
	cout<<"Enter name: \n";
	cin.getline(name,15);
	cout<<"Enter employee code: \n";
	cin>>code;
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
void Teacher::getTeacher(){
	getStaff();
	//getEdu();
	cout<<"Enter subject of teacher: ";
	cin.getline(subject,15);
	cout<<"Enter publication: ";
	cin.getline(publication,20);
}
void Teacher::putTeacher(){
	putStaff();
	//putEdu();
	cout<<"Subject: "<<subject<<"\n";
	cout<<"Publication: "<<publication<<"\n";
}
void Typist::getTypist(){
	getStaff();
	cout<<"Enter speed of typist in words per minute: \n";
	cin>>speed;
}
void Typist::putTypist(){
	putStaff();
	cout<<"Speed : "<<speed<<" words per minute.\n";
}
void Officer::getOfficer(){
	getStaff();
	//getEdu();
	cout<<"Enter grade of officer: \n";
	cin.get(grade);
}
void Officer::putOfficer(){
	putStaff();
	//putEdu();
	cout<<"Grade of officer: "<<grade<<"\n";
}
void Regular::getRegular(){
	getTypist();
	cout<<"Enter wage: \n";
	cin>>wage;
}
void Regular::putRegular(){
	putTypist();	
	cout<<"Wage: "<<wage<<"\n";
}
void Casual::getCasual(){
	getTypist();
	cout<<"Enter daily wage: \n";
	cin>>dWage;
}	
void Casual::putCasual(){
	putTypist();
	cout<<"Daily wage: "<<dWage<<"\n";
}
int main(){
	Teacher t;
	t.getTeacher();
	Officer o;
	o.getOfficer();
	Casual c;
	c.getCasual();
	Regular r;
	r.getRegular();	
	t.putTeacher();
	o.putOfficer();
	c.putCasual();
	r.putRegular();
	return 0;
}
