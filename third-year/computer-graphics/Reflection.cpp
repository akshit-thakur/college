#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
    int gd=DETECT,gm,choice,n;
    initgraph(&gd,&gm,(char*)"d:\\tc\\bgi");
    int x[4];    int xdash[4];    int y[4];    int ydash[4];
    int xmid = getmaxx()/2,ymid = getmaxy()/2;
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
    setcolor(12);
    for(int i=0; i<n-1; i++)
        line(x[i]+xmid,ymid-y[i],x[i+1]+xmid,ymid-y[i+1]);
    line(x[n-1]+xmid,ymid-y[n-1],x[0]+xmid,ymid-y[0]);
    cout << "Reflection about: \n" << "1. X axis \n" << "2. Y axis \n" << "3. X=Y axis\n";
    cin >> choice;
    switch( choice){
    case 1:
        for(int i=0; i<n; i++)            y[i]=-y[i];
        break;
    case 2:
        for(int i=0; i<n; i++)            x[i] = -x[i];
        break;
    case 3:
        double theta= (90* 3.141592653589/180);
        for(int i=0; i<n; i++){
            y[i] = -y[i];
            xdash[i] = x[i]*cos(theta)-y[i]*sin(theta);
            ydash[i] = x[i]*sin(theta)+y[i]*cos(theta);
            x[i] = xdash[i];    y[i] = ydash[i];
        }
    }
    setcolor(15);
    for(int i=0; i<n-1; i++)
        line(x[i]+xmid,ymid-y[i],x[i+1]+xmid,ymid-y[i+1]);
    line(x[n-1]+xmid,ymid-y[n-1],x[0]+xmid,ymid-y[0]);;
    getch();
    return 0;
}
