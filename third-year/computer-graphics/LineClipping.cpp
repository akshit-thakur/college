#include <iostream>
#include<graphics.h>
using namespace std;
const int INSIDE = 0, LEFT = 1,RIGHT = 2,BOTTOM = 4, TOP = 8; // 1000
int xMax,yMax,xMin,yMin;
// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
    // initialized as being inside
    int code = INSIDE;
    if (x < xMin)	 // to the left of rectangle
        code |= LEFT;
    else if (x > xMax) // to the right of rectangle
        code |= RIGHT;
    if (y < yMin)	 // below the rectangle
        code |= BOTTOM;
    else if (y > yMax) // above the rectangle
        code |= TOP;
    return code;
}

void cohenSutherlandClip(double x1, double y1,double x2, double y2)
{
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1), code2 = computeCode(x2, y2);
    // Initialize line as outside the rectangular window
    bool accept = false;
    while (true)
    {
        if ((code1 == 0) && (code2 == 0)) // If both endpoints lie within rectangle
        {
            accept = true;
            break;
        }
        else if (code1 & code2) // If both endpoints are outside rectangle in same region
            break;
        else  // Some segment of line lies within the rectangle
        {
            int codeOut;
            double x, y;
            // At least one endpoint is outside the rectangle, pick it.
            codeOut = (code1!=0)? code1:code2;
            // Find intersection point using formulas y = y1 + slope * (x - x1), x = x1 + (1 / slope) * (y - y1)
            if (codeOut & TOP)   // point is above the clip rectangle
            {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            }
            else if (codeOut & BOTTOM)   // point is below the rectangle
            {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            }
            else if (codeOut & RIGHT)   // point is to the right of rectangle
            {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            }
            else if (codeOut & LEFT)    // point is to the left of rectangle
            {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }
            // Now intersection point x,y is found.We replace point outside rectangle by intersection point
            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout <<"Line accepted from " << x1 << ", " << y1 << " to "<< x2 << ", " << y2 << endl;
        line(x1,y1,x2,y2);
    }
    else
        cout << "Line rejected" << endl;
}
int main()
{
    int gd = DETECT,gm,n;
    double x1,y1,x2,y2;
    initgraph(&gd,&gm,(char*)"d:\\turboc\\bgi");
    cout << "Enter the clipping window:\n";
    cin >> xMin >> yMin >> xMax >> yMax;
    rectangle(xMin,yMin,xMax,yMax);
    cout << "Enter the number of lines:\n";
    cin >> n;
    cout<<"Enter the start and end vertices of lines:\n";
    for(int i=0; i<n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cohenSutherlandClip(x1,y1,x2,y2);
    }
    getch();
    return 0;
}
