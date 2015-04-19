#include "main_header.h"
/**
TASK: To find the square root of sum of squares of elements of a 1xn or nx1 matrix;
INPUT: Any Matrix A;
RETURN TYPE: double;
NOTE: The code automatically checks if the inputted matrix is avlid or not;
**/
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

/**
Input: Matrix A;
Output: Transformed matrix B;
**/
Matrix Matrix::transpose(Matrix A)
{
    Matrix B(A.Columns,A.Rows,2);
    for(int i=0; i<A.Rows; i++)
    {
        for(int j=0; j<A.Columns; j++)
        {
            B.matrix[j][i]=A.matrix[i][j];
        }
    }
    return B;
}


