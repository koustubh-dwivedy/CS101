#include "main_header.h"
/**
THIS IS AN OPERATOR;
TASK: To add 2 matrices;
SYNTAX: A=B+C;
NOTE: Takes care of dimensional difference;
**/
Matrix Matrix::operator+(Matrix B)
{
    if(Rows==B.Rows && Columns==B.Columns)
    {
        Matrix a(Rows,Columns,1);
        for(int i=0;i<Rows;i++)
        {
            for(int j=0;j<Columns;j++)
            {
                a.matrix[i][j]=matrix[i][j]+B.matrix[i][j];
            }
        }
        return a;
    }
    else
    {
        cout << "Matrices cannot be Added. Dimension difference"<<endl;
        Matrix C(2);
        return C;
    }
}

