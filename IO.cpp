#include <iostream>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
using namespace std;

void input()
{
    cout << "Enter 1 to open Microsoft Excel";
    int a;
    while(1)
    {
        cin >> a;
        if(a==1)
        {
            system("start INPUT.csv");
            break;
        }
        else cout << "Enter a valid number";
    }
    while(1)
    {
        cout << "Enter 2 after saving and closing MS Excel, after inputting your desired matrix";
        cin >> a;
        if (a==2) break;
        else cout << "Enter a valid number"<<endl;
    }
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

}



