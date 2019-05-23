
float tet[4][4] = {
    {100, 180, 0, 1},
    {180, 100, 0, 1},
    {200, 200, 0, 1},
    {150, 150, 100, 1}
};
// int main()
// {
//     init();
//     float point[4]={250,250,0,1};
//     //draw_prism(0,1,2,2,point,tet);
//     while(1)
//     {   cleardevice();
//         draw_prism(0,3,1,1,point,tet);
//         draw_prism(0,2,3,3,point,tet);
//         draw_prism(1,3,2,2,point,tet);
//         char n; cin>>n;
//         float ang = (10*acos(-1))/180.0;
//         if(n=='x'||n=='X')
//             rotX(tet,4,cos(ang),sin(ang));
//         else if(n=='y'||n=='Y')
//             rotY(tet,4,cos(ang),sin(ang));
//         else if(n=='z'||n=='Z')
//             rotZ(tet,4,cos(ang),sin(ang));
//         else break;
//     }
    
//     closegraph();
// }