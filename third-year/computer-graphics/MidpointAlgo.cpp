#include<iostream>
#include<graphics.h>

void drawCircle(int x,int y,int xc,int yc){
    int color = YELLOW;
    putpixel(x+xc ,y+yc, color);
	putpixel(-x+xc ,y+yc, color);
	putpixel(x+xc, -y+yc,color);
	putpixel(-x+xc, -y+yc,color);
	putpixel(y+xc, x+yc, color);
	putpixel(y+xc, -x+yc, color);
	putpixel(-y+xc, x+yc, color);
	putpixel(-y+xc, -x+yc, color);
}
void midPointAlgo(int xc,int yc,int r){
    int x=0,y=r;
    int pk = 3 - 2*r;
    drawCircle(x,y,xc,yc);
	while(x < y){
        if(pk <= 0){
			pk = pk + (4*x) + 6;
			drawCircle(++x,y,xc,yc);
		} else{
			pk = pk + (4*(x-y)) + 10;
			drawCircle(++x,--y,xc,yc);
		}
	}
}
int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"D:\\TC\\BGI");
    midPointAlgo(200,200,50);
    getch();
    return 0;
}
