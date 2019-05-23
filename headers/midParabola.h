void drawParabola(int xc, int yc, float a, float limit, int color)
{
    float d,x,y;
    d=1-2*(a);
    x=y=0;
    while(y<=2*a)
    {
        if(d<0)d+=2*y+3;
        else{ d+=2*y+3-4*a; x++;}
        putpixel(x+xc,y+yc,color);
        putpixel(x+xc,-y+yc,color);
        y++;
    }
    while(x<limit+xc)
    {
        if(d>0)d+=-4*a;
        else{ d+=2*y+2-4*a; y++;}
        putpixel(x+xc,y+yc,color);
        putpixel(x+xc,-y+yc,color);
        x++;
    }
}