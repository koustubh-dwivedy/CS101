#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

class Matrix
{
public:
    int Rows;
    int Columns;
    vector<vector<double> > matrix;

    Matrix(int);
    /*
        Argument    Result
        (1)         Input
        (2)         Null matrix of dim->1x1
    */
    Matrix(int,int,int);
    /*
        Argument    Result
        (n,m,1)     n x m null matrix
        (n,n,2)     n x n Identity matrix
    */
    Matrix operator=(Matrix);
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    // Add PA=LU operator
    // Add inverse operator
    void display_output();
    void output_to_excel();
    void print();
};
