#include "main_header.h"
/**
Purpose:     This function finds the inverse of a matrix.namely Inverse_matrix;
             It is a member fuction of class Matrix.

Input:       takes two arguments -a character which decides which matrix object to be returned,
                                 -and the matrix "A" on which actual operations are to be performed.

Output:      returns the Inverse matrix
**/
Matrix Matrix::Inverse_matrix(char ch,Matrix A)
{
    Matrix B(A.Rows,A.Rows,2);// an identitiy dummy matrix just for calling Row-reduced().
    Matrix I(Rows,Rows,2);// an identity matrix defined.
    if(ch=='1') // if character sent in is '1' then matrix that needs to be multiplied with "I"(Identity Matrix) to give Inverse will be returned.
    {
        return ((A.Row_reduced('Q',A,B))*(A.choose_matrix('I',A)));
    }
    else// for any other input of character it'll return the inverse of matrix A;
    {
        return ((A.Row_reduced('Q',A,B))*A.choose_matrix('I', A))*I;
    }
}
