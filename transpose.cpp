#include"main_header.h"
Matrix transpose(Matrix &a)
{
    Matrix t(a.Columns,a.Rows,1);
    for(int i=0;i<a.Rows;i++)
    {
        for(int j=0;j<a.Columns;j++)
        {
            t.matrix[j][i]=a.matrix[i][j];
        }
    }
    return t;
}
