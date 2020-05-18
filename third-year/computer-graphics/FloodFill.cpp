#include<iostream>
#include<graphics.h>
using namespace std;
void floodFill4(int x,int y,int old,int newC){
	if(getpixel(x,y) == old){
		putpixel(x,y,newC);
		floodFill4(x+1,y,old,newC);
		floodFill4(x,y+1,old,newC);
		floodFill4(x-1,y,old,newC);
		floodFill4(x,y-1,old,newC);
	}
}

void floodFill8(int x,int y,int old,int newC){
    if(getpixel(x,y)==old){
        delay(5);
        putpixel(x,y,newC);
        floodFill8(x+1,y,old,newC);
        floodFill8(x-1,y,old,newC);
        floodFill8(x,y+1,old,newC);
        floodFill8(x,y-1,old,newC);
        floodFill8(x+1,y+1,old,newC);
        floodFill8(x-1,y+1,old,newC);
        floodFill8(x+1,y-1,old,newC);
        floodFill8(x-1,y-1,old,newC);
    }
}
int main(){
	int gm,gd=DETECT;
	int x,y,radius;
	cout<<"Enter x and y positions for circle\n";
	cin>>x>>y;
	cout<<"Enter radius of circle\n";
	cin>>radius;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	circle(x,y,radius);
	floodFill4(x,y,0,12);
	delay(1000);
	floodFill8(x,y,12,15);
	delay(3000);
	closegraph();
	return 0;
}
