#include "main_header.h"

Matrix Matrix::choose_matrix(char charac, Matrix A)
{
    Matrix m_u(A.Rows,A.Columns,1);
    Matrix m(A.Rows,A.Rows,2);
    // m_u.print();
    m_u=A;
    //m_u.print();
    Matrix m_l(A.Rows,A.Rows,2), m_i_l(A.Rows,A.Rows,2), m_p(A.Rows,A.Rows,2);//according to this "a_row" and "a_col" can be changed depending on global rows  and colmn decln of main Matrix


    int i=0;
    for(int j=0; j<A.Columns; j++)
    {
        while(i< A.Rows)
        {

            //cout << "ok";

            //m_u.print();
            // function to run from 'i'th row to A_row
            m_i_l=(Permutation(i,j,m_u,A))*m_i_l;
            //cout << "ok";
            //Permutation(i,j,m_u,A).print();
            m_l=  m_l*Permutation(i,j,m_u,A);
            //cout << "ok";
            //m_l.print();

            m_p=  (Permutation(i,j,m_u,A))*m_p;

            m_u=  (Permutation(i,j,m_u,A))*m_u;


            // m_i_l.print();



            if(m_u.matrix[i][j]!=0)
            {
                //  Matrix m(A.Rows,A.Rows,2);
                m= Eij(i,j,m_u,A);


                for(int c=0; c<A.Rows; c++)
                {
                    for(int d=0; d<A.Rows; d++)
                    {
                        if(c>d)
                            m.matrix[c][d]=-(m.matrix[c][d]);
                    }
                }
                // m.print();
                // cout<<endl<<endl;


                //(Eij(i,j,m_u,A)).print();
                //cout<<endl<<endl;
                // function to run from 'i'th row to A_row and check what change required and return the corresponding matrix
                m_i_l=(Eij(i,j,m_u,A))*m_i_l;

                //m_i_l.print();
                //cout<<endl<<endl;
                //cout << endl<<endl;

                m_l=  m_l*m;
                m_u=  (Eij(i,j,m_u,A))*m_u;

                // m.print();
                //cout<<endl<<endl;

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
    case 'P':  // returns the final permutation matrix to convert to
        return m_p;
        break;

    }


}


