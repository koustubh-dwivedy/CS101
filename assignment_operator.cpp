#include "main_header.h"
Matrix Matrix::operator=(Matrix B)
{
    if(Rows==B.Rows && Columns==B.Columns)
    {
        for(int i=0;i<Rows;i++)
        {
            for(int j=0;j<Columns;j++)
            {
                matrix[i][j]=B.matrix[i][j];
            }
        }
    }
    else
    {
        cout << "Matrices cannot be equated. Dimension difference";
    }
}
