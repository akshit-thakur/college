#include<iostream>
#include<graphics.h>
using namespace std;
int main(){
    int gd = DETECT,gm;
    initgraph(&gd,&gm,(char*)"d:\\tc\\bgi");
    int rect[2][2];    int x[3];    int y[3];    int t[2];
    int choice;
    do{
        cout << "Enter choice: \n";
        cout << "1. Rectangle\n";
        cout << "2. Triangle\n";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter the left,top,right and bottom for rectangle:\n";
            cin >> rect[0][0] >> rect[0][1] >> rect[1][0] >> rect[1][1];
            cout << "Enter the translation vector:\n";
            cin >> t[0] >> t[1];
            setcolor(12);
            rectangle(rect[0][0],rect[0][1],rect[1][0],rect[1][1]);
            rect[0][0] += t[0];
            rect[0][1] += t[1];
            rect[1][0] += t[0];
            rect[1][1] += t[1];
            setcolor(15);
            rectangle(rect[0][0],rect[0][1],rect[1][0],rect[1][1]);
            break;
        case 2:
            cout << "Enter the vertices of triangle:\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
            cout << "Enter the translation vector:\n";
            cin >> t[0] >> t[1];
            setcolor(12);
            line(x[0],y[0],x[1],y[1]);
            line(x[1],y[1],x[2],y[2]);
            line(x[2],y[2],x[0],y[0]);
            for(int i=0;i<3;i++){
                x[i] += t[0];
                y[i] += t[1];
            }
            setcolor(15);
            line(x[0],y[0],x[1],y[1]);
            line(x[1],y[1],x[2],y[2]);
            line(x[2],y[2],x[0],y[0]);
            break;
        }
    }while(choice!=1&&choice!=2);
    getch();
    return 0;
}
