#include "main_header.h"
// This takes in input->
// A (function whose transformation we are doing)
// Address of the matrix Q (defined in eigen program with appropriate memory allocated).
// Address of the matrix R (defined in eigen program with appropriate memory allocated).
// This returns void.
void Matrix::qr(Matrix &A, Matrix &Q, Matrix &R)
{
    // Defining matrices u and e.
    Matrix *u[A.Columns];
    Matrix *e[A.Columns];
    for(int i=0; i<A.Columns; i++)
    {
        u[i] = new Matrix(1,A.Rows,1);
    }
    for(int i=0; i<A.Columns; i++)
    {
        e[i] = new Matrix(1,A.Rows,1);
    }
    //
    // Putting u1=a1.
    for(int i=0; i<A.Rows; i++)
    {
        (*u[0]).matrix[0][i]=A.matrix[i][0];
    }
    // Putting e1=u1/mod(u1)
    for(int i=0; i<A.Rows; i++)
    {
        (*e[0]).matrix[0][i]=(*u[0]).matrix[0][i]/mod((*u[0]));
    }
    //


    double buffer=0;
    for(int i=1; i<A.Columns; i++)
    {
        // Finding u[i].
        for(int a=0; a<A.Rows; a++)
        {

            buffer=A.matrix[a][i];

            for(int b=0; b<i; b++)
            {

                buffer=buffer-(((*e[b])*A).matrix[0][i])*((*e[b]).matrix[0][a]);

            }

            (*u[i]).matrix[0][a]=buffer;

        }
        // Finding e[i].
        for(int j=0; j<A.Rows; j++)
        {

            (*e[i]).matrix[0][j]=(*u[i]).matrix[0][j]/double(mod((*u[i])));

        }
    }
    // Assigning values to Q and R
    for(int i=0; i<A.Rows; i++)
    {
        for(int j=0; j<A.Columns; j++)
        {
            Q.matrix[i][j]=(*e[j]).matrix[0][i];
        }
    }
    //
    for(int i=0; i<A.Rows; i++)
    {
        for(int j=0; j<A.Columns; j++)
        {
            if(i>j)
            {
                R.matrix[i][j]=0;
            }
            if(i<=j)
            {
                R.matrix[i][j]=((*e[i])*A).matrix[0][j];
            }
        }
    }
    //
}









