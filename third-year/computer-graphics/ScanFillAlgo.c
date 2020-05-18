#include<iostream>
#include<graphics.h>

int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"d:\\tc\\bgi");
    brensenhem(0,0,150,400);
    getch();
    return 0;
}
