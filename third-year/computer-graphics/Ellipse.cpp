#include <iostream>
#include <graphics.h>
#define ROUND(a) ((int)(a + 0.5))
void ellipsePlotPoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, GREEN);
    putpixel(xc - x, yc + y, GREEN);
    putpixel(xc + x, yc - y, GREEN);
    putpixel(xc - x, yc - y, GREEN);
}
void ellipseMidpoint(int xc, int yc, int rx, int ry)
{
    int rx2 = rx * rx, ry2 = ry * ry;
    int twoRx2 = 2 * rx2, twoRy2 = 2 * ry2;
    int p, x = 0, y = ry, px = 0, py = twoRx2 * y;
    ellipsePlotPoints(xc, yc, x, y);
    /*Region 1*/
    p = ROUND(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py)
    {
        x++;
        px += twoRy2;
        if (p < 0)
            p += ry2 + px;
        else
        {
            y--;
            py -= twoRx2;
            p += ry2 + px - py;
        }
        ellipsePlotPoints(xc, yc, x, y);
    }
    /*Region 2*/
    p = ROUND(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y > 0)
    {
        y--;
        py -= twoRx2;
        if (p > 0)
            p += rx2 - py;
        else
        {
            x++;
            px += twoRy2;
            p += rx2 - py + px;
        }
        ellipsePlotPoints(xc, yc, x, y);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"d:\\tc\\bgi");
    ellipseMidpoint(100, 100, 50, 75);
    getch();
    return 0;
}
