#include<iostream>
#include<graphics.h>
using namespace std;
int main(){
    int gd = DETECT, gm,n,xMin,yMin,xMax,yMax;
    initgraph(&gd,&gm,(char*)"d:\\tc\\bgi");
    cout << "Enter the number of points: ";
    cin >> n;
    int xy[n][2];
    cout<<"Enter the points:\n";
    for(int i=0; i<n; i++)
        cin >>xy[i][0] >> xy[i][1]; //{{10,10}, {-10,10}, {400,100},{100,400}, {400,400}, {100,40}
    cout << "Enter the clipping window:\n";
    cin >> xMin >> yMin >> xMax >> yMax; //0,300,0,300
    rectangle(xMin,yMin,xMax,yMax);
    for (int i=0; i<n; i++){
        if ( (xy[i][0] >= xMin) && (xy[i][0] <= xMax) && (xy[i][1] >= yMin) && (xy[i][1] <= yMax)){
            putpixel(xy[i][0],xy[i][1],15);
            cout << "[ " << xy[i][0] << " , " << xy[i][1]<<" ]  : Inside\n";
        }
        else
            cout << "[ " << xy[i][0] << " , " << xy[i][1]<<" ]  : Outside\n";
    }
    getch();
    return 0;
}
