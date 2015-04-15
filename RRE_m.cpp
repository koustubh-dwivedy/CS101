#include "main_header.h"
Matrix Matrix::Row_reduced(char ch, Matrix A)
{


    Matrix m_rre(A.Rows,A.Columns,1);
    m_rre=A.choose_matrix('U',A);;


    Matrix L_rre(A.Rows,A.Rows,2);


    for(int i=A.Rows-1; i>=0; i--)
    {
        for(int j=0; j<A.Columns; j++)
        {
            if(m_rre.matrix[i][j]!=0)
            {
                int s=m_rre.matrix[i][j];
                for(int k=j; k<A.Columns; k++)

                    m_rre.matrix[i][k]=(m_rre.matrix[i][k])/s;





                // function to run from 'i'th row to A_row and check what change required and return the corresponding matrix
                for(int k=0; k<A.Rows; k++)
                    L_rre.matrix[i][k]=(L_rre.matrix[i][k])/s;

                L_rre= (Eij_rre(i,j,m_rre,A))*L_rre;
                m_rre=  (Eij_rre(i,j,m_rre,A))*m_rre;


                break;

            }


        }
    }
    switch(ch)
    {

    case 'R':
        return m_rre;// RRE form of matrix returned.
        break;
    case 'Q':
        return L_rre;//for returning the matrix that directly converts a matrix to RRE form.
        break;
    }

}

