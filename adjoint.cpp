# include "main_header.h"
Matrix Matrix::Adjoint(Matrix &A)
{
    while(1)
    {
        if(A.Rows!=A.Columns)
        {
            cout<<"not a square matrix";
            break;
            return Matrix(1,1,1);
        }

        Matrix Adj(A.Rows,A.Columns,1);
        for(int i=0;i<A.Rows;i++)
        {
            for(int j=0;j<A.Columns;j++)
            {
               double element=1;
               Matrix e((A.Rows-1),(A.Columns-1),1);
               for(int i1=1;i1<=A.Rows;i1++)
                for(int j1=1;j1<=A.Columns;j1++)
                e[i1-1][j1-1]=Adj[(i+i1)%A.Rows][(j+j1)%A.Columns];
               element=e.det(e);
               Adj[i][j]=element*pow(-1,i*j);
            }
        }
        return transpose(Adj);
        break;
    }
}
