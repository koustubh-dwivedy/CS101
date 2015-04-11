#include "main_header.h"
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
            cout << "Enter 2 after saving and closing Notepad, after inputting your desired matrix";
            cin >> a;
            if (a==2) break;
            else cout << "Enter a valid number"<<endl;
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
