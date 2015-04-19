
#include "main_header.h"
/**
Purpose:        to print the matrices taking care of equal spacing between columns depending on the largest element in the column.
                Member Function of Matrix class
Input:          NIL

Output:         Print the matrices.
**/

void Matrix::print()
{
    int s[Rows+1][Columns];
    int m=0;
    for(int j=0; j<Columns; j++)
    {
        s[Rows+1][j]=0;
        // elements of columns converted to string type and maximum length of element in column stored
        for(int i=0; i<Rows; i++)
        {

            double dbl= matrix[i][j];
            std::ostringstream strs;
            strs << dbl;
            std::string str = strs.str();
            s[i][j]=str.length();
            s[Rows+1][j]=max(s[i][j],s[Rows+1][j]);
        }
    }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // prints the matrices with spacing taken care of
    for(int i=0;i<Rows;i++)
    {
        for(int j=0; j<Columns; j++)
        {
            cout<<matrix[i][j];
           for(int c=s[i][j]; c<s[Rows+1][j]+3; c++)
                cout<<" ";

        }
         cout << endl<<endl;
    }
}
