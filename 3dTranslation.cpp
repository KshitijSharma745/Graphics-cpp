#include <iostream> 
#include<math.h>

using namespace std; 


void multiply(int mat1[3][4],  
              int mat2[4][3],  
              int res[3][3]) 
{ 
    int i, j, k; 
    for (i = 0; i < 3; i++) 
    { 
        for (j = 0; j < 3; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < 4; k++) 
                res[i][j] += mat1[i][k] *  
                             mat2[k][j]; 
        } 
    } 
} 
void print(int res[3][3]){
    cout << "Result matrix is \n"; 
    for (int i = 0; i < 3; i++) 
    { 
        for (int j = 0; j < 3; j++) 
        cout << res[i][j] << " "; 
        cout << "\n"; 
    } 
}
void rotate(int mat[4][4], double ang, int type, int res[4][4]){
    int cos_ang = cos(ang);
    int sin_ang = sin(ang);
    
    switch(type){
        case 1: res[1][1] = cos_ang;
                res[1][2] = -sin_ang;
                res[2][1] = sin_ang;
                res[2][2] = cos_ang;
                break;
        case 2: res[0][0] = cos_ang;
                res[0][2] = sin_ang;
                res[2][0] = -sin_ang;
                res[2][2] = cos_ang;
                break;
        case 3: res[0][0] = cos_ang;
                res[0][1] = -sin_ang;
                res[1][0] = sin_ang;
                res[1][1] = cos_ang;
                break;
    }
    
}
int main() 
{ 
    int i, j; 
    int res[3][3]; // To store result 
    int A[3][4] = {{2, 3, 4, 1}, 
                    {8, 5, 10, 1}, 
                    {-5, 10, 5, 1}}; 
    int translate[3] = {2,3,4};
    int B[4][3] = {{1, 0, 0}, 
                    {0, 1, 0}, 
                    {0, 0, 1}, 
                    {-translate[0], -translate[1], -translate[2]}}; 
  
    multiply(A, B, res); 
  print(res);
  for(int i = 0; i<3; ++i){
      for(int j = 0; j<3; ++j){
          
      }
  }
    // int C[4][4]={{1,0,0,0},
    //       {0, 1, 0,0},
    //       {0, 0,1, 0},
    //       {0,0,0,1}};
    // double ang = (double)(3-14)/(double)4;
    // rotate(res, ang, 1, C);

    // print(C);
  
    return 0; 
} 