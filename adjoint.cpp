/* purpose of the function: to calculate the Adjoint of a given matrix.
                            an adjoint is such a matrix that when multiplied
                            to the former matrix gives a diagonal matrix with
                            all the diagonal matrix equal to the determinant of the
                            former matrix.

   input:                   matrix whose matrix is to be calculated

   output:                  the adjoint matrix
*/
#include "main_header.h"
Matrix Adjoint(Matrix A)
{

        if(A.Rows!=A.Columns)
        {
            cout<<"not a square matrix";
            return Matrix(1,1,1);
        }

        Matrix Adj(A.Rows,A.Columns,1);
        for(int i=0;i<A.Rows;i++)
        {
            for(int j=0;j<A.Columns;j++)
            {
               double element=1;
               Matrix e((A.Rows-1),(A.Columns-1),1);
               for(int i1=1;i1<=(A.Rows-1);i1++)
               {

                for(int j1=1;j1<=(A.Columns-1);j1++)
                e.matrix[i1-1][j1-1]=(A.matrix[(i+i1)%A.Rows][(j+j1)%A.Columns]);
               }
               element=det(e.choose_matrix('U',e));//each element of adjoint is the cofactor of the
                                                   //element at that point in parent matrix

               if((A.Rows%2==0) && ((i+j)%2==1))
               Adj.matrix[i][j]=element*-1;
               else
                Adj.matrix[i][j]=element;
            }
        }
        return (Adj.transpose(Adj));
        }

