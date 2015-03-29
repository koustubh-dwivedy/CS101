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
void Matrix::display_output()
{
    system("start OUTPUT.csv");
}
