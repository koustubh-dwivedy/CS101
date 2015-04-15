#include "main_header.h"
Matrix Matrix::Eij_rre(int c, int d, Matrix m_u,Matrix A)
{
    Matrix E_ij(A.Rows,A.Rows,2);

    for(int i=c-1;i>=0; i--)
        E_ij.matrix[i][c]= -(m_u.matrix[i][d]);


    return  E_ij;

}

