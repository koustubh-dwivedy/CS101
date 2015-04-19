#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class Matrix
{
    // In functions required by Koustubh
    double mod(Matrix);
    //
public:
    int Rows;
    int Columns;
    vector<vector<double> > matrix;

    Matrix()
    /**
    This is no error but a way (redefining parameterless (default) constructor) so that
    arrays of Matrix can be created.
    **/
    {
        Rows=3;
        Columns=3;
        matrix.resize(3);
        for(int i=0; i<3; i++)
        {
            matrix[i].resize(3);
        }
    }
    Matrix(int);
    /**
        Argument    Result
        (1)         Input
        (2)         Null matrix of dim->1x1
    **/
    Matrix(int,int,int);
    /**
        Argument    Result
        (n,m,1)     n x m null matrix
        (n,n,2)     n x n Identity matrix
    **/
    Matrix operator=(Matrix);
    bool operator==(Matrix);
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    Matrix eigen_val(Matrix);
    void qr(Matrix &A, Matrix &Q, Matrix &R);
    void display_output();
    void output_to_excel();
    Matrix Permutation(int c, int d, Matrix m_u,Matrix A);
    Matrix Row_reduced(char ch, Matrix A,Matrix);
    Matrix Eij(int c, int d, Matrix m_u,Matrix A);
    Matrix Eij_rre(int c, int d, Matrix m_u,Matrix A);
    Matrix choose_matrix(char charac, Matrix A);
    Matrix Inverse_matrix(char ch,Matrix A);
    void print();
    Matrix transpose(Matrix A);
};
int rank(Matrix a);
Matrix nullspace (Matrix A);
double det(Matrix A);
void solve(Matrix,Matrix);
Matrix Adjoint(Matrix);
