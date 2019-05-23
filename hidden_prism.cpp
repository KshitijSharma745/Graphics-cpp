int dot(float n[4], float p[4])
{
    float s = 0.0;
    s = n[0]*p[0]+n[1]*p[1]+n[2]*p[2];
    if(s<0)return -1;
    if(s>0)return 1;
    return 0;
}
int check(int a, int b, int c, float point[4], float prism[][4])
{
    float n1[4]={prism[b][0]-prism[a][0],prism[b][1]-prism[a][1],prism[b][2]-prism[a][2],1};
    float n2[4]={prism[c][0]-prism[a][0],prism[c][1]-prism[a][1],prism[c][2]-prism[a][2],1};
    float n[4]={n1[1]*n2[2]-n1[2]*n2[1],-n1[0]*n2[2]+n1[2]*n2[0],n1[0]*n2[1]-n1[1]*n2[0],1};
    float d[4]={(prism[a][0]+prism[b][0]+prism[c][0])/3.0,(prism[a][1]+prism[b][1]+prism[c][1])/3.0,(prism[a][2]+prism[b][2]+prism[c][2])/3.0,1};
    float p[4]={d[0]-point[0],d[1]-point[1],d[2]-point[2],1};
    return dot(n,p);
}
int draw_prism(int a, int b, int c, int d, float point[4],float prism[][4])
{   
    int ch = check(a,b,c,point,prism);
    if(ch>=0) setlinestyle(0,0,1);
    else setlinestyle(3,0,1);
    line(prism[a][0],prism[a][1],prism[b][0],prism[b][1]);
    line(prism[b][0],prism[b][1],prism[c][0],prism[c][1]);
    line(prism[c][0],prism[c][1],prism[d][0],prism[d][1]);
    line(prism[d][0],prism[d][1],prism[a][0],prism[a][1]);
}
// int main()
// {
//     init();
//        float point[4]={120,120,0,1};
//             float prism[8][4] = {
//             {0, 0, 0, 1},
//             {90, 0, 0, 1},
//             {90, 90, 0, 1},
//             {0, 90, 0, 1},
//             {30, 30, 90, 1},
//             {60, 30, 90, 1},
//             {60, 60, 90, 1},
//             {30, 60, 90, 1},
//         };
//     draw_prism(0,1,2,3,point,prism);
//     draw_prism(4,7,6,5,point,prism);
//     draw_prism(1,5,6,2,point,prism);
//     draw_prism(0,4,5,1,point,prism);
//     draw_prism(0,3,7,4,point,prism);
//     draw_prism(3,2,6,7,point,prism);
//     int n; cin>>n;
//     closegraph();
// }