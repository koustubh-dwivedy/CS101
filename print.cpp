#include "main_header.h"
void Matrix::print()
{
    for(int i=0;i<Rows;i++)
    {
        for(int j=0;j<Columns;j++)
        {
<<<<<<< HEAD
            cout << matrix[i][j]<<" "<<"\t";
=======
            cout << matrix[i][j]<<" ";
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee
        }
        cout << endl;
    }
}
