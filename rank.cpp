/*
*Task: To find rank of a matrix
Input Type: Object of class Matrix
Output Type: Since rank is always an int, the output type is int
Algorithm: The first non-zero element in the echelon form is a pivot.
            Rank=No. of pivots
*/
#include "main_header.h"
int rank(Matrix a)
{
    int r=0;//r=rank
    Matrix temporary(a.Rows,a.Columns,1);//temporary stores the echelon form of input matrix 'a'
    temporary=a.choose_matrix('U',a);
    for(int i=0; i<temporary.Rows;i++)
    {
        for(int j=0; j<temporary.Columns;j++)
        {
            if(temporary.matrix[i][j]!=0)
            {
                r++;
                break;
            }
        }
    }
    return r;
}

