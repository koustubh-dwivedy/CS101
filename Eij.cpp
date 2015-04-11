#include "main_header.h"w
Matrix Matrix::Eij(int c, int d, Matrix m_u,Matrix A)
{
    Matrix E_ij(A.Rows,A.Rows,2);

    for(int i=c+1;i<A.Rows; i++)
        E_ij.matrix[i][d]=-(m_u.matrix[i][d]/m_u.matrix[c][d]);

    return  E_ij;
}
