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
    // Define = operator
    // Add addition operator
    // Add subtraction operator
    // Add multiplication operator
    // Add PA=LU operator
    // Add inverse operator
    void display_output();
    void output_to_excel();
};
