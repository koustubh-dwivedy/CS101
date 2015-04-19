#include "main_header.h"
/**
Purpose:    to produce a matrix that will take care of various row exchanges req. in other matrices in choose_matrix(); namely Permutation();
            It is a member fuction of class Matrix.

Inputs:     Takes four arguments - 2 integer type to specify the transformation req. in specific [row][column].
                                 - Matrix m_u as it is the matrix of reference for these operations
                                 - Matrix "A" for use of its row and column size.

Outputs:    returns the resulting Permutation martrix object.
**/

Matrix Matrix::Permutation(int c, int d, Matrix m_u,Matrix A)
{
    Matrix Permu(A.Rows,A.Rows,2);//Identity matrix

    // Matrix object Permu constructed taht will take care of the row exchanges in the following lines.
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

