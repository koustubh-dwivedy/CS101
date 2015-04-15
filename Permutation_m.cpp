#include "main_header.h"
Matrix Matrix::Permutation(int c, int d, Matrix m_u,Matrix A)
{
    Matrix Permu(A.Rows,A.Rows,2);


    if(m_u.matrix[c][d] ==0)
    {
        for(int i=c+1; i<A.Rows; i++)
        {
            if(m_u.matrix[i][d] !=0)
            {
            Permu.matrix[c][c]=0;
            Permu.matrix[c][i]=1;
            Permu.matrix[i][c]=1;
            Permu.matrix[i][i]=0;


            break;
            }

        }

    }
    return Permu;
}

