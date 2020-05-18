#include<iostream>
#include<math.h>
#include<graphics.h>
#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)
using namespace std;
int main(){
    int gd = DETECT, gm, n, xmid,ymid,xPivot,yPivot,angle,choice;
    initgraph(&gd,&gm,(char*)"d:\\tc\\bgi");
    int x[4];    int y[4];
    xmid = getmaxx()/2; ymid = getmaxy()/2;
    line(5,ymid,getmaxx()-5,ymid);
    line(xmid+3,5,xmid+3,getmaxy()-5);
    do{
        cout << "Enter choice:\n" << "1. Rectangle\n" << "2. Triangle\n";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter the 4 vertices of rectangle :\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
            n = 4;
            break;
        case 2:
            cout << "Enter the 3 vertices of triangle :\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
            n = 3;
            break;
        }
    }while(choice>2);
    cout << "Enter rotation reference point:\n";
    cin >> xPivot >> yPivot;
    cout << "Enter the angle of rotation:\n";
    cin >> angle;
    setcolor(12);
    for(int i=0; i<n-1; i++)
        line(x[i]+xmid,ymid-y[i],x[i+1]+xmid,ymid-y[i+1]);
    line(x[n-1]+xmid,ymid-y[n-1],x[0]+xmid,ymid-y[0]);
    for(int i=0; i<n; i++){
        int xShifted =  x[i] - xPivot;
        int yShifted =  y[i] - yPivot;
        x[i] = xPivot + (xShifted*COS(angle) - yShifted*SIN(angle));
        y[i] = yPivot + (xShifted*SIN(angle) + yShifted*COS(angle));
    }
    setcolor(15);
    for(int i=0; i<n-1; i++)
        line(x[i]+xmid,ymid-y[i],x[i+1]+xmid,ymid-y[i+1]);
    line(x[n-1]+xmid,ymid-y[n-1],x[0]+xmid,ymid-y[0]);
    getch();
    return 0;
}
