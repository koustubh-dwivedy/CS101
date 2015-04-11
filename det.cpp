#include"main_header.h"
double det(Matrix &A)
{
    if(A.Rows==A.Columns)
    {
    Matrix temporary(A.Rows,A.Columns,1);
    temporary=choose_matrix(U,A);
    double d=1;
    for(int i=0; i<temporary.Rows;i++)
    {
        d=d*temporary.matrix[i][i];
    }
    return d;
    }
    else
    {
        cout<<"This is not a square matrix. Please provide appropriate inputs."<<endl;
        return 0;
    }

}
