#include "main_header.h"
/**
THIS IS AN OPERATOR;
TASK: To assign result to a given matrix;
SYNTAX: A=B+C;
NOTE: Takes care of dimensional difference;
**/
Matrix Matrix::operator=(Matrix B)
{

    Rows=B.Rows;
    Columns=B.Columns;

    matrix.resize(Rows);
    for(int i=0; i<Rows; i++)
    {
        matrix[i].resize(Columns);
    }

    for(int i=0; i<Rows; i++)
    {
        for(int j=0; j<Columns; j++)
        {
            matrix[i][j] = B.matrix[i][j];
        }
    }
    return 0;
}
