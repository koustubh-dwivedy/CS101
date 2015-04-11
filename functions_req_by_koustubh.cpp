#include "main_header.h"
double Matrix::mod(Matrix A)
{
    if(A.Columns==1)
    {
        double buffer=0;
        for(int i=0; i<A.Rows; i++)
        {
            buffer = buffer + (A.matrix[i][0])*(A.matrix[i][0]);
        }
        return sqrt(buffer);
    }
    else if(A.Rows==1)
    {
        double buffer=0;
        for(int i=0; i<A.Columns; i++)
        {
            buffer = buffer + (A.matrix[0][i])*(A.matrix[0][i]);
        }
        return sqrt(buffer);
    }
    else
    {
        cout << "Mod cannot be operated on a non colummn/row matrix";
        return 0;
    }
}
Matrix Matrix::transpose(Matrix A)
{
    Matrix B(2);
    B.Columns=A.Rows;
    B.Rows=A.Columns;
    for(int i=0; i<A.Rows; i++)
    {
        for(int j=0; j<A.Columns; j++)
        {
            B.matrix[j][i]=A.matrix[i][j];
        }
    }
    return B;
}
