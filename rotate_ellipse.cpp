#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;
void multiply(vector<vector<float> >& mat1, vector<vector<float> >& mat2, int n)
{
    float res[4][3];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 3; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            mat1[i][j] = res[i][j];
        }
    }
}
void putpixelEllipseR(int cx, int cy,int x, int y,int color,int a, float ang)
{
    vector<vector<float> > points={{x,-y,1},{x,y,1},{-x,-y,1},{-x,y,1}};
    vector<vector<float> > mat  = {{1,0,0},{0,1,0},{-a,0,1}};

    multiply(points,mat,4);
    mat = {{cos(ang),sin(ang),0},{-sin(ang),cos(ang),0},{0,0,1}};
    multiply(points,mat,4);
    mat = {{1,0,0},{0,1,0},{a,0,1}};
    multiply(points,mat,4);
    ang = (acos(-1)*(-45))/180;
    mat = {{cos(ang),sin(ang),0},{-sin(ang),cos(ang),0},{0,0,1}};
    multiply(points,mat,4);
    for(int i = 0; i<4; ++i)
    putpixel(cx + points[i][0], cy + points[i][1], color);
   
}

void drawEllipseR(int cx, int cy, int a, int b,int color,float ang)
{
    int x = 0, y = b;
    int d = 2 * b * b + a * a - 2 * a * a * b;
    
    putpixelEllipseR(cx, cy, x, y,color,a,ang);

    while (a * a * y > x * b * b) {
        if (d > 0) {
            d += (2 * b * b * (2 * x + 3) - 4 * a * a * (y - 1));
            y--;
        }
        else {
            d += (2 * b * b * (2 * x + 3));
        }
        x++;
        putpixelEllipseR(cx, cy, x, y,color,a,ang);

    }

    d = 2 * b * b * x * x + b * b + 2 * b * b * x + 2 * a * a * y * y + 2 * a * a - 4 * a * a * y - 2 * a * a * b * b;

    while (y >= 0) {
        if (d < 0) {
            d += (4 * b * b * (x + 1) - 2 * a * a * (2 * y - 3));
            x++;
        }
        else {
            d += 2 * a * a * (3 - 2 * y);
        }
        y--;
        putpixelEllipseR(cx, cy, x, y,color,a,ang);
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");
    int cx = 200, cy = 200;
    float ang = acos(-1), deg = 0;

    int a = 10, b = 5;

    while(1)
    {
        deg = 0;
        while(deg<180)
        {
            cleardevice();
            line(200,200,320,80);
            ang = (acos(-1)*deg)/180;
            drawEllipseR(cx,cy,a,b,7,ang);
            deg+=5;
            delay(100);
        }
        float theta = -45;
        ang = (acos(-1)*theta)/180;
        cx+=2*a*cos(theta);
        cy+=2*a*sin(theta);
    }
    int my; 
    cin>>my;
    closegraph();
    return 0;
}
