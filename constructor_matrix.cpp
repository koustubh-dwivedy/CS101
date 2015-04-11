#include "main_header.h"
Matrix::Matrix(int a,int b,int c)
{
    if(c==1)
    {
        Rows=a;
        Columns=b;
        matrix.resize(Rows);
        for(int i=0; i<Rows; i++)
        {
            matrix[i].resize(Columns);
        }
    }
    else if(a==b && c==2)
    {
        Rows=a;
        Columns=b;
        matrix.resize(Rows);
        for(int i=0; i<Rows; i++)
        {
            matrix[i].resize(Columns);
        }
        for(int i=0;i<Rows;i++)
        {
            for(int j=0;j<Columns;j++)
            {
                if(i==j) matrix[i][j]=1;
                else if(i!=j) matrix [i][j]=0;
            }
        }
    }

}
