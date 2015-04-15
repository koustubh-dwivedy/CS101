// to calculate L, U , echelon form and row reduced form and hence obtain R , d, and particular solution.
# include "main_header.h"
Matrix::Matrix Echelon(const Matrix &m,double* D,Matrix &L,Matrix &U,int &detP,Matrix &P)//to avoid copying
{

   // Matrix P(m.Rows,m.Columns,2);
   // Matrix L(m.Rows,m.Rows,2);
   // Matrix U(m.Rows,m.columns,2);
    Matrix &e=m;//check
    int currentRow=0,currentColumn=0;
    int detP=1;
    checkPermutation(e,0,P);
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

Matrix::Matrix Inverse(Matrix A)
{

    Matrix P(m.Rows,m.Columns,2);
    Matrix L(m.Rows,m.Rows,2);
    Matrix U(m.Rows,m.columns,2);
    double b[1]={0};
    int detP=1;
    Matrix E=Echelon(A,b,L,U,detP,P);
    if(det(E) && det(E)!=HUGE_VAL)
 {
    double determinant=det(E)*detP;
    Matrix Adj=Adjoint(A);
    Matrix I=(1/determinant)*Adj;
    return I;
 }
    else if(!det(E))
    {
        cout<<"inverse does not exist";
         return Matrix(1,1,1);
    }
    else
        return(Matrix(1,1,1));
}
