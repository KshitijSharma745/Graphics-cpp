#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;
#define i first
#define j second
int main()
{

    int n;
    cout << "Enter no. of points ";
    cin >> n;

    pair<double, double> poly[n], point[2]; //,line1[n],normal[n],fin[2];
   
    for (int i = 0; i < n; ++i)
    {
        double x, y;
        cin >> x >> y;
        poly[i] = {x, y};
    }
 
    cout << "ENTER points\n";

    for (int i = 0; i < 2; ++i)
    {
        double x, y;
        cin >> x >> y;
        point[i] = {x, y};
    }
    double p[n+7],q[n+7],t1=0.0,t2=1.0;
    for(int i = 0; i<n; ++i)
    {
        double x1,x2,y1,y2,x,y,a,b,c;
        x1 = poly[i].i, y1 = poly[i].j;
        x2 = poly[(i+1)%n].i, y2 = poly[(i+1)%n].j;
        x = poly[(i+2)%n].i, y = poly[(i+2)%n].j;
        a = y2-y1; b = -(x2-x1); c = -x1*(y2-y1)+y1*(x2-x1);
        p[i]=a*(point[1].i-point[0].i)+b*(point[1].j-point[0].j);
        q[i]=a*point[0].i+b*point[0].j+c;
        if(a*x+b*y+c>=0) p[i]=-p[i];
        else q[i]=-q[i];
        cout<<p[i]<<" "<<q[i]<<"\n";
        cout<<a<<" "<<b<<" "<<c<<"\n";
        if(p[i]==0&&q[i]<0){t1=0;t2=0;break;}
        else if(p[i]<0){t1=max(t1,(q[i]*1.0)/p[i]);}
        else if(p[i]>0)t2 = min(t2,(q[i]*1.0)/p[i]);
    }
    cout<<t1<<" "<<t2<<"\n";
    int gd = DETECT, gm;
    char drive[] = "";
    initgraph(&gd, &gm, drive);
    for(int i = 0; i<n; ++i)
    {
        line(poly[i].i,poly[i].j,poly[(i+1)%n].i,poly[(i+1)%n].j);
    }
    line(point[0].i+t1*(point[1].i-point[0].i),point[0].j+t1*(point[1].j-point[0].j),point[0].i+t2*(point[1].i-point[0].i),point[0].j+t2*(point[1].j-point[0].j));
    cin>>n;
    return 0;
}