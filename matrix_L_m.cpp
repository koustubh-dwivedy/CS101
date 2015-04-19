#include "main_header.h"
/**
Purpose:    This is a multipurpose function.hence namely choose_matrix ; dependig on which matrix you need to perform operations.
            It is a member fuction of class Matrix.

Inputs:     two arguments- charcter(depending on which matrix you want to be returned)
                         - matrix "A" on which the operations need to be performed.

Outputs:    returns the Matrix objects that are req.

Advise:     plz read teh switch case code at teh end of the following function to better understand the operations going on.

**/


Matrix Matrix::choose_matrix(char charac, Matrix A)
{
    Matrix m_u(A.Rows,A.Columns,1); // Null Matrix
    Matrix m(A.Rows,A.Rows,2);// Identity matrix

    m_u=A;

    Matrix m_l(A.Rows,A.Rows,2), m_i_l(A.Rows,A.Rows,2), m_p(A.Rows,A.Rows,2);// Tdentity matrices

    int i=0;
    for(int j=0; j<A.Columns; j++)
    {
        while(i< A.Rows)// loop to run from 'i'th row to A_row
        {
            //first all the row exchanges are taken care of in every matrix by multiplying with the req. object returned by Permutation Matrix.
            m_i_l=(Permutation(i,j,m_u,A))*m_i_l;

            m_l=  m_l*Permutation(i,j,m_u,A);

            m_p=  (Permutation(i,j,m_u,A))*m_p;

            m_u=  (Permutation(i,j,m_u,A))*m_u;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if(m_u.matrix[i][j]!=0)
            {
                m= Eij(i,j,m_u,A);


                for(int c=0; c<A.Rows; c++)
                {
                    for(int d=0; d<A.Rows; d++)
                    {
                        if(c>d)
                            m.matrix[c][d]=-(m.matrix[c][d]);
                    }
                }
                // In the following four lines different matrix operations are taken care of.

                m_i_l=(Eij(i,j,m_u,A))*m_i_l;

                m_l=  m_l*m;

                m_u=  (Eij(i,j,m_u,A))*m_u;

                i++;

            }
            break;

        }
    }
    m_l= m_p * m_l;

    switch(charac)
    {
    case 'L':   // for returning the L matrix of "A" matrix
        return m_l;
        break;

    case 'U':  // for returning U matrix
        return m_u;
        break;

    case 'I': // for returning inverse of L to directly multiply to b in case of case Ax=b.
        return m_i_l;
        break;

    case 'P':// returns the final Permutation matrix obtained
        return m_p;
        break;

    }


}


