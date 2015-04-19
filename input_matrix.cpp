#include "main_header.h"
/**
This is the code for constructing the matrix (CONSTRUCTORS OF Matrix class);
TASK 1: Assigns a matrix inputted by user to the matrix, all by just defining it like "Matrix A(1);"
        Initially INPUT.txt (present in program directory) opened in notepad.
        User enters matrix and saves it.
        Then user presses 2 in the prorgam window by which program saves the matrix entered in INPUT.txt
            to an object of class Matrix while copying its elements as well as
            identifying number of rows and columns.
TASK 2: To define a 1x1 null matrix;
SYNTAX:
    //
        Argument    Result
        (1)         Input
        (2)         Null matrix of dim->1x1
    //
EXAMPLE CODE<->
Martix A(1); // Takes input
Matrix B(2); // Constructs Null matrix of dim->1x1
**/
Matrix::Matrix(int x)
{
    if(x==1)
    {
        // Input Popup
        cout << "Enter 1 to open INPUT.txt";
        int a;
        while(1)
        {
            cin >> a;
            if(a==1)
            {
                system("start INPUT.txt");
                break;
            }
            else cout << "Enter a valid number";
        }
        while(1)
        {
            cout << "Enter 2 after saving and closing Notepad, after inputting your desired matrix\n";
            cin >> a;
            if (a==2) break;
            else cout << "Enter a valid number\n"<<endl;
        }
        // Converting Input to matrix
        string lineA;
        int rowA=0,colA=0;
        double x,input[10][10]= {{0}};
        ifstream fileIN;
        fileIN.open("INPUT.txt");
        if(fileIN.fail())
        {
            cerr << "*File you are trying to access cannot be found/opened:";
            exit(1);
        }
        while(fileIN.good())
        {
            while(getline(fileIN,lineA))
            {
                istringstream streamA(lineA);
                colA=0;
                while(streamA >> x)
                {
                    input[rowA][colA]=x;
                    colA++;
                }
                rowA++;
            }
        }

        Rows=rowA;
        Columns=colA;
        matrix.resize(Rows);
        for(int i=0; i<Rows; i++)
        {
            matrix[i].resize(Columns);
        }

        for (int i=0; i<rowA; i++)
        {
            for (int j=0; j<colA; j++)
            {
                matrix[i][j]=input[i][j];
            }
        }
    }
    else if(x==2)
    {
        Rows=1;
        Columns=1;
        matrix.resize(Rows);
        for(int i=0; i<Rows; i++)
        {
            matrix[i].resize(Columns);
        }
        matrix[0][0]=0;
    }
}
