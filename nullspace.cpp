#include "main_header.h"
<<<<<<< HEAD
Matrix Matrix::nullspace (Matrix A)
=======
Matrix nullspace (Matrix A)
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee
{
    Matrix nspace(A.Columns,A.Columns,1);
    int nbase=0;
    int pivots[A.Rows][A.Columns],  freevar[A.Columns];//stores column no of free n pivot var
    int p=0,f=0;

    for(int i=0; i<A.Rows; i++)
    {
        for(int j=0; j<A.Columns; j++)
        {
            if(A.matrix[i][j]!=0)
            {


                pivots[p][0]=i;
                pivots[p][1]=j;
                p++;
                break;

            }
        }
    }
    for(int i=0, j=0; i<A.Columns; i++,j++) //finds columns of free variables. nothing but complement of pivot set
    {
        while(pivots[j][1]!=i)
        {
            freevar[f]=i;
            f++;
            i++;
        }
        j++;
        if(j==p) break;
    }

    for(int i=0; i<f; i++)
    {
        int base[A.Columns];
        int counter=0;

        for(int j=0; j<A.Columns; j++)
        {
            if(j==freevar[counter])
            {
                if(j==freevar[i])base[j]=1;
                else base[j]=0;
                counter++;
            }

        }
        for(int k=(p-1); k>=0; k--)
        {
            int sum=0;
            int coefficient=A.matrix[pivots[k][0]][pivots[k][1]];
            for(int l=A.Columns; l>pivots[k][1]; l--)

            {
                sum=sum+A.matrix[pivots[k][0]][l]*base[l];

            }
            base[pivots[k][1]]=-1*sum/coefficient;

        }

        for(int l=0; l<A.Columns; l++)
        {
            nspace.matrix[l][nbase]=base[l];
        }
        nbase++;

    }
    nspace.Rows=A.Columns;
    nspace.Columns=nbase;
    return nspace;

}
