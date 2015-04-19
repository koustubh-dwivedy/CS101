/*
*Task: Integrates th code and is the User interface of this software
*
*Features: 1.Provides the list of functionality of the software
*          2.Feature of compound calculation by storing the most recent result and providing an option
*            to re-use it in the next iteration, thereby making computations like rank(inverse((A+B)*C)) possible
*
*Please note: Please refer to the header file to understand various types of declaring an object of
*             type matrix because some take input from user at the time of initialization while some
*             directtly initialize the matrix to a null or identity matrix
*/
#include "main_header.h"
void recentMatrix(Matrix &result)//inputs a matrix from user and stores it in object passed to function
{
    cout<<"Enter matrix"<<endl;
    Matrix A(1);//input from user
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
    char save='1';//save is the status if the user wants ti input a new matrix or use the most recent
                  //result obtained. By default, it is set as "new Matrix" in the start.
    Matrix storeResult(1,1,1);//stores the most recent result to be operated on
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

        case 1://to solve the system of linear equations
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
            if(A.Rows==b.Rows && b.Columns==1)
                solve(A,b);
            else
                cout<<"number of equations and number of constants do not match"<<endl;
            break;
        }

        case 2://to perform matrix operations
            int choice2;
            cout<<"Enter the number corresponding to your choice of operation"<<endl
                <<"1. Addition or Subtraction or Multiplication"<<endl
                <<"2. Rank\n3. Determinant\n4. Echelon Form\n5. PA=LU form (where A is the input matrix)"<<endl
                <<"6. Row Reduced Form\n7. Inverse\n8. Transpose\n9. Adjoint\n10. Nullspace\n11. Eigen Values\n12. QR Transformation"<<endl
                <<"Your Choice: ";
            cin>>choice2;
            switch(choice2)//NOTE: All operations are performed on storeResult matrix which stores the latest result
                            //or the latest input from the user which needs to be operated on
            {
            case 1:
            {

                char op;
                if(save=='1')recentMatrix(storeResult);
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

                int x=0;
                cout << "If you want this output in MS Excel as well then press 1, else press any other number."<<endl;
                cin >> x;
                if (x==1) storeResult.output_to_excel();
                cout << "If you want to view this file, press 2, else press any other number"<<endl;
                cin >> x;
                if (x==2) storeResult.display_output();

                break;
            }

            case 2:
            {
                if(save=='1')recentMatrix(storeResult);//if the status of save is '1' then user wants
                                                        //to use a fresh matrix that needs to be input
                                                        //this is taken care of by function recentMatrix

                cout<<"Rank of the matrix is: "<<rank(storeResult.choose_matrix('U',storeResult))<<endl;
                break;

            }
            case 3:
            {
                if(save=='1')recentMatrix(storeResult);
                if(storeResult.Rows==storeResult.Columns)
                    cout<<"Determinant = "<<det(storeResult.choose_matrix('U',storeResult))<<endl;
                else
                    cout<<"This is not a square matrix. Please input an appropriate matrix."<<endl;
                break;
            }
            case 4:
            {
                if(save=='1')recentMatrix(storeResult);
                cout<<"Echelon form is: "<<endl;
                storeResult=storeResult.choose_matrix('U',storeResult);
                (storeResult).print();


                int x=0;
                cout << "If you want this output in MS Excel as well then press 1, else press any other number."<<endl;
                cin >> x;
                if (x==1) storeResult.output_to_excel();
                cout << "If you want to view this file, press 2, else press any other number"<<endl;
                cin >> x;
                if (x==2) storeResult.display_output();


                break;
            }
            case 5:
            {
                if(save=='1')recentMatrix(storeResult);
                cout<<"Following is the PA=LU form: "<<endl;
                cout<<"P: \n\n";
                storeResult.choose_matrix('P',storeResult).print();
                cout<<"L: \n\n";
                storeResult.choose_matrix('L',storeResult).print();
                cout<<"U: \n\n";
                storeResult.choose_matrix('U',storeResult).print();
                break;

            }
            case 6:
            {
                if(save=='1')recentMatrix(storeResult);
                cout<<"Row Reduced form is: "<<endl;
                Matrix B(storeResult.Rows,storeResult.Rows,2);
                storeResult=storeResult.Row_reduced('R',storeResult,B);
                storeResult.print();


                int x=0;
                cout << "If you want this output in MS Excel as well then press 1, else press any other number."<<endl;
                cin >> x;
                if (x==1) storeResult.output_to_excel();
                cout << "If you want to view this file, press 2, else press any other number"<<endl;
                cin >> x;
                if (x==2) storeResult.display_output();


                break;
            }
            case 7:
            {
                if(save=='1')recentMatrix(storeResult);
                if(storeResult.Rows==storeResult.Columns&&det(storeResult)!=0)//for inverse to exist
                {                                                             //matrix needs to be square
                                                                            //and determinant!=0

                storeResult=storeResult.Inverse_matrix('2',storeResult);
                cout<<"Inverse is: "<<endl;
                storeResult.print();


                int x=0;
                cout << "If you want this output in MS Excel as well then press 1, else press any other number."<<endl;
                cin >> x;
                if (x==1) storeResult.output_to_excel();
                cout << "If you want to view this file, press 2, else press any other number"<<endl;
                cin >> x;
                if (x==2) storeResult.display_output();


                }
                 else cout << "Inverse Non-Existent \n\n";
                break;

            }
            case 8:
            {
                if(save=='1')recentMatrix(storeResult);
                cout<<"Transpose is: "<<endl;
                storeResult=storeResult.transpose(storeResult);
                storeResult.print();


                int x=0;
                cout << "If you want this output in MS Excel as well then press 1, else press any other number."<<endl;
                cin >> x;
                if (x==1) storeResult.output_to_excel();
                cout << "If you want to view this file, press 2, else press any other number"<<endl;
                cin >> x;
                if (x==2) storeResult.display_output();



                break;
            }
            case 9:
                {
                if(save=='1')recentMatrix(storeResult);
                cout<<"the adjoint of the matrix is"<<endl;
                storeResult=Adjoint(storeResult);
                storeResult.print();


                int x=0;
                cout << "If you want this output in MS Excel as well then press 1, else press any other number."<<endl;
                cin >> x;
                if (x==1) storeResult.output_to_excel();
                cout << "If you want to view this file, press 2, else press any other number"<<endl;
                cin >> x;
                if (x==2) storeResult.display_output();

                }
            case 10:
            {
                if(save=='1')recentMatrix(storeResult);
                cout<<"The basis for nullspace is: "<<endl;
                Matrix A(1,1,1);
                A=storeResult.choose_matrix('U',storeResult);
                storeResult=nullspace(A);
                storeResult.print();


                int x=0;
                cout << "If you want this output in MS Excel as well then press 1, else press any other number."<<endl;
                cin >> x;
                if (x==1) storeResult.output_to_excel();
                cout << "If you want to view this file, press 2, else press any other number"<<endl;
                cin >> x;
                if (x==2) storeResult.display_output();


                break;
            }
            case 11:
            {
                if(save=='1')recentMatrix(storeResult);
                storeResult.eigen_val(storeResult).print();
                break;
            }
            case 12:
            {
                if(save=='1')recentMatrix(storeResult);
                Matrix Q(storeResult.Rows,storeResult.Columns,1),R(storeResult.Rows,storeResult.Columns,1);
                storeResult.qr(storeResult,Q,R);
                cout << "Result:"<<endl;
                cout << "Q:"<<endl;
                Q.print();
                cout << "R:"<<endl;
                R.print();
                break;
            }

            default:
                cout<<"Invalid Input"<<endl;
                break;




            }

            break;

        default:
            cout<<"Invalid input"<<endl;
        }
        char ch;
        while(true)
        {
            cout<<"Do you wish to continue with the application? Enter Y for Yes and N for No\n";
            cout<<"Your choice: ";
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
