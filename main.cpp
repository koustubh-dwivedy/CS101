#include "main_header.h"
// Make sure in the end that in each and every function where division is taking place,
// it should be double(a)/b and not a/b.
int main()
{
    Matrix A(1),C(2),B(2);
    C=B.eigen_val(A);
    C.print();
}
