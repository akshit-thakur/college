#include<iostream>
#include<graphics.h>
using namespace std;
int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "d:\\tc\\bgi");
	int point[2][2];
	int translate[2];
	cout<<"Enter the start coordinates of line:\n";
	cin>>point[0][0]>>point[0][1];
	cout<<"Enter the end coordinates of line\n";
	cin>>point[1][0]>>point[1][1];
	cout<<"Enter the translation vector:\n";
	cin>>translate[0]>>translate[1];
	setcolor(12);
	line(point[0][0],point[0][1],point[1][0],point[1][1]);
    point[0][0] += translate[0];
    point[0][1] += translate[1];
    point[1][0] += translate[0];
    point[1][1] += translate[1];
    setcolor(15);
    line(point[0][0],point[0][1],point[1][0],point[1][1]);
    getch();
    closegraph();
}
