#include "main_header.h"
/**
This is the code for constructing the matrix (CONSTRUCTORS OF Matrix class);
TASK: To construct matrices;
SYNTAX:
    //
        Argument    Result
        (n,m,1)     n x m null matrix
        (n,n,2)     n x n Identity matrix
    //
EXAMPLE CODE<->
Martix A(n,m,1); // Constructs n x m null matrix
Matrix B(n,n,2); // Constructs n x n null matrix
**/
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
