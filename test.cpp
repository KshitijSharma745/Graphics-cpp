#include<graphics.h>
#include<bits/stdc++.h>
#include<stdio.h>
#include"headers/hermiteGraph.h"
#include"cy

using namespace std;

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    vector<pair<int,int> > points= plotHermiteCurve(100,100,125,75,150,100,175,75,7);
    for(auto it: points)putpixel(it.first,it.second,7);
    // hermite curve equation   p(t)=2t3+4t2+10t+100
    // float Px,Py,Px1,Py1,Py2,Px2,Px3,Py3;
    // float t=-60,t1;
    // while(t<=60){
    //     Py=(t*t*t-3600*t)/3000;
    //     Px=t+100;
    //     t+=0.1;
    //     putpixel((int)Px, 150+(int)Py, WHITE);
    // //     putpixel((int)Px,300-(int)Py,WHITE);
    // }

    //circle drawing
/*
        float t2=-60;

        while(t2<=60){
            int Py1=(t2*t2*t2-3600*t2)/3000;
            int Px1=t2+100;
            t2+=0.1;
            putpixel((int)Px1, 150- (int)Py1, WHITE);
            putpixel((int)Px1,300-(int)Py1,WHITE);
            putpixel((int)Px1,250-(int)Py1,YELLOW);
        }    
        t=-60;

    float theta=0,th1;
int xm,ym;
    while(t<=20){
        Py=(int)(250-(t*t*t-3600*t)/3000);
        Px=(int)(t+100);
        t1=t+40;
        Py1=(int)(250-(t1*t1*t1-3600*t1)/3000);
        Px1=(int)(t1+100);
        t2=t+20;
        Py2=(t2*t2*t2-3600*t2)/3000;
        Px2=t2+100;
        t+=0.1;
        setcolor(WHITE);

    //     th1=-60;
    // while(th1<=60){
    //     Py3=(th1*th1*th1-3600*th1)/3000;
    //     Px3=th1+100;-f
    //     th1+=0.1;
    //     putpixel((int)Px3, 200- (int)Py3, WHITE);
    //     putpixel((int)Px3,300-(int)Py3,WHITE);
    // }

        circle((int)Px,(int)Py,20);
        circle((int)Px1,(int)Py1,20);

        int rcos=20*cos(theta);
        int rsin=20*sin(theta);

        theta+=0.05;
        // xm=Px+Px1;
        // ym=Py+Py1;
        // th1=(Py-Py1)/(Px-Px1);
        // xm=xm- cos(th1)/1000;
        // ym=ym- sin(th1)/1000;
        xm=Px2;
        ym=175-Py2;
        line(xm,ym,Px,Py);
        line(xm,ym,Px1,Py1);

        line(Px-rcos,Py-rsin,Px+rcos,Py+rsin);
        line(Px+rsin,Py-rcos,Px-rsin,Py+rcos);
        line(Px1-rcos,Py1-rsin,Px1+rcos,Py1+rsin);
        line(Px1+rsin,Py1-rcos,Px1-rsin,Py1+rcos);
        delay(10);
        //cleardevice();
        setcolor(BLACK);

        line(Px-rcos,Py-rsin,Px+rcos,Py+rsin);
        line(Px+rsin,Py-rcos,Px-rsin,Py+rcos);

        line(Px1-rcos,Py1-rsin,Px1+rcos,Py1+rsin);
        line(Px1+rsin,Py1-rcos,Px1-rsin,Py1+rcos);

        circle((int)Px,Py,20);
        circle((int)Px1,Py1,20);
        line(xm,ym,Px,Py);
        line(xm,ym,Px1,Py1);
    }





    delay(1000);
    */
    getch();
    closegraph();

}