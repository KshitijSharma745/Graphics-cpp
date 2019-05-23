#include<bits/stdc++.h>
#include<graphics.h>
#include"headers/hermiteGraph.h"
#define i first
#define j second

using namespace std;
void multiply(vector<vector<float> >& mat1, vector<vector<float> >& mat2, int n)
{
    float res[n][4];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 4; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            mat1[i][j] = res[i][j];
        }
    }
}
void rotX(vector<vector<float> >& mat1, int n, float cs, float sn)
{
    vector<vector<float> > rot;
    for(int i = 0; i<3; ++i)for(int j = 0; j<3; ++j){ if(i==j)rot[i][j]=1; else rot[i][j]=0;}
    rot[1][1]=cs; rot[1][2]=sn; rot[2][1]=-sn; rot[2][2]=cs;
    multiply(mat1,rot,n);
}
void rotY(vector<vector<float> >& mat1, int n, float cs, float sn)
{
    vector<vector<float> > rot;
    for(int i = 0; i<4; ++i)for(int j = 0; j<4; ++j){ if(i==j)rot[i][j]=1; else rot[i][j]=0;}
    rot[0][0]=cs; rot[0][2]=-sn; rot[2][0]=sn; rot[2][2]=cs;
    multiply(mat1,rot,n);
}

pair<int,int> rotate(pair<int,int> p, double angle)
{
    float cosA = cos(angle);
    float sinA = sin(angle);
    pair<int,int> ans;
    ans.i = p.i*cosA - p.j*sinA;
    ans.j = p.i*sinA + p.j*cosA;
    return ans;
}
int main() {
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode,"C:\\TURBOC3\\BGI");
    int xp = 500, yp = 200;
//K
    vector<pair<int,int> > k1 = plotHermiteCurve(0+xp,5+yp,3+xp,2+yp,3+xp,2+yp,5+xp,0+yp,1);
    vector<pair<int,int> > k2 = plotHermiteCurve(5+xp,0+yp,5+xp,4+yp,5+xp,10+yp,5+xp,20+yp,1);
    vector<pair<int,int> > k3 = plotHermiteCurve(0+xp,15+yp,4+xp,18+yp,4+xp,18+yp,5+xp,20+yp,1);
    vector<pair<int,int> > k4 = plotHermiteCurve(5+xp,10+yp,10+xp,5+yp,10+xp,5+yp,15+xp,0+yp,1);
    vector<pair<int,int> > k5 = plotHermiteCurve(5+xp,10+yp,10+xp,15+yp,10+xp,15+yp,15+xp,20+yp,1);
//s
    vector<pair<int,int> > s1 = plotHermiteCurve(15+xp,20+yp,20+xp,17+yp,22+xp,13+yp,20+xp,10+yp,1);
    vector<pair<int,int> > s2 = plotHermiteCurve(20+xp,10+yp,18+xp,14+yp,20+xp,17+yp,25+xp,20+yp,1);
    vector<pair<int,int> > s3 = plotHermiteCurve(15+xp,20+yp,17+xp,20+yp,18+xp,20+yp,25+xp,20+yp,1);
//h
    vector<pair<int,int> > h1 = plotHermiteCurve(0+xp,0+yp,0+xp,5+yp,0+xp,10+yp,0+xp,20+yp,1);
    vector<pair<int,int> > h2 = plotHermiteCurve(0+xp,20+yp,5+xp,15+yp,6+xp,17+yp,10+xp,20+yp,1);
//i
    vector<pair<int,int> > i1 = plotHermiteCurve(5+xp,10+yp,6+xp,11+yp,5+xp,12+yp,4+xp,11+yp,1);
    vector<pair<int,int> > i2 = plotHermiteCurve(0+xp,20+yp,5+xp,15+yp,6+xp,17+yp,10+xp,20+yp,1);
//t
    vector<pair<int,int> > t1 = plotHermiteCurve(5+xp,0+yp,5+xp,15+yp,5+xp,17+yp,5+xp,20+yp,1);
    vector<pair<int,int> > t2 = plotHermiteCurve(0+xp,10+yp,5+xp,10+yp,6+xp,10+yp,10+xp,10+yp,1);
//i
    vector<pair<int,int> > i11 = plotHermiteCurve(0+xp,6+yp,3+xp,7+yp,4+xp,9+yp,5+xp,11+yp,1);
    vector<pair<int,int> > i12 = plotHermiteCurve(0+xp,10+yp,0+xp,12+yp,0+xp,18+yp,0+xp,20+yp,1);
//j
    vector<pair<int,int> > j1 = plotHermiteCurve(5+xp,10+yp,5+xp,15+yp,5+xp,20+yp,5+xp,30+yp,1);
    vector<pair<int,int> > j2 = plotHermiteCurve(5+xp,30+yp,0+xp,25+yp,5+xp,20+yp,10+xp,17+yp,1);
    vector<pair<int,int> > j3 = plotHermiteCurve(4+xp,4+yp,5+xp,5+yp,5+xp,4+yp,6+xp,6+yp,1);

    int h = 30;
    int ia = h+10;
    int t = ia+10;
    int ib = t+10;
    int j = ib+5;
    double ang = (acos(-1)*10)/180;
    vector<vector<float> > rot;
    vector<pair<int,int> > big;

    for(int i = 0; i<k1.size(); ++i){big.push_back(k1[i]);}
    for(int i = 0; i<k2.size(); ++i){big.push_back(k2[i]);}
    for(int i = 0; i<k3.size(); ++i){big.push_back(k3[i]);}
    for(int i = 0; i<k4.size(); ++i){big.push_back(k4[i]);}
    for(int i = 0; i<k5.size(); ++i){big.push_back(k5[i]);}

    for(int i = 0; i<s1.size(); ++i){big.push_back(s1[i]);}
    for(int i = 0; i<s2.size(); ++i){big.push_back(s2[i]);}

    for(int i = 0; i<h1.size(); ++i){h1[i].i+=h;big.push_back(h1[i]);}
    for(int i = 0; i<h2.size(); ++i){h2[i].i+=h;big.push_back(h2[i]);}

    for(int i = 0; i<i1.size(); ++i){i1[i].i+=ia;big.push_back(i1[i]);}
    for(int i = 0; i<i2.size(); ++i){i2[i].i+=ia;big.push_back(i2[i]);}

    for(int i = 0; i<t1.size(); ++i){t1[i].i+=t;big.push_back(t1[i]);}
    for(int i = 0; i<t2.size(); ++i){t2[i].i+=t;big.push_back(t2[i]);}

    for(int i = 0; i<i11.size(); ++i){i11[i].i+=ib;big.push_back(i11[i]);}
    for(int i = 0; i<i12.size(); ++i){i12[i].i+=ib;big.push_back(i12[i]);}

    for(int i = 0; i<j1.size(); ++i){j1[i].i+=j;big.push_back(j1[i]);}
    for(int i = 0; i<j2.size(); ++i){j2[i].i+=j;big.push_back(j2[i]);}
    for(int i = 0; i<j3.size(); ++i){j3[i].i+=j;big.push_back(j3[i]);}

   // vector<pair<double,double> > mat = {{cos(ang),sin(ang)},{-sin(ang),cos(ang)}};
//    vector<vector<float> > ans;
//    for(int i = 0; i<big.size(); ++i)
//    {
//        ans[i].push_back(big[i].i);
//        ans[i].push_back(big[i].j);
//        ans[i].push_back(0);
//        ans[i].push_back(1);
//    }
    double deg = 0;
    // vector<vector<float> > mat = {    {1, 0, 0, 0},
    //                             {0, (float)cos(ang), (float)(-sin(ang)), 0},
    //                             {0, (float)sin(ang), (float)cos(ang), 0},
    //                             {0, 0, 0, 1}    };
//     while(deg<360)
//     {
//       ang = (acos(-1)*deg)/180;
//        multiply(ans,mat,ans.size());
//        setcolor(WHITE);
//         for(int i = 0; i<ans.size(); ++i)
//         {
//             putpixel(ans[i][0],ans[i][j],7);
//         }
//         setcolor(BLACK);
//         delay(100);
//         for(int i = 0; i<ans.size(); ++i)
//         {
//             putpixel(ans[i][0],ans[i][j],7);
//         }
//     deg+=5;
//    }
    
    //multiply(points,mat,4);
   
    for(auto it: k1)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: k2)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: k3)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: k4)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: k5)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: s1)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: s2)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: s3)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: h1)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: h2)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: i1)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: i2)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: t1)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: t2)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: i11)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: i12)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: j1)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: j2)putpixel(it.i,it.j,7);
    delay(10);
    for(auto it: j3)putpixel(it.i,it.j,7);

    int cnt = 11;
    getch();
    cleardevice();
    while(deg<360&&cnt--)
    {
        ang = (acos(-1)*deg)/180;
        //setcolor(WHITE);
        for(int i = 0; i<big.size(); ++i)
        {
            big[i] = rotate(big[i],ang);
            putpixel(big[i].i,big[i].j,7);
        }
       // setcolor(BLACK);
        delay(500);
        for(int i = 0; i<big.size(); ++i)
        {
            putpixel(big[i].i,big[i].j,0);
        }
        deg+=0.5;
    }
    cout<<"EXIT";

    getch();
    return 0;
}