#include<bits/stdc++.h>
#include<graphics.h>
#define x first
#define y second
#define M 50
using namespace std;
int dot(pair<double,double> p1, pair<double,double> p2){
    return (p1.x*p2.x)+(p1.y*p2.y);
}
 int n;

 //pair<double,double> poly[M],point[2],line1[M],normal[M],fin[2];

void draw( vector<pair<double,double> >poly,int n,pair<double,double> *fin){
    // int gd = DETECT,gm;
    // char drive[] = "";
    // initgraph(&gd,&gm,drive);
    //making polygon
    // int X = getmaxx()/2;
    // int Y = getmaxy()/2;
    setcolor(WHITE);
    for(int i = 0; i<n-1; ++i){
        line(poly[i].x,poly[i].y,poly[i+1].x,poly[i+1].y);
    }
    line(poly[n-1].x,poly[n-1].y,poly[0].x,poly[0].y);
    
    setcolor(YELLOW);
    line(fin[0].x,fin[0].y,fin[1].x,fin[1].y);
    // getch();
    // closegraph();
}


void cyrus(int n, vector<pair<double,double> >poly,pair<double,double> point[]){
    
    pair<double,double> normal[n],fin[2];
    // pair<int,int> a,b,c,p1,p2,ab,bc,ca,Nab,Nbc,Nca,f1,f2;

    // a={1,1};
    // b={9,7};
    // c={7,3}; cout<<"\n";

    // p1={2,4};
    // p2={11,5};

    
   
    // cout<<"Enter no. of points ";
    // cin>>n;

   
    // for(int i = 0; i<n; ++i){
    //     int x,y;
    //     cin>>x>>y;
    //     poly[i] = {x,y};
    // }

    for(int i = 0; i<n; ++i){
        int k,l;
        if(i==n-1){
             k = poly[0].x-poly[n-1].x;
             l = poly[0].y-poly[n-1].y;
        }
        else 
        {
            k = poly[i+1].x-poly[i].x;
            l = poly[i+1].y-poly[i].y;
        }

     //   line1[i] = {k,l};

        
        normal[i] = {l,-k};
       
    
    }

    // cout<<"ENTER points\n";

    // for(int i = 0; i<2; ++i){
    //     int x,y;
    //     cin>>x>>y;
    //     point[i] = {x,y};
    // }

    int c = 0;
    double tmax = 0.0, tmin = 1.0;
    for(int i = 0; i<n; ++i){
        pair<int,int> p1,p2;
        // if(i==n-1) p1 = {point[0].x-poly[0].x,point[0].y-poly[0].y};
        // else p1 = {point[0].x-poly[i+1].x,point[0].y-poly[i+1].y};
        p1 = {point[0].x-poly[i].x,point[0].y-poly[i].y};
        p2 = {point[1].x-point[0].x,point[1].y-point[0].y};
      int t1 = dot(p1,normal[i]);
      int t2 = dot(p2,normal[i]);
    
    double t = -(t1*1.0)/(t2*1.0);
    //cout<<t1<<" "<<t2<<" "<<t<<"\n";
    if(t<=1&&t>=0){

        if(t2>0)tmin = min(tmin,t);
        else tmax = max(tmax,t);
        
        // fin[c] = {p2.x*t,p2.y*t};
        // fin[c] = {fin[c].x+point[0].x,fin[c].y+point[0].y};
        // ++c;
        // cout<<fin[c-1].x<<" "<<fin[c-1].y<<"\n";
    }

    } cout<<"\n";

    pair<int,int> p2 = {point[1].x-point[0].x,point[1].y-point[0].y};
    fin[0] = {p2.x*tmax,p2.y*tmax};
    fin[0] = {fin[0].x+point[0].x,fin[0].y+point[0].y};
    fin[1] = {p2.x*tmin,p2.y*tmin};
    fin[1] = {fin[1].x+point[0].x,fin[1].y+point[0].y};
    draw(poly,n,fin);

  //  return 0;
    
}

void cyrusbeck(int n, vector<pair<double,double> >poly,pair<double,double> point[]){
    for(int i = 0; i<n; i+=4)
    {
        vector< pair<double,double> >cpoly;
        cpoly.push_back(poly[i]);
        cpoly.push_back(poly[(i+1)%n]);
        cpoly.push_back(poly[(i+2)%n]);
        cpoly.push_back(poly[(i+3)%n]);
        cyrus(4,cpoly,point);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");
    vector< pair<double,double> >poly;
    poly.push_back({80,50});
    poly.push_back({100,200});
    poly.push_back({120,50});
    poly.push_back({120,250});
    poly.push_back({80,250});
    pair<double,double> point[] = {{50,150},{200,150}};
    //cyrusbeck(5,poly,point);
    draw(poly,5,point);
    getch();
    closegraph();
}