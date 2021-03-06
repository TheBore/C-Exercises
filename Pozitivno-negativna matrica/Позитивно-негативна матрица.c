#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

/*
Од стандарден влез се вчитуваaт броевите M и N што означуваат димензиите на една матрица, а потоа се вчитуваат и сите елементи во матрицата со димензии MxN.

Дадената матрицата да се трансформира и да се испечати на стандарден излез на начин што:

сите позитивни елементи во матрицата ќе се заменат со сума од апсолутните вредности на елементите во истата колона.
сите негативни елементи во матрицата ќе се заменат со сума од апсолутните вредност на елементите во истата редица.
елементите што се нула остануваат исти
Пример:

Влез:
4 4
-1 -1 5 5
2 2 4 -6
7 8 -10 12
5 -5 -5 5

Излез:
12 12 24 28 
15 16 24 14 
15 16 37 28 
15 20 20 28
*/

int main()
{
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    int a[MAX][MAX];
    int row_sum[MAX/2]={0};
    int col_sum[MAX/2]={0};
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]>0)
            {
                row_sum[i]=abs(row_sum[i]+a[i][j]);
                col_sum[j]=abs(col_sum[j]+a[i][j]);
            }
            else
            {
                row_sum[i]=abs(row_sum[i]-a[i][j]);
                col_sum[j]=abs(col_sum[j]-a[i][j]);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]>0)
            {
                a[i][j]=col_sum[j];
            }
            else
            {
                if(a[i][j]!=0)
                {
                    a[i][j]=row_sum[i];
                }
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
