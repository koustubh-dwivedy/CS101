#include "main_header.h"
void Matrix::print()
{
    for(int i=0;i<Rows;i++)
    {
        for(int j=0;j<Columns;j++)
        {
            cout << matrix[i][j]<<" "<<"\t";
        }
        cout << endl;
    }
}
