#include "main_header.h"
/**
Purpose:    to produce a matrix that will take care that all elements below the pivot are made zero in m_u and multiplied to other matrices in choose_matrix(); namely Eij();
            It is a member fuction of class Matrix.

Inputs:     Takes four arguments - 2 integer type to specify the operation req. in specific [row][column] of pivot.
                                 - Matrix m_u as it is the matrix of reference for these operations
                                 - Matrix "A" for use of its row and column size.

Outputs:    returns the resulting martrix object that performs the Row operations req. at every step.
**/

Matrix Matrix::Eij(int c, int d, Matrix m_u,Matrix A)
{
    Matrix E_ij(A.Rows,A.Rows,2);//Identity matrix

    // takes care that all elements below the pivot are made zero.and produces such a matrix req..
    for(int i=c+1;i<A.Rows; i++)
        E_ij.matrix[i][d]=-(m_u.matrix[i][d]/m_u.matrix[c][d]);

    return  E_ij;// returns then req. amtrix
}
