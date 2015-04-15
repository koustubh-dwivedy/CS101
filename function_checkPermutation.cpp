#include "main_header.h"
int checkPermutation(Matrix /* *A */a,int checkJ,Matrix /* *p */P)
{
// commented out by koustubh // Matrix *a=A;// check dereferencing of pointers
// commented out by koustubh // Matrix *P=p;
if(a.matrix[checkJ][checkJ] !=0 )
return 1;
int firstNonZero=checkJ+1;
while(a.matrix[firstNonZero][checkJ]==0)firstNonZero++;
for(int i=0;i<a.Columns;i++)
        {
        int temp,tempP;
        temp=a.matrix[checkJ][i];
        a.matrix[checkJ][i]=a.matrix[firstNonZero][i];
        a.matrix[firstNonZero][i]=temp;
        tempP=P.matrix[checkJ][i];
        P.matrix[checkJ][i]=P.matrix[firstNonZero][i];
        P.matrix[firstNonZero][i]=temp;
        }
return -1;
}


