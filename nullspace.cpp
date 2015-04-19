/*
*Task: Returns the matrix which represents the basis for the nullspace of the given matrix
*Input type: An object of class Matrix
*Output type: An object of class Matrix
*Algorithm: 1.Find the position [i][j] of pivot variables and column no. [j] of free variables
*           2.Every column of nullspace is a vector x such that one free variable=1 and other free variables are =0
*               and other elements(corresponding to pivots) are filled such that A*x=0
*/
#include "main_header.h"
Matrix nullspace (Matrix A)
{
    Matrix nspace(A.Columns,A.Columns,1);
    int nbase=0;
    int pivots[A.Rows][A.Columns],  freevar[A.Columns];//stores co-ordinates of pivots and column no. of free variables
    int p=0,f=0;//p=no. of pivot variables; f=no. of free variables

    for(int i=0; i<A.Rows; i++)//find co-ordinates of pivots
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
        int base[A.Columns];//one of the columns of the final nullspace
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
        nbase++;//nbase stores no. of column vactors req. to construct the nullspace

    }
    nspace.Rows=A.Columns;
    nspace.Columns=nbase;
    return nspace;

}

