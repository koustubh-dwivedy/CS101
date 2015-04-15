#include<simplecpp>

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


