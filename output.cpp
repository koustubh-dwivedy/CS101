/**
Task: Outputs the supplied matrix to OUTPUT.csv which is present in the directory containing program;
Input: Any Matrix;
Logic: .csv fromat stands for comma separated variables
and as the name suggests each variable is separated by
commas (or every element of matrix is separated by commas);
**/
#include "main_header.h"
void Matrix::output_to_excel()
{
    ofstream file;
    file.open("OUTPUT.csv");
    for(int i=0;i<Rows;i++)
                {
                    for(int j=0;j<Columns;j++)
                    {
                        file << matrix[i][j] << ",";
                    }
                    file<<"\n";
                }
    file.close();
}
/**
Task:: Opening OUTPUT.csv
NOTE: OUTPUT.csv is opened through the default .csv opening software of the OS;
**/
void Matrix::display_output()
{
    system("start OUTPUT.csv");
}
