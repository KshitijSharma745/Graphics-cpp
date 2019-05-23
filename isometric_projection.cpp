float const cube_len = 50;
float cube[8][4] = {
    {0, 0, 0, 1},
    {cube_len, 0, 0, 1},
    {cube_len, cube_len, 0, 1},
    {0, cube_len, 0, 1},
    {0, 0, cube_len, 1},
    {cube_len, 0, cube_len, 1},
    {cube_len, cube_len, cube_len, 1},
    {0, cube_len, cube_len, 1},
};
float A = (35.264 * 3.14) / 180, B = (45 * 3.14) / 180;
float t[4][4] = {{cos(B), sin(B) * sin(A), sin(B) * cos(A), 0},
                 {0, cos(A), -sin(A), 0},
                 {-sin(B), cos(B) * sin(A), cos(A) * cos(B), 0},
                 {0, 0, 0, 1}};

void multiply(float mat1[][4], float mat2[4][4], int n)
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
void translate(float mat1[][4], int n, int x, int y, int z)
{
   float mat[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{x,y,z,1}};
   multiply(mat1,mat,n);
}
void shear(float mat1[][4], int n, int sx, int sy, int sz)
{
    float mat[n][4] = {{sx,0,0,0},{0,sy,0,0},{0,0,sz,1},{0,0,0,1}};
    multiply(mat1,mat,n);
}
void rotX(float mat1[][4], int n, float cs, float sn)
{
    float rot[4][4];
    for(int i = 0; i<4; ++i)for(int j = 0; j<4; ++j){ if(i==j)rot[i][j]=1; else rot[i][j]=0;}
    rot[1][1]=cs; rot[1][2]=sn; rot[2][1]=-sn; rot[2][2]=cs;
    multiply(mat1,rot,n);
}
void rotY(float mat1[8][4], int n, float cs, float sn)
{
    float rot[4][4];
    for(int i = 0; i<4; ++i)for(int j = 0; j<4; ++j){ if(i==j)rot[i][j]=1; else rot[i][j]=0;}
    rot[0][0]=cs; rot[0][2]=-sn; rot[2][0]=sn; rot[2][2]=cs;
    multiply(mat1,rot,n);
}
void rotZ(float mat1[8][4], int n, float cs, float sn)
{
    float rot[4][4];
    for(int i = 0; i<4; ++i)for(int j = 0; j<4; ++j){ if(i==j)rot[i][j]=1; else rot[i][j]=0;}
    rot[0][0]=cs; rot[0][1]=sn; rot[1][0]=-sn; rot[1][1]=cs;
    multiply(mat1,rot,n);
}
void front(float cube[8][4], int xx, int yy)
{
    for (int i = 0; i < 4; ++i)
    {
        line(xx + cube[i][0], yy - cube[i][1], xx + cube[(i + 1) % 4][0], yy - cube[(i + 1) % 4][1]);
        line(xx + cube[i + 4][0], yy - cube[i + 4][1], xx + cube[4 + (i + 1) % 4][0], yy - cube[4 + (i + 1) % 4][1]);
        line(xx + cube[i][0], yy - cube[i][1], xx + cube[i + 4][0], yy - cube[i + 4][1]);
    }
}
void side(float cube[8][4], int xx, int yy)
{
    for (int i = 0; i < 4; ++i)
    {
        line(xx + cube[i][2], yy - cube[i][1], xx + cube[(i + 1) % 4][2], yy - cube[(i + 1) % 4][1]);
        line(xx + cube[i + 4][2], yy - cube[i + 4][1], xx + cube[4 + (i + 1) % 4][2], yy - cube[4 + (i + 1) % 4][1]);
        line(xx + cube[i][2], yy - cube[i][1], xx + cube[i + 4][2], yy - cube[i + 4][1]);
    }
}
void top(float cube[8][4], int xx, int yy)
{
    for (int i = 0; i < 4; ++i)
    {
        line(xx + cube[i][0], yy - cube[i][2], xx + cube[(i + 1) % 4][0], yy - cube[(i + 1) % 4][2]);
        line(xx + cube[i + 4][0], yy - cube[i + 4][2], xx + cube[4 + (i + 1) % 4][0], yy - cube[4 + (i + 1) % 4][2]);
        line(xx + cube[i][0], yy - cube[i][2], xx + cube[i + 4][0], yy - cube[i + 4][2]);
    }
}
void front2(float cube[8][4])
{
    for (int i = 0; i < 4; ++i)
    {
        line(cube[i][0],cube[i][1],cube[(i + 1) % 4][0],cube[(i + 1) % 4][1]);
        line(cube[i + 4][0],cube[i + 4][1],cube[4 + (i + 1) % 4][0],cube[4 + (i + 1) % 4][1]);
        line(cube[i][0],cube[i][1],cube[i + 4][0],cube[i + 4][1]);
    }
}
void isometric(float cube1[][4], int n)
{
   
    multiply(cube1, t, n);
    //front(cube1);
    //side(cube1);
     //top(cube1);

}

// int main()
// {
//     init();
//     float cube1[8][4],cube2[8][4];
//     for (int i = 0; i < 8; ++i)
//         for (int j = 0; j < 4; ++j)
//             cube1[i][j] = cube[i][j];
//     char n;
//     isometric(cube1,8);
//     for (int i = 0; i < 8; ++i)
//         for (int j = 0; j < 4; ++j)
//             cube2[i][j] = cube1[i][j];

//     for (int i = 0; i < 8; ++i)
//         for (int j = 0; j < 3; ++j)
//             cube2[i][j] += 250;

//     while(1)
//     {   cleardevice();
//         int X = getmaxx(); int Y = getmaxy();
//         line(0,Y/2,X,Y/2);
//         line(X/3,0,X/3,Y);
//         line((2*X)/3,0,(2*X)/3,Y);
//         front(cube1,ox1,oy1);
//         side(cube1,ox2,oy1);
//         top(cube1,ox3,oy1);
        
//         cin>>n;
//         float ang = (10*acos(-1))/180.0;
//         // if(n=='x'||n=='X')
//         //     rotX(cube2,8,cos(ang),sin(ang));
//         // else if(n=='y'||n=='Y')
//         //     rotY(cube2,8,cos(ang),sin(ang));
//         // else if(n=='z'||n=='Z')
//         //     rotZ(cube2,8,cos(ang),sin(ang));
//         // else break;
//         if(n=='0')break;
//         rotY(cube1,8,cos(ang),sin(ang));
//     }        
//     closegraph();
//     return 0;
// }
