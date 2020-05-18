#include<iostream>
#include<graphics.h>
int main(){
    int gd = DETECT,gm;
    initgraph(&gd,&gm,(char*)"d:\\tc\\bgi");
    int rect[2][2];
    int tri[2][3];
    int t[2];
    do{
        int choice;
        cout << "Enter choice: \n";
        cout << "1. Rectangle";
        cout << "2. Triangle";
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
            cin >> tri[0][0] >> tri[0][1] >> tri[1][0] >> tri[1][1] >> tri[2][0] >> tri[2][1];
            cout << "Enter the translation vector:\n";
            cin >> t[0] >> t[1];
            setcolor(12);
            line(tri[0][0],tri[0][1],tri[1][0],tri[1][1]);
            line(tri[1][0],tri[1][1],tri[2][0],tri[2][1]);
            line(tri[2][0],tri[2][1],tri[0][0],tri[0][0]);
            for(int i=0;i<3;i++){
                tri[i][0] += t[0];
                tri[i][1] += t[1];
            }
            setcolor(15);
            line(tri[0][0],tri[0][1],tri[1][0],tri[1][1]);
            line(tri[1][0],tri[1][1],tri[2][0],tri[2][1]);
            line(tri[2][0],tri[2][1],tri[0][0],tri[0][0]);
            break;
        }
    }while(choice<3);
    rectangle
    return 0;
}
