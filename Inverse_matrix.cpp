#include "main_header.h"
Matrix Matrix::Inverse_matrix(char ch,Matrix A)
{
    if(ch=='1')
    {
        return ((A.Row_reduced('Q',A))*(A.choose_matrix('I',A)));
    }
    else
    {
        return ((A.Row_reduced('Q',A))*A.choose_matrix('I', A))*A;
    }
}
