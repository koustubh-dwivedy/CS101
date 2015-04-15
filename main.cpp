#include "main_header.h"
// Make sure in the end that in each and every function where division is taking place,
// it should be double(a)/b and not a/b.
int main()
{
<<<<<<< HEAD
Matrix A(1);


A.choose_matrix('U',A).print();
cout<<endl<<endl;
(A.Row_reduced('R',A)).print();
cout<<endl<<endl;

   (A.Row_reduced('Q',A)*A.choose_matrix('U',A)).print();
    return 0;
=======
    Matrix A(1),C(2),B(2);
    C=B.eigen_val(A);
    C.print();
>>>>>>> 031cc6d3b581b5d33170b3d68e7b3823524844ee
}
