#include<iostream>
#include<graphics.h>
#include"headers/midParabola.h"
#include"headers/bresenhamCircle.h"


using namespace std;

int main() 
{
    int gdetect=DETECT,gmode;
    initgraph(&gdetect,&gmode," ");
    drawParabola(100,240,20,200,7);
    drawBresenhamCircle(50,150,240,4);
    getch();
    closegraph();
    return 0;
}