#include "main_header.h"
void recentMatrix(Matrix &result)
{
    cout<<"Enter matrix"<<endl;
    Matrix A(1);
    result=A;
}
int main()
{
    cout<<"                   Welcome to LinApp: The Linear Algebra App"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int choice;
    char save='1';
    Matrix storeResult(1,1,1);
    while(true)
    {

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
        {

            cout<<"Press ENTER to input the coefficient matrix"<<endl;
            Matrix A(1);
            cout<<"Now, input the constant matrix."<<endl;
            Matrix b(1);
            if(b.Columns==1);
            else
            {
                while(true)
                {
                    cout<<"Please input an appropriate constant matrix. It should be a column matrix"<<endl;
                    Matrix c(1);
                    if(c.Columns==1)
                    {
                        b=c;
                        break;
                    }
                }
            }
            break;
        }

//continue with case 1:
        case 2:
            int choice2;
            cout<<"Enter the number corresponding to your choice of operation"<<endl
                <<"1. Addition or Subtraction or Multiplication"<<endl
                <<"2. Rank\n3. Determinant\n4. Echelon Form\n5. PA=LU form (where A is the input matrix)"<<endl
                <<"6. Row Reduced Form\n7. Inverse\n8. Transpose\n9. Adjoint\n10. Nullspace\n11. Eigen Values"<<endl
                <<"Your Choice: ";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
            {

                char op;
                if(save='1')recentMatrix(storeResult);
                Matrix result(1,1,1);
                result=storeResult;
                while(true)
                {
                    cout<<"enter 0 to exit the current opertion or enter the choice of operator from +, -, *"<<endl;


                    while(1)
                    {
                        cin>>op;
                        if(op=='+'||op=='-'||op=='*'||op=='0')break;
                        cout<<"Please enter correct character"<<endl;
                    }
                    if(op=='0') break;
                    cout<<"Enter the next matrix"<<endl;
                    Matrix B(1);
                    if(op=='+')
                    {
                        result=result+B;

                    }
                    else if(op=='-')
                    {
                        result=result-B;

                    }
                    else if(op=='*')
                    {
                        result=result*B;

                    }
                }
                cout<<"Answer: "<<endl;
                storeResult=result;
                storeResult.print();
                break;
            }

            case 2:
            {
                if(save='1')recentMatrix(storeResult);
                cout<<"Rank of the matrix is: "<<rank(storeResult)<<endl;
                break;

            }
            case 3:
            {
                if(save='1')recentMatrix(storeResult);
                if(storeResult.Rows==storeResult.Columns)
                    cout<<"Determinant = "<<det(storeResult)<<endl;
                else
                    cout<<"This is not a square matrix. Please input an appropriate matrix."<<endl;
                break;
            }
            case 4:
            {
                if(save='1')recentMatrix(storeResult);
                cout<<"Echelon form is: "<<endl;
                storeResult=storeResult.choose_matrix('U',storeResult);
                (storeResult).print();
                break;
            }
            case 5://check usage of choose_matrix
            {
                if(save='1')recentMatrix(storeResult);
                cout<<"Following is the PA=LU form: "<<endl;
                cout<<"P: ";
                storeResult.choose_matrix('P',storeResult).print();
                cout<<"L: ";
                storeResult.choose_matrix('L',storeResult).print();
                cout<<"U: ";
                storeResult.choose_matrix('U',storeResult).print();
                break;

            }
            case 6://row reduced defn use to be checked
            {
                if(save='1')recentMatrix(storeResult);
                cout<<"Row Reduced form is: "<<endl;
                storeResult=storeResult.Row_reduced('R',storeResult).
                            storeResult.print();
                break;
            }
            case 7://Kishen handle it!!!
            {
                if(save='1')recentMatrix(storeResult);
                cout<<"Inverse is: "<<endl;//just find and display the inverse of storeResult matrix. then update storeResult with the most recent result i.e the inverse

            }
            case 8:
            {
                if(save='1')recentMatrix(storeResult);
                cout<<"Transpose is: "<<endl;
                storeResult=transpose(storeResult);
                storeResult.print();
                break;
            }
            case 10:
            {
                if(save='1')recentMatrix(storeResult);
                cout<<"The basis for nullspace is: "<<endl;
                storeResult=nullspace(storeResult);
                storeResult.print();
                break;
            }
            case 11://koustubh to handle eigen values
            {
                if(save='1')recentMatrix(storeResult);//just find the eigenvalues of the storeResult matrix
                break;
            }
            default:
                cout<<"Invalid input"<<endl;




            }

        default:
            cout<<"Invalid input"<<endl;
        }
        char ch;
        while(true)
        {
            cout<<"Do you wish to continue with the application? Enter Y for yes and N for no.";
            cin>>ch;
            if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
            cout<<"Invalid input. Please re-enter"<<endl;

        }
        if(ch=='N'||ch=='n')break;
        while(true)
        {
            cout<<"\nPlease enter your choice:\n\n";
            cout<<"1. Use a new matrix next time.\n"
                <<"2. Save the result and use it again next time."<<endl;
            cin>>save;
            if(save=='1'||save=='2')break;
            cout<<"Invalid input.\n";
        }
        cout<<"*************************************************************************************\n\n\n\n";


    }
}
