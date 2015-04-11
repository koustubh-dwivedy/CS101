#include "main_header.h"
bool Matrix::operator==(Matrix A)
{
    if(Rows==A.Rows && Columns==A.Columns)
    {
        double counter=0;
        for(int i=0;i<A.Rows;i++)
        {
            for(int j=0;j<A.Columns;j++)
            {
                if(matrix[i][j]==A.matrix[i][j]) counter = counter+1;
            }
        }
        if(counter == A.Columns*A.Rows) return TRUE;
    }
    else return FALSE;
}
