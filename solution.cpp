#include <iostream>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

class Matrix
{
public:
    int Rows;
    int Columns;
    vector<vector<double> > matrix;

    Matrix(int);
    /*
        Argument    Result
        (1)         Input
        (2)         Null matrix of dim->1x1
    */
    Matrix(int,int,int);
    /*
        Argument    Result
        (n,m,1)     n x m null matrix
        (n,n,2)     n x n Identity matrix
    */
    Matrix operator=(Matrix);
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(Matrix);
    // Add PA=LU operator
    // Add inverse operator
    void display_output();
    void output_to_excel();
    void print();
};
// *********************************************************************************************************************

#include "main_header.h"
Matrix::Matrix(int x)
{
    if(x==1)
    {
        // Input Popup
        cout << "Enter 1 to open INPUT.txt";
        int a;
        while(1)
        {
            cin >> a;
            if(a==1)
            {
                system("start INPUT.txt");
                break;
            }
            else cout << "Enter a valid number";
        }
        while(1)
        {
            cout << "Enter 2 after saving and closing Notepad, after inputting your desired matrix";
            cin >> a;
            if (a==2) break;
            else cout << "Enter a valid number"<<endl;
        }
        // Converting Input to matrix
        string lineA;
        int rowA=0,colA=0;
        double x,input[10][10]= {{0}};
        ifstream fileIN;
        fileIN.open("INPUT.txt");
        if(fileIN.fail())
        {
            cerr << "*File you are trying to access cannot be found/opened:";
            exit(1);
        }
        while(fileIN.good())
        {
            while(getline(fileIN,lineA))
            {
                istringstream streamA(lineA);
                colA=0;
                while(streamA >> x)
                {
                    input[rowA][colA]=x;
                    colA++;
                }
                rowA++;
            }
        }

        Rows=rowA;
        Columns=colA;
        matrix.resize(Rows);
        for(int i=0; i<Rows; i++)
        {
            matrix[i].resize(Columns);
        }

        for (int i=0; i<rowA; i++)
        {
            for (int j=0; j<colA; j++)
            {
                matrix[i][j]=input[i][j];
            }
        }
    }
    else if(x==2)
    {
        Rows=1;
        Columns=1;
        matrix.resize(Rows);
        for(int i=0; i<Rows; i++)
        {
            matrix[i].resize(Columns);
        }
        matrix[0][0]=0;
    }
}
// ********************************************************************************************************************
#include "main_header.h"
void Matrix::print()
{
    for(int i=0;i<Rows;i++)
    {
        for(int j=0;j<Columns;j++)
        {
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

// *****************************************************************************************************************


Matrix transpose(Matrix &a)
{
    Matrix t(a.Columns,a.Rows,1);
    for(int i=0;i<a.Rows;i++)
    {
        for(int j=0;j<a.Columns;j++)
        {
            t.matrix[j][i]=a.matrix[i][j];
        }
    }
    return t;
}
//**************************************************************************************************************************
Matrix Adjoint(const Matrix &A)
{
        if(A.Rows!=A.Columns)
        {
            cout<<"not a square matrix";
            return Matrix(1,1,1);
        }

        Matrix Adj(A.Rows,A.Columns,1);
        for(int i=0;i<A.Rows;i++)
        {
            for(int j=0;j<A.Columns;j++)
            {
               double element=1;
               Matrix e((A.Rows-1),(A.Columns-1),1);
               for(int i1=1;i1<=A.Rows;i1++)
                for(int j1=1;j1<=A.Columns;j1++)
                e.matrix[i1-1][j1-1]=Adj.matrix[(i+i1)%A.Rows][(j+j1)%A.Columns];
               element=e.det(e);
               Adj.matrix[i][j]=element*pow (-1.0,i*j);
            }
        }
        return transpose(Adj);
    }


    //*******************************************************************************************************************************

int checkPermutation(Matrix *A,int checkJ,Matrix* p)
{
Matrix *a=A;// check dereferencing of pointers
Matrix *P=p;
if(a.matrix[checkJ][checkJ]!=0)
return 1;
int firstNonZero=checkJ+1;
while(a.matrix[firstNonZero][checkJ]==0)firstNonZero++;
for(int i=0;i<cmax;i++)
        {
        int temp,tempP;
        temp=a.matrix[checkJ][i];
        a.matrix[checkJ][i]=a.matrix[firstNonZero][i]
        a.matrix[firstNonZero][i]=temp;
        tempP=P.matrix[checkJ][i];
        P.matrix[checkJ][i]=P.matrix[firstNonZero][i]
        P.matrix[firstNonZero][i]=temp;
        }
return -1;
}

// ********************************************************************************************************************************************
Matrix::Matrix Echelon(const Matrix &m,double* D,Matrix &L,Matrix &U,int &detP,Matrix &P)//to avoid copying
{

   // Matrix P(m.Rows,m.Columns,2);
   // Matrix L(m.Rows,m.Rows,2);
   // Matrix U(m.Rows,m.columns,2);
    Matrix e=m;//check
    int currentRow=0,currentColumn=0;
    int detP=1;
    detP=detP*checkPermutation(e,0,P);
        while(currentColumn<=m.Columns)
    {
        currentColumn=0;
        if(e.matrix[currentRow][currentColumn]==0)
        {
            currentColumn++;
            break;
        }
        for(int i=1;i<=(m.Rows-currentRow))
        {
            double tempFactor=e.matrix[currentRow+i][currentColumn]/e.matrix[currentRow][currentColumn];
            L.matrix[currentRow+i][currentColumn]=-1*tempFactor;
            D[currentRow+i]=D[currentRow+i]-tempFactor*D[currentRow];
            for(int j=0;j<m.Columns;j++)
                e.matrix[currentRow+i][j]=e.matrix[currentRow+i][j]-tempFactor*e.matrix[currentRow][j];
        }
        detP=detP*checkPermutation(e,currentColumn,P);
        currentColumn++;
        currentRow++;
    }
    U=e;
    return e;
}
// ****************************************************************************************************************************************
Matrix::Matrix Inverse(Matrix A)
{

    Matrix P(m.Rows,m.Columns,2);
    Matrix L(m.Rows,m.Rows,2);
    Matrix U(m.Rows,m.columns,2);
    double b[1]={0};
    int detP=1;
    Matrix E=Echelon(A,b,L,U,detP,P);
    doble det=1;
    if(det!=0 && det!=HUGE_VAL)
 {
    double determinant=det*detP;
    Matrix Adj=Adjoint(A);
    Matrix I=(1/determinant)*Adj;
    return I;
 }
    else if(!det)
    {
        cout<<"inverse does not exist";
         return Matrix(1,1,1);
    }
    else
        return(Matrix(1,1,1));
}
//**************************************************************************************************************************************************
Matrix nullspace (Matrix A)
{
    Matrix nspace(A.Columns,A.Columns,1);
    int nbase=0;
    int pivots[A.Rows][A.Columns],  freevar[A.Columns];//stores column no of free n pivot var
    int p=0,f=0;

    for(int i=0; i<A.Rows; i++)
    {
        for(int j=0; j<A.Columns; j++)
        {
            if(A.matrix[i][j]!=0)
            {


                pivots[p][0]=i;
                pivots[p][1]=j;
                p++;
                break;

            }
        }
    }
    for(int i=0, j=0; i<A.Columns; i++,j++) //finds columns of free variables. nothing but complement of pivot set
    {
        while(pivots[j][1]!=i)
        {
            freevar[f]=i;
            f++;
            i++;
        }
        j++;
        if(j==p) break;
    }

    for(int i=0; i<f; i++)
    {
        int base[A.Columns];
        int counter=0;

        for(int j=0; j<A.Columns; j++)
        {
            if(j==freevar[counter])
            {
                if(j==freevar[i])base[j]=1;
                else base[j]=0;
                counter++;
            }

        }
        for(int k=(p-1); k>=0; k--)
        {
            int sum=0;
            int coefficient=A.matrix[pivots[k][0]][pivots[k][1]];
            for(int l=A.Columns; l>pivots[k][1]; l--)

            {
                sum=sum+A.matrix[pivots[k][0]][l]*base[l];

            }
            base[pivots[k][1]]=-1*sum/coefficient;

        }

        for(int l=0; l<A.Columns; l++)
        {
            nspace.matrix[l][nbase]=base[l];
        }
        nbase++;

    }
    nspace.Rows=A.Columns;
    nspace.Columns=nbase;
    return nspace;

}
// **************************************************************************************************************************************
void partSol(Matrix A,double *b)// find the solution to Ax=b
{
Matrix echelon=A.Echelon(A,b);
 Matrix nspace(A.Columns,A.Columns,1);
nspace=nullspace(A)

 int pivots[echelon.Rows][2];
    int P=0,f=0;

    for(int i=0; i<echelon.Rows; i++)
    {
        for(int j=0; j<echelon.Columns; j++)
        {
            if(echelon.matrix[i][j]!=0)
            {


                pivots[P][0]=i;
                pivots[P][1]=j;
                P++;
                break;
            }
        }
    }





 if(A.Rows==A.Columns&&A.Columns==P)
 {
     cout<<"the system of equations has a unique solution"<<endl;
     int p=A.Columns;int currentRow=A.Rows;
     double solution[A.Columns];
     for (int f=0;f<A.Columns;f++)solution[f]=0;
     while(currentRow>=0)
     {

         double sum=0;
         while(pivots[currentRow][1]!=p)
         {
             sum=sum+echelon.matrix[currentRow][p]*solution[p];
             p--;
         }
         solution[p]=(b[p]-sum)/echelon.matrix[currentRow][p];
     currentRow--;
     }
     for(int k=0;k<p;k++)
     cout<<"value of variable " <<(k+1)<<" is "<<solution[k];
 }
 else if(A.Rows>P)
  {
      int i=1;
      for(int j=P;j<A.Rows;j++)
      {
          if(b[j]!=0)i=0;
      }
      if(!i)
      cout<<"system is inconsistent"<<endl;
      else
      {
          if (A.Columns==P)
          {
         cout<<"the system of equations has a unique solution"<<endl;
         int p=A.Columns;int currentRow=A.Columns;
         double solution[A.Columns];
         for(int g=0;g<A.Columns;g++)solution[g]=0;
         while(currentRow>=0)
         {
             double sum=0;
             while(pivots[currentRow][1]!=p)
             {
                 sum=sum+echelon.matrix[currentRow][p]*solution[p];
                 p--;
             }
             solution[p]=(b[p]-sum)/echelon.matrix[currentRow][p];
             currentRow--;
         }
         for(int k=0;k<p;k++)
         cout<<"value of variable " <<(k+1)<<" is "<<solution[k];
          }


      else
      {
      cout<<"System has infinitely many solutions";
      cout<<" the basis of null set is the set for vectors: "<<endl;
      nspace.print()<<endl;
      cout<<"the particular soltuion is"<<endl;
      double solution[echelon.Columns];
      for(int f=0;f<echelon.Columns;f++)solution[f]=0;
      int currentRow=A.Rows;
         while(currentRow>=0)
     {
         int p1=A.Columns;
         double sum=0;
         while(pivots[currentRow][2]!=p1)
         {
             sum=sum+echelon.matrix[currentRow][p1]*solution[p1];
             p1--;
         }
         solution[p1]=(b[currentRow]-sum)/echelon.matrix[currentRow][p1];
     currentRow--;
     }
     for (int q=0;q<echelon.Columns;q++)
     cout<<solution[q]<<endl;
    }
}
}
  else
  {
      cout<<"system has infinitey many solutions"<<endl;
      cout<<" the basis of null set is the set for vectors: "<<endl;
      nspace.print();
      cout<<"the particular soltuion is"<<endl;
      double solution[echelon.Columns];
      for(int f=0;f<echelon.Columns;f++)solution[f]=0;

      int currentRow=A.Rows;
         while(currentRow>=0)
     {
         int p1=A.Columns;
         while(pivots[currentRow][1]!=p1)
         {
             double sum=0;
             sum=sum+echelon.matrix[currentRow][p1]*solution[p1];
             p1--;
         }
         solution[p1]=(b[p1]-sum)/echelon.matrix[currentRow][p1];
         currentRow--;
     }
     for (int q=0;q<echelon.Columns;q++)
         cout<<solution[q]<<endl;
     }
  }
// ***************************************************************************************************************************************

void main()
{
Matrix A(1);
 Matrix P(m.Rows,m.Columns,2);
 Matrix L(m.Rows,m.Rows,2);
 Matrix U(m.Rows,m.columns,2);
 Matrix b(1);
 partSol(A,b);
 }




