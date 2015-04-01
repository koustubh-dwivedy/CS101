#include<simplecpp>
/* here i have assumed that the matrix a is global.
*also,the number of rows, i.e rmax and the number of columns i.e cmax of the matrix are assumed to be global
* since these parameters may be rquired time and again, they may be defined in the main program itself.
*also, in the main program,initially P will be stored globally as identity matrix ofdimensions mXm.
* as the funcion checkPermutation is called, P will keep changing accordingly
*/
int checkPermutation(int checkJ)
{
if(a[checkJ][checkJ]!=0)
return 1;
int firstNonZero=checkJ+1;
while(a[firstNonZero][checkJ]==0)firstNonZero++;
for(int i=0;i<cmax;i++)
        {
        int temp,tempP;
        temp=a[checkJ][i];
        a[checkJ][i]=a[firstNonZero][i]
        a[firstNonZero][i]=temp;
        tempP=P[checkJ][i];
        P[checkJ][i]=P[firstNonZero][i]
        P[firstNonZero][i]=temp;
        }
return -1;
}


