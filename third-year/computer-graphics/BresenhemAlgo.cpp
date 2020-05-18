#include<iostream>
#include<graphics.h>

void brensenhem(int x1,int y1,int x2,int y2){
    int slopeError = (2*(y2-y1))- (x2-x1);
    for(int x=x1,y=y1;x<=x2;x++){
        putpixel(x,y,WHITE);
        slopeError += (2*(y2-y1));
        if(slopeError>=0){
            y+=1;
            slopeError -= 2*(x2-x1);
        }
    }
}
int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"d:\\tc\\bgi");
    brensenhem(0,0,150,400);
    getch();
    return 0;
}
