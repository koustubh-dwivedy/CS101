#include "main_header.h"

int main()
{
Matrix A(1);


A.choose_matrix('U',A).print();
cout<<endl<<endl;
(A.Row_reduced('R',A)).print();
cout<<endl<<endl;

   (A.Row_reduced('Q',A)*A.choose_matrix('U',A)).print();
    return 0;
}
