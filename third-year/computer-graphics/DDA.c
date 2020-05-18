#include <stdio.h>
#include <graphics.h>
#define ROUND(a)((int)(a+0.5))

void lineDDA(int xa,int ya,int xb,int yb){
    int dx = xb-xa, dy = yb-ya,steps,k;
    float xIncrement,yIncrement, x = xa, y = ya;
    if( abs(dx) > abs(dy) )
        steps = abs(dx);
    else steps = abs(dy);
    xIncrement = dx /(float)steps;
    yIncrement = dy /(float)steps;
    SetPixel(ROUND(x),ROUND(y));
    for(k=0;k<steps;k++){
        x += xIncrement;
        y += yIncrement;
        SetPixel(ROUND(x),ROUND(y));
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    lineDDA(10,20,100,200);
    getch();
	return 0;
}
