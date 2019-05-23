#include<iostream>
#include<graphics.h>
using namespace std;
#define i first
#define j second
void gen_polycode(pair<double, double> poly[], int n, int polycode[])
{
    for(int i = 0; i<n; ++i)polycode[i]=i+1;
}

int gencode(pair<double,double> point,pair<double, double> poly[], int n, int polycode[])
{   
    int code = 0x0;
    for(int i = 0; i<n; ++i)
    {   
        double x1,x2,y1,y2,x3,y3,a,b,c,x,y;
        x1 = poly[i].i, y1 = poly[i].j;
        x2 = poly[(i+1)%n].i, y2 = poly[(i+1)%n].j;
        x3 = poly[(i+2)%n].i, y3 = poly[(i+2)%n].j;
        x = point.i; y = point.j;
        a = y2-y1; b = -(x2-x1); c = -x1*(y2-y1)+y1*(x2-x1);
        if((a*x+b*y+c)*(a*x3+b*y3+c)<0)code|=polycode[i];
    }
    return code;
}
void clipline(pair<double, double> p1,, pair<double, double> poly[], int n, int polycode[]){
    int code1 = gencode(p1);
    int code2 = gencode(p2);
    double x,y;
    if(code1!=0){
        x = p1.x;
        y = p1.y;
        if((code1&LEFT)==1){
            x = xmin;
            y = p1.y + ((p2.y-p1.y)*(xmin-p1.x)*1.0)/(p2.x-p1.x);
        }
        else if((code1&BOTTOM)==1){
            x = p1.x + ((p2.x-p1.x)*(ymin-p1.y)*1.0)/(p2.y-p1.y);
            y = ymin;
        }
        else if((code1&RIGHT)==1){
            x = xmax;
            y = p1.y + ((p2.y-p1.y)*(xmax-p1.x)*1.0)/(p2.x-p1.x);
        }
        else if((code1&TOP)==1){
            x = p1.x + ((p2.x-p1.x)*(ymax-p1.y)*1.0)/(p2.y-p1.y);
            y = ymax;
        }
        p1.x = x;
        p1.y = y;
    }
    else if(code2!=0){
        x = p2.x;
        y = p2.y;
        if((code2&LEFT)==1){
            x = xmin;
            y = p1.y + ((p2.y-p1.y)*(xmin-p1.x)*1.0)/(p2.x-p1.x);
        }
        else if((code2&BOTTOM)==1){
            x = p1.x + ((p2.x-p1.x)*(ymin-p1.y)*1.0)/(p2.y-p1.y);
            y = ymin;
        }
        else if((code2&RIGHT)==1){
            x = xmax;
            y = p1.y + ((p2.y-p1.y)*(xmax-p1.x)*1.0)/(p2.x-p1.x);
        }
        else if((code2&TOP)==1){
            x = p1.x + ((p2.x-p1.x)*(ymax-p1.y)*1.0)/(p2.y-p1.y);
            y = ymax;
        }
        p2.x = x;
        p2.y = y;
    }

}
void clip(pair<double, double> point[2], pair<double, double> poly[], int n, int polycode[])
{   
    pair<double, double>  p1 = point[0], p2 = point[1];

    int done = 0,f = 0;
    do{ 
        int code1 = gencode(p1,poly,n,polycode);
        int code2 = gencode(p2,poly,n,polycode);
        if((code1&code2)!=0){done=1;}
        if((code1&code2)==0&&(code1|code2)==0){done = 1; f=1;}
        if((code1&code2)==0&&(code1|code2)!=0)clipline();

    }while(done!=1);
    if(f==1)
    line(p1.i,p1.j,p2.i,p2.j);
}
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


    return 0;
}