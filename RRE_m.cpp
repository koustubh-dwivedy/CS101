#include "main_header.h"
/**
Purpose:    to produce a matrix that will take care that all elements below and above the pivot are made zero and pivot made =1 in m_u; namely Row_reduced();
            It is a member fuction of class Matrix.

Inputs:     Takes four arguments - 1 character type to specify the character, depending on Matrix req.
                                 - Matrix "B" a constant matrix o that similar operations colud be performed on it.
                                 - Matrix "A" for use of its row and column size.

Outputs:    returns the resulting martrix object that performs the Row operations req. at every step.
**/

Matrix Matrix::Row_reduced(char ch, Matrix A,Matrix B)
{


    Matrix m_rre(A.Rows,A.Columns,1);//Null
    Matrix m_rre_b(A.Rows,A.Columns,1);//Null
    m_rre=A.choose_matrix('U',A);
    m_rre_b=A.choose_matrix('I',A)*B;;

    Matrix L_rre(A.Rows,A.Rows,2);


    for(int i=(A.Rows-1); i>=0; i--)
    {
        Matrix I(A.Rows,A.Rows,2);
        for(int j=0; j<A.Columns; j++)
        {
            // following code makes pivots equal to 1
            if(m_rre.matrix[i][j]!=0)
            {
                double  s=m_rre.matrix[i][j];
                for(int k=j; k<A.Columns; k++)
                {
                    m_rre.matrix[i][k]=(m_rre.matrix[i][k])/s;
                    m_rre_b.matrix[i][k]=(m_rre_b.matrix[i][k])/s;
                }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                // following code makes elemtnts above pivots =0
                I.matrix[i][i]=I.matrix[i][i]/s;
                L_rre=I*L_rre;
                L_rre= (Eij_rre(i,j,m_rre,A))*L_rre;
                m_rre_b =  (Eij_rre(i,j,m_rre,A))*m_rre_b;

                m_rre=  (Eij_rre(i,j,m_rre,A))*m_rre;
                break;

            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
    case 'B':// returns the  changed constant matrix with similar operations performed as in m_rre.
        return m_rre_b;
    }

}

