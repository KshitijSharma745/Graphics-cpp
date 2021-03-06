using namespace std;

void putpixelEllipse(int cx, int cy,int x, int y,int color)
{
    putpixel(cx + x, cy - y, color);
    putpixel(cx + x, cy + y, color);
    putpixel(cx - x, cy - y, color);
    putpixel(cx - x, cy + y, color);
}

void drawEllipse(int cx, int cy, int a, int b,int color)
{
    int x = 0, y = b;
    int d = 2 * b * b + a * a - 2 * a * a * b;
    putpixelEllipse(cx, cy, x, y,color);

    while (a * a * y > x * b * b) {
        if (d > 0) {
            d += (2 * b * b * (2 * x + 3) - 4 * a * a * (y - 1));
            y--;
        }
        else {
            d += (2 * b * b * (2 * x + 3));
        }
        x++;
        putpixelEllipse(cx, cy, x, y,color);

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
        putpixelEllipse(cx, cy, x, y,color);
    }
}

