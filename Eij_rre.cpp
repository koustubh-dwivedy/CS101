#include "main_header.h"
/**
Purpose:    to produce a matrix that will take care that all elements below and above the pivot are made zero in m_rre and multiplied to other matrices in Row_reduced(); namely Eij_rre();
            It is a member fuction of class Matrix.

Inputs:     Takes four arguments - 2 integer type to specify the operation req. in specific [row][column] of pivot.
                                 - Matrix mrreu as it is the matrix of reference for these operations
                                 - Matrix "A" for use of its row and column size.

Outputs:    returns the resulting martrix object that performs the Row operations req. at every step.
**/
Matrix Matrix::Eij_rre(int c, int d, Matrix m_rre,Matrix A)
{
    Matrix E_ij(A.Rows,A.Rows,2);//Identity
//following code make element above pivot=0
    for(int i=c-1;i>=0; i--)
        E_ij.matrix[i][c]= -(m_rre.matrix[i][d]);


    return  E_ij;

}

