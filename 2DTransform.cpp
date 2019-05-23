#include<bits/stdc++.h>
using namespace std;
void multiply(vector<vector<float> >& mat1, vector<vector<float> >& mat2, int n)
{
    float res[4][3];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 3; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            mat1[i][j] = res[i][j];
        }
    }
}


