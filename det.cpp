#include"main_header.h"
double det(Matrix &A)
{
    if(A.Rows==A.Columns)
    {
    Matrix temporary(A.Rows,A.Columns,1);
<<<<<<< HEAD
    temporary=choose_matrix('U',A);
=======
    temporary=choose_matrix(U,A);
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee
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
