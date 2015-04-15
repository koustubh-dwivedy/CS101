#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <vector>
<<<<<<< HEAD
=======
#include <math.h>
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee

using namespace std;

class Matrix
{
    //functions required by Koustubh
    double mod(Matrix);
    //
public:
    int Rows;
    int Columns;
    vector<vector<double> > matrix;

<<<<<<< HEAD
=======
    Matrix() // This is no error but a way (redefining parameterless (default) constructor) so that arrays of Matrix can be created.
    {
        Rows=3;
        Columns=3;
        matrix.resize(3);
        for(int i=0;i<3;i++)
        {
            matrix[i].resize(3);
        }
    }
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee
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
    bool operator==(Matrix);
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);

    // Add PA=LU operator
<<<<<<< HEAD
    Matrix Eij(int c, int d, Matrix m_u,Matrix A);
    Matrix Permutation(int c, int d, Matrix m_u,Matrix A);
    Matrix choose_matrix(char charac, Matrix A);
    Matrix Eij_rre(int c, int d, Matrix m_u,Matrix A);
    Matrix Row_reduced(char ch,Matrix A);
    Matrix Inverse_matrix(char ch,Matrix A);
   // Add inverse operator
=======
    // Add inverse operator
    Matrix eigen_val(Matrix);
    Matrix transpose(Matrix); // defined in functions_req_by_koustubh.cpp
    void qr(Matrix &A, Matrix &Q, Matrix &R);
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee
    void display_output();
    void output_to_excel();
    void print();
};
