/* purpose of the function: given a coefficient matrix corresponding to a system of linear equations
                            and the corresponding constant matrix, to generate the solution.
                            the system may have no, one or infinitely many solutions.
                            the function checks for the correct option out of the three.
                            if system is inconsistent,it prints appropriate remark.
                            if system has unique solution, it prints the solution.
                            if infinitely many solutions exists, the function prints the basis of null
                            space and the corresponding particular solution.
  input:                    coefficient and contant matrix
  output:                   void
  */
# include "main_header.h"
void solve(Matrix A,Matrix B)
{
    Matrix RRE=A.Row_reduced('R',A,B);//calls function to compute row reduced form

    Matrix b=A.Row_reduced('B',A,B);// converts constant matrix appropriately

    Matrix Pivots(A.Rows,2,1);//stores row index and column index of pivot elements

    int P=0;
    for(int i=0; i<A.Rows; i++)
    {
        for(int j=0; j<A.Columns; j++)
        {
            if(RRE.matrix[i][j]!=0)
            {


                Pivots.matrix[P][0]=i;
                Pivots.matrix[P][1]=j;
                P++;
            break;

            }
        }
    }
    Matrix pivots(P,2,1);//resizes Pivot matrix
    for(int i=0;i<P;i++)
        for(int j=0;j<2;j++)
        pivots.matrix[i][j]=Pivots.matrix[i][j];

        if(A.Columns==A.Rows && A.Rows==P)
        {
            cout<<"unique solution exists"<<endl<<endl<<endl;
            cout<<"the value of variables is"<<endl<<endl<<endl;
            Matrix Sol(2);
            Sol=RRE.Inverse_matrix('2',RRE)*b;
            Sol.print();
        }
        else if(A.Rows>P)
        {
            int check=1;
            for(int i=P;i<A.Rows;i++)
            {
                if (b.matrix[i][0]!=0)
                    check=0;
            }
            if(!check)
            cout<<"given system of equations is inconsistent"<<endl;

            else
                {
                if(A.Columns==P)
                {
                    cout<<"unique solution exists"<<endl;
                    Matrix A1(P,P,1);
                    for(int i=0;i<P;i++)
                        for(int j=0;j<P;j++)
                        A1.matrix[i][j]=RRE.matrix[i][j];
                    Matrix Sol(2);
                    Sol=A1.Inverse_matrix('2',A1)*b;
                    cout<<"values of variables are"<<endl<<endl;
                    Sol.print();
                }
                else
                {
                    cout<<"infinitely many solutions exist"<<endl;
                    cout<<"the basis for nullspace is"<<endl;
                    Matrix nspace(2);
                    nspace=nullspace(A);
                    nspace.print();
                    Matrix Sol(A.Columns,1,1);
                    for(int i=0;i<A.Rows;i++)
                    {
                        int c=pivots.matrix[i][1];
                        Sol.matrix[c][0]=b.matrix[c][0];
                    }
                    Sol.print();
                }


                }



                }
                else
                {
                    cout<<"infinitely many solutions exist"<<endl;
                    cout<<" basis for nullspace is"<<endl<<endl;
                    Matrix  nspace(2);
                    nspace=nullspace(A);
                    nspace.print();
                    cout<<endl<<"particular solution is"<<endl<<endl;
                    Matrix Sol(A.Columns,1,1);
                    for(int i=0;i<A.Rows;i++)
                    {
                        int c=pivots.matrix[i][1];
                        Sol.matrix[c][0]=b.matrix[i][0];
                    }
                    Sol.print();

                    }
                }
