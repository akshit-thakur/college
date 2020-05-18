#include <iostream>
#include <graphics.h>
using namespace std;
void bFill4(int x, int y, int fillC,int boundaryC){
	if(getpixel(x, y) != boundaryC && getpixel(x, y) != fillC){
		putpixel(x, y, fillC);
		bFill4(x + 1, y, fillC, boundaryC);
		bFill4(x, y + 1, fillC, boundaryC);
		bFill4(x - 1, y, fillC, boundaryC);
		bFill4(x, y - 1, fillC, boundaryC);
	}
}
void bFill8(int x, int y, int fillC, int boundaryC){
    if( getpixel(x, y) != boundaryC &&  getpixel(x, y)!= fillC ){
       putpixel(x, y, fillC);
       bFill8(x + 1, y, fillC, boundaryC);
       bFill8(x - 1, y, fillC, boundaryC);
       bFill8(x, y + 1, fillC, boundaryC);
       bFill8(x, y - 1, fillC, boundaryC);
       bFill8(x + 1, y + 1, fillC, boundaryC);
       bFill8(x - 1, y - 1, fillC, boundaryC);
       bFill8(x + 1, y - 1, fillC, boundaryC);
       bFill8(x - 1, y + 1, fillC, boundaryC);
    }
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "d:\\tc\\bgi");
	int left,top,right,bottom;
	cout<<"Enter 4 vertices of rectangle\n";
	cin>>left>>top>>right>>bottom;
	rectangle(left,top,right,bottom);
	bFill4((left+right)/2,(top+bottom)/2,12,15);
	delay(3000);
	bFill8((left+right)/2,(top+bottom)/2, 15, 15);
	delay(3000);
	getch();
	closegraph();
	return 0;
}
