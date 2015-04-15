#include "main_header.h"
int rank(Matrix &a)
{
    int r=0;
    Matrix temporary(a.Rows,a.Columns,1);
    temporary.matrix=choose_matrix(U,a);
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

