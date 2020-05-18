#include<iostream>
#include<graphics.h>
using namespace std;
void findNewCoordinate(int s[][3], int p[][1])
{
    int temp[3][1] = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 3; k++)
                temp[i][j] += (s[i][k] * p[k][j]);

    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
    p[2][0] = temp[2][0];
}
void scale(int x[], int y[],int n,int sx, int sy,int xref,int yref)
{
    setcolor(12);
    for(int i=0; i<n-1; i++)
        line(x[i],y[i],x[i+1],y[i+1]);
    line(x[n-1], y[n-1], x[0], y[0]);
    int s[3][3] = { sx, 0, xref*(1-sx),
                    0, sy, yref*(1-sy),
                    0,  0,  1
                  };
    int p[3][1];
    for (int i = 0; i < n; i++)
    {
        p[0][0] = x[i];
        p[1][0] = y[i];
        p[2][0] = 1;
        findNewCoordinate(s, p);
        x[i] = p[0][0];
        y[i] = p[1][0];
    }
    setcolor(15);
    for(int i=0; i<n-1; i++)
        line(x[i],y[i],x[i+1],y[i+1]);
    line(x[n-1], y[n-1], x[0], y[0]);
}
int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm,(char*)"d:\\tc\\bgi");
    int x[4];
    int y[4];
    int sx,sy,choice,refx,refy;
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
            cout<<"Enter the coordinates of rectangle:\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
            cout<<"Enter the scaling vector:\n";
            cin >> sx >> sy;
            cout<<"Enter the reference points:\n";
            cin >> refx >> refy;
            scale(x,y,4,sx,sy,refx,refy);
            break;
        case 2:
            cout<<"Enter the coordinates of triangle:\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
            cout<<"Enter the scaling vector:\n";
            cin >> sx >> sy;
            cout<<"Enter the reference points:\n";
            cin >> refx >> refy;
            scale(x,y,3,sx,sy,refx,refy);
            break;
        case 3:
            cout<<"Enter the coordinates of line:\n";
            cin >> x[0] >> y[0] >> x[1] >> y[1];
            cout<<"Enter the scaling vector:\n";
            cin >> sx >> sy;
            cout<<"Enter the reference points:\n";
            cin >> refx >> refy;
            scale(x,y,2,sx,sy,refx,refy);
            break;
        }
    }
    while(choice>3);
    getch();
    closegraph();
    return 0;
}
