#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;
void transform_input_to_mat(int *mat)
{
    string lineA;
    int rowA=0,colA=0,x,input[10][10]= {{0}};
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
    for (int i=0;i<rowA;i++)
    {
        for (int j=0;j<colA;j++)
        {
            *(mat+i*colA+j)=input[i][j];
        }
    }
}

void input_popup()
{
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
        cout << "Enter 2 after saving and closing Notepad, after inputting your desired matrix";
        cin >> a;
        if (a==2) break;
        else cout << "Enter a valid number"<<endl;
    }
}

int row_in_input()
{
    string lineA;
    int rowA=0,colA=0,x,input[10][10]= {{0}};
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
    return rowA;
}

int col_in_input()
{
    string lineA;
    int rowA=0,colA=0,x,input[10][10]= {{0}};
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
    return colA;
}

void output(int *pntr_to_mtrx,int rows,int columns) //Pointer of the form &matrix[0][0];
{
    ofstream file;
    file.open("OUTPUT.csv");
    for(int i=0;i<rows;i++)
                {
                    for(int j=0;j<columns;j++)
                    {
                        file << *(pntr_to_mtrx+i*columns+j) << ",";
                    }
                    file<<"\n";
                }
    file.close();
}
void display_output()
{
    system("start OUTPUT.csv");
}
void display_input()
{
    system("start INPUT.csv");
}
int main()
{
    /*
    Matrix to be inputted like this->
    int main()
    {
        //This will create a matrix "input" of size row_in_input * col_in_input
        //with its entries as matrix elements.
        int input[row_in_input()][col_in_input];
        transform_input_to_mat(&input[0][0]);
    }
    ACTUAL CODE-> ACTUAL CODE -> ACTUAL CODE->
    input_popup();
    int matrix1[row_in_input()][col_in_input()];
    transform_input_to_mat(&matrix1[0][0]);
    for(int i=0;i<row_in_input();i++)
    {
        for(int j=0;j<col_in_input();j++)
        {
            cout << matrix1[i][j]<<" ";
        }
        cout << endl;
    }
    input_popup();
    int matrix2[row_in_input()][col_in_input()];
    transform_input_to_mat(&matrix2[0][0]);
    for(int i=0;i<row_in_input();i++)
    {
        for(int j=0;j<col_in_input();j++)
        {
            cout << matrix2[i][j]<<" ";
        }
        cout << endl;
    }
    */
}



