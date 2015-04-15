#include "main_header.h"
int main()
{
cout<<"                   Welcome to LinApp: The Linear Algebra App"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
int choice;
while(true)
{
cout<<"Enter your choice of operation:"<<endl;
cout<<"1. Solve Linear Equation"<<endl<<
"2. Perform Matrix operations"<<endl;
cout<<"Your Choice: ";
cin>>choice;
if(choice==1||choice==2)break;
cout<<"Invalid choice. Please enter again."<<endl;
}

switch(choice)
{

case 1:
cout<<"Press ENTER to input the coefficient matrix"<<endl;
Matrix A(1);
cout<<"Now, input the constant matrix."<<endl;
Matrix b(1);
if(b.Columns==1);
else{
    while(true)
    {
        cout<<"Please input an appropriate constant matrix. It should be a column matrix"<<endl;
        Matrix c(1);
        if(c.Columns==1) {b=c;break;}
    }
}
break;
//continue with case 1:
case 2:
    cout<<"Enter the number corresponding to your choice of operation"<<endl
    <<"1. Addition or Subtraction or Multiplication"<<endl
    <<"2. Rank\n3. Determinant\n4. Echelon Form\n5. LU form"<<endl
    <<"6. Row Reduced Form\n7. Inverse\n8. Transpose\n9. Adjoint\n10. Nullspace\n11. Eigen Values"<<endl;





}



}
