#include<bits/stdc++.h>
#include<graphics.h>
#define i first
#define j second
using namespace std;

bool isinside(vector<pair<float,float> > poly,pair<float,float> point, int n)
{   
    bool b = true;
    for(int i = 0; i<n; ++i)
    {
        int x1 = poly[i].i, y1 = poly[i].j;
        int x2 = poly[(i+1)%n].i, y2 = poly[(i+1)%n].j;
        int x3 = poly[(i+2)%n].i, y3 = poly[(i+2)%n].j;
        int a = y2-y1, b = -(x2-x1), c = -x1*(y2-y1)+y1*(x2-x1);
        if(((a*point.i+b*point.j+c)*(a*x3+b*y3+c))>=0) continue;
        b = false; break;
    }
    return b;
}
void seedFill(int x,int y, vector<pair<float,float> > poly, int n) {
    cout<<"("<<x<<","<<y<<") "<<getpixel(x,y)<<endl;
    pair<float,float> point = {(float)x,(float)y};
    if(!isinside(poly,point,n))return;
    // if(x>=420 || x<=220 || y>=300 || y<=100)
    //     return;
    if(getpixel(x,y)==2)
        return;
    putpixel(x,y,GREEN);
    seedFill(x,y+1,poly,4);
    seedFill(x,y-1,poly,4);
    seedFill(x+1,y,poly,4);
    seedFill(x-1,y,poly,4);
    seedFill(x+1,y+1,poly,4);
    seedFill(x+1,y-1,poly,4);
    seedFill(x-1,y+1,poly,4);
    seedFill(x-1,y-1,poly,4);
}

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"C:\\TURBOC3\\BGI");
    setcolor(RED);
    rectangle(220,100,420,300);
    vector<pair<float,float> > poly;
    poly.push_back({220,100});
    poly.push_back({420,100});
    poly.push_back({420,300});
    poly.push_back({220,300});
    setcolor(WHITE);
    seedFill(320,200,poly,4);
    getch();
    return 0;
}