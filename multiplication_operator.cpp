#include "main_header.h"
/**
THIS IS AN OPERATOR;
TASK: To multiply 2 matrices;
SYNTAX: A=B*C;
NOTE: Takes care of dimensional difference;
**/
Matrix Matrix::operator*(Matrix B)
{
    if(Columns==B.Rows)
    {
        Matrix a(Rows,B.Columns,1);
        double sum=0;
        for(int i=0; i<Rows; i++)
        {
            for(int j=0; j<B.Columns; j++)
            {
                sum=0;
                for(int a=0; a<Columns; a++)
                {
                    sum=sum+matrix[i][a]*B.matrix[a][j];
                }
                a.matrix[i][j]=sum;
            }
        }
        return a;
    }
    else
    {
        cout << "Matrices cannot be multiplied. Dimension difference"<<endl;
        Matrix C(2);
        return C;
    }
}
