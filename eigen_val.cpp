#include "main_header.h"
Matrix Matrix::eigen_val(Matrix A)
{
    if(A.Rows==A.Columns)
    {
        Matrix B(A.Columns,A.Columns,1),C(A.Columns,A.Columns,1),Q(A.Columns,A.Columns,1),R(A.Columns,A.Columns,1);
        Matrix eigenvalues(1,A.Columns,1);
        double counter=0;
        C=A;


        while(1)
        {
            qr(C,Q,R);
            B=R*Q;
            for(int i=0;i<A.Rows;i++)
            {
                for(int j=0;j<A.Columns;j++)
                {
                    if(i>j && B.matrix[i][j]<0.000001 && B.matrix[i][j]>-0.000001) counter = counter + 1;
                }
            }

            if((counter == (A.Rows*A.Columns - A.Rows)/2))
            {
                for(int i=0;i<A.Columns;i++)
                {
                    eigenvalues.matrix[0][i]=B.matrix[i][i];
                }
                return eigenvalues;
                break;
            }
            C=B;
            counter=0;
        }
    }
    else
    {
        cout << "Eigen Values of a non square matrix not defined";
        return 0;
    }
}
