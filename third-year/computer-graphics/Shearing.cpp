#include<iostream>
#include<graphics.h>
using namespace std;
void shear(int* x,int * y,int n,int sh,char ch)
{
    setcolor(12);
    for(int i=0; i<n-1; i++)
        line(x[i],y[i],x[i+1],y[i+1]);
    line(x[n-1], y[n-1], x[0], y[0]);
    if(ch=='x')
    {
        for(int i=0; i<n; i++)
            x[i]+=sh*y[i];
    }
    else
    {
        for(int i=0; i<n; i++)
            y[i]+=sh*x[i];
    }
    setcolor(15);
    for(int i=0; i<n-1; i++)
        line(x[i],y[i],x[i+1],y[i+1]);
    line(x[n-1], y[n-1], x[0], y[0]);
}
int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,(char*)"d:\\tc\\bgi");
    int x[3];    int y[3];
    int sh,choice;    char ch;
    do
    {
        cout << "Enter choice:\n";
        cout << "1. Rectangle\n";
        cout << "2. Triangle\n";
        cout << "3. Line\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter the 4 vertices of rectangle :\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
            cout << "Shear with respect to x or y axis?:\n";
            cin >> ch;
            cout << "Enter the direction of shear:\n";
            cin >> sh;
            shear(x,y,4,sh,ch);
            break;
        case 2:
            cout << "Enter the 3 vertices of triangle :\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
            cout << "Shear with respect to x or y axis?:\n";
            cin >> ch;
            cout << "Enter the direction of shear:\n ";
            cin >> sh;
            shear(x,y,3,sh,ch);
            break;
        case 3:
            cout << "Enter start coordinates of line:\n";
            cin >> x[0] >> y[0];
            cout << "Enter end coordinates of line:\n";
            cin >> x[1] >> y[1];
            cout << "Shear with respect to x or y axis?:\n";
            cin >> ch;
            cout << "Enter the direction of shear:\n ";
            cin >> sh;
            shear(x,y,2,sh,ch);
            break;
        }
    }
    while(choice>3);
    getch();
    return 0;
}
