#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

class Matrix
{
public:
    int Rows;
    int Columns;
    double matrix[128][128];
    Matrix(int);
    Matrix(int,int);
    Matrix operator=(Matrix);
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    // Add PA=LU operator
    // Add inverse operator
    void display_output();
    void output_to_excel();
};
