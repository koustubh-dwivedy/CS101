/**
*Task: Calculates determinant of given matrix
*Input Parameter Characteristics:
*1.Type: Object of class Matrix
*2.Should be a square matrix.
*Output type: double
*Working logic: Determinant of a matrix is det(P)*product of diagonal elements of echelon form of the matrix
*               where det(p)=(-1)^(No. of row exchanges made in Identity matrix in order to achieve P)
*                           =(-1)^(No. of zeros in diagonal of P-1) [Note: If all diagonal elements are 1 then det(p)=1 anyways.]
**/
#include"main_header.h"
double det( Matrix A)
{
    if(A.Rows==A.Columns)
    {
    Matrix temporary(A.Rows,A.Columns,2);//will store the echelon form of A
    Matrix tempP(A.Rows,A.Rows,2);//will store the Permutation matrix of A (P in PA=LU form)
    int pfactor=1;//stores the determinant of p
    tempP=A.choose_matrix('P',A);
    int zerocounter=0;//counts no. of 0's in diagonal of P
    for(int i=0;i<A.Rows;i++)
    {
        if(tempP.matrix[i][i]==0)zerocounter++;
    }
    if(zerocounter!=0)//if all diagonal members are not 1 and atleast one 0 is present
        pfactor=pow(-1,(zerocounter-1));

    temporary=A.choose_matrix('U',A);
    double d=1;
    for(int i=0; i<temporary.Rows;i++)
    {
        d=d*temporary.matrix[i][i];
    }
    return pfactor*d;//final ans=det(P)*product of diagonal elements of echelon form
    }
    else
    {
        cout<<"This is not a square matrix. Please provide appropriate inputs."<<endl;
        return HUGE_VAL;
    }

}
