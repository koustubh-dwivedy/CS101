# include "main_header.h"
void partSol(Matrix A,double *b)// find the solution to Ax=b
{
Matrix echelon=Echelon(A,b);
 Matrix nspace(A.Columns,A.Columns,1);
nspace=nullspace(A)

 int pivots[echelon.Rows][2],
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





 if(A.Rows==A.Columns&&A.Rows=P)
 {
     cout<<"the system of equations has a unique solution"<<endl;
     double coeff[A.Columns];
     int p=A.Columns;int currentRow=A.Rows;
     double solution[A.Columns]={0};
     while(currentRow>=0)
     {

         while(echelon[currentRow][p]!=0)
         {
             double sum=0;
             coeff[p]=echelon[currentRow][p];
             if(solution[p]==0)
             solution[p]=(b[p]-sum)/echelon[currentRow][p];
             else
             sum=sum+echelon[currentRow][p]*solution[p];
             p--;
         }
     currentRow--;
     }
     for(int k=0;k<p;k++)
     cout<<"value of variable " <<[k+1]<<" is "<<solution[k];
 }
 else if(A.Columns==p && A.Rows>A.Columns)
  {
      int i=1;
      for(j=A.columns;j<A.Rows;j++)
      {
          if(b[j]!=0)i=0;
      }
      if(!i)
      cout<<"system is inconsistent"<<endl;
      else
      {
     cout<<"the system of equations has a unique solution"<<endl;
     double coeff[A.Columns];
     int p=A.Columns;int currentRow=A.Columns;
     double solution[A.Columns]={0};
     while(currentRow>=0)
     {

         while(echelon[currentRow][p]!=0)
         {
             double sum=0;
             coeff[p]=echelon[currentRow][p];
             if(solution[p]==0)
             solution[p]=(b[p]-sum)/echelon[currentRow][p];
             else
             sum=sum+echelon[currentRow][p]*solution[p];
             p--;
         }
     currentRow--;
     }
     for(int k=0;k<p;k++)
     cout<<"value of variable " <<[k+1]<<" is "<<solution[k];
      }
  }
  else
  {
      cout<<"system has infinitey many solutions"<<endl;
      cout<<" the basis of null set is the set for vectors: "<<endl;
      nspace.print();
      cout<<"the particular soltuion is"<<endl;
      double solution[echelon.Columns]={HUGE_VAL};

      int currentRow=A.Rows;
         while(currentRow>=0)
     {
         int p1=A.Columns;
         while(echelon[currentRow][p1]!=0 || pivots[p][2]!=p1 )
         {
             double sum=0;

             if(solution[p1]==HUGE_VAL)
             solution[p1]=(b[p1]-sum)/echelon[currentRow][p1];
             else
             sum=sum+echelon[currentRow][p1]*solution[p1];
             p1--;
         }
     currentRow--;
     p--;
     }
     for (int q=0;q<echelon.Columns;q++)
     {
         if(solution[q]==HUGE_VAL
         cout<<'0';
         elsecout<<solution[q];
     }
  }
}






