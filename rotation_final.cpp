
#include <iostream>
#include <math.h>
#include <graphics.h>
#include "cyrus_beck.cpp"
using namespace std;
#define x first
#define y second
int main()
{

    int n;
    cout << "Enter no. of points ";
    cin >> n;

    pair<double, double> poly[n], point[2]; //,line1[n],normal[n],fin[2];
    double xg = 0, yg = 0;
    for (int i = 0; i < n; ++i)
    {
        double x, y;
        cin >> x >> y;
        poly[i] = {x, y};
        xg += x;
        yg += y;
    }
    xg = (xg * 1.0) / (3.0);
    yg = (yg * 1.0) / (3.0);
    // for (int i = 0; i < n; ++i)
    // {
    //     poly[i].x -= xg;
    //     poly[i].y -= yg;
    // }
    // for(int i = 0; i<n; ++i){
    //     int k,l;
    //     if(i==n-1){
    //          k = poly[0].x-poly[n-1].x;
    //          l = poly[0].y-poly[n-1].y;
    //     }
    //     else
    //     {
    //     k = poly[i+1].x-poly[i].x;
    //     l = poly[i+1].y-poly[i].y;
    //     }

    //     line1[i] = {k,l};

    //     normal[i] = {l,-k};

    // }

    cout << "ENTER points\n";

    for (int i = 0; i < 2; ++i)
    {
        double x, y;
        cin >> x >> y;
        point[i] = {x, y};
    }
    double deg = (3.14) / (18 * 1.0);
    pair<double, double> pr = {cos(deg), sin(deg)};
    int gd = DETECT, gm;
    char drive[] = "";
    initgraph(&gd, &gm, drive);
    for (int j = 0; j < 100; ++j)
    {
        cleardevice();
         cyrus(n,poly,point);
        for (int i = 0; i < n - 1; ++i)
        {
          //  line(poly[i].x+xg, poly[i].y+yg, poly[i + 1].x+xg, poly[i + 1].y+yg);
            double x = poly[i].x-xg, y = poly[i].y-yg;
            poly[i].x = x * pr.x - y * pr.y + xg;
            poly[i].y = y * pr.x + x * pr.y + yg;
        }
      //  line(poly[n - 1].x+xg, poly[n - 1].y+yg, poly[0].x+xg, poly[0].y+yg);
        double x = poly[n - 1].x-xg, y = poly[n - 1].y-yg;
        poly[n - 1].x = x * pr.x - y * pr.y + xg;
        poly[n - 1].y = y * pr.x + x * pr.y + yg;
       
        delay(500);
    }
    getch();
    closegraph();
    return 0;
}