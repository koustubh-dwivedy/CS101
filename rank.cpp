#include "main_header.h"
<<<<<<< HEAD
int Matrix::rank(Matrix &a)
{
    int r=0;
    Matrix temporary(a.Rows,a.Columns,1);
    temporary=choose_matrix('U',a);
=======
int rank(Matrix &a)
{
    int r=0;
    Matrix temporary(a.Rows,a.Columns,1);
    temporary.matrix=choose_matrix(U,a);
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee
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

