#include<iostream>
#include<graphics.h>
int main(){
    int gd = DETECT, gm;
    initgraph(&gd,&gm,(char*)"d:\\tc\\bgi");
    int choice;
    do{
        cout << "Enter choice:\n";
        cout << "1. Rectangle"
        cout << "2. Triangle"
        cout << "3. Line"
        switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }while(choice>3);
    getch();
    return 0;
}
