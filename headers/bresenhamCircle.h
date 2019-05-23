void plotPixelForCircle(int x,int y,int xc,int yc,int color) {
    putpixel(xc+x,yc-y,color);
    putpixel(xc+x,yc+y,color);
    putpixel(xc-x,yc-y,color);
    putpixel(xc-x,yc+y,color);
    putpixel(xc+y,yc+x,color);
    putpixel(xc+y,yc-x,color);
    putpixel(xc-y,yc-x,color);
    putpixel(xc-y,yc+x,color);
}

void drawBresenhamCircle(int r,int xc,int yc,int color) {
    int d=3-(2*r), x = 0, y = r;
    plotPixelForCircle(x,y,xc,yc,color);
    while(x<=y) {
        if(d<0) {
            d+=4*x+6;
            x++;
        } else {
            d+=4*(x-y)+10;
            x++;
            y--;
        }
        plotPixelForCircle(x,y,xc,yc,color);
    }
}
