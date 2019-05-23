#include<bits/stdc++.h>
#include<graphics.h>
#include"headers/hermiteGraph.h"
#define i first
#define j second

using namespace std;

int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"C:\\TURBOC3\\BGI");
    int xp = 320, yp = 240;
    //1
   vector<pair<int,int> > r1 = plotHermiteCurve(5+xp,0+yp,5+xp,5+yp,5+xp,10+yp,5+xp,20+yp,1);
    //6
    vector<pair<int,int> > r6a = plotHermiteCurve(10+xp,0+yp,5+xp,5+yp,0+xp,10+yp,0+xp,15+yp,7);
    vector<pair<int,int> > r6b = plotHermiteCurve(10+xp,10+yp,20+xp,15+yp,10+xp,20+yp,0+xp,15+yp,7);
    //3
    vector<pair<int,int> > r3a = plotHermiteCurve(0+xp,0+yp,10+xp,5+yp,5+xp,7+yp,0+xp,10+yp,7);
    vector<pair<int,int> > r3b = plotHermiteCurve(0+xp,10+yp,10+xp,15+yp,5+xp,17+yp,0+xp,20+yp,7);
    //4
    vector<pair<int,int> > r4a = plotHermiteCurve(0+xp,0+yp,0+xp,2+yp,0+xp,5+yp,0+xp,10+yp,7);
    vector<pair<int,int> > r4b = plotHermiteCurve(0+xp,10+yp,2+xp,10+yp,4+xp,10+yp,10+xp,10+yp,7);
    vector<pair<int,int> > r4c = plotHermiteCurve(10+xp,0+yp,10+xp,10+yp,10+xp,15+yp,10+xp,20+yp,7);

    for(int i = 0; i<r6a.size(); ++i)r6a[i].i+=20;
    for(int i = 0; i<r6b.size(); ++i)r6b[i].i+=20;
    
    for(int i = 0; i<r3a.size(); ++i)r3a[i].i+=50;
    for(int i = 0; i<r3b.size(); ++i)r3b[i].i+=50;
    
    for(int i = 0; i<r4a.size(); ++i)r4a[i].i+=75;
    for(int i = 0; i<r4b.size(); ++i)r4b[i].i+=75;
    for(int i = 0; i<r4c.size(); ++i)r4c[i].i+=75;

    for(auto it: r1)putpixel(it.i,it.j,7);
    for(auto it: r6a)putpixel(it.i,it.j,7);
    for(auto it: r6b)putpixel(it.i,it.j,7);
    for(auto it: r3a)putpixel(it.i,it.j,7);
    for(auto it: r3b)putpixel(it.i,it.j,7);
    for(auto it: r4a)putpixel(it.i,it.j,7);
    for(auto it: r4b)putpixel(it.i,it.j,7);
    for(auto it: r4c)putpixel(it.i,it.j,7);

    getch();
    return 0;
}