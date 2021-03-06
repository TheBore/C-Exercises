#include <stdio.h>
#include <stdlib.h>

/*
Од стандарден влез се вчитуваат информации за една матрица и тоа:

броевите М и N (мора да се деливи со 2, во спротивно да заврши програмата и да се испечати порака MATRICATA NE E KOMPATIBILNA).
сите броеви во матрицата со димензии МxN.
Матрицата да се трансформира на начин што ќе се подели на четири четвртини и за секоја четвртина ќе се пресмета разликата меѓу максималниот и минималниот елемент. Потоа секој елемент во секоја четвртина ќе се замени соодветно со разликата на максималниот и минималниот елемент во таа четвртина.
Пример:

Влез:
4 4
1 1 2 2
2 5 4 8
1 8 9 2
2 2 1 8

Излез:
4 4 6 6 
4 4 6 6 
7 7 8 8 
7 7 8 8 

Објаснување: Првата четвртина на матрицата е составена од елементите 1, 1, 2, 5, втората четвртина од елементите 2, 2, 4, 8 итн. Во првата четвртина максимален елемент е бројот 5, а минимален елемент е бројот 1. Нивната разлика е 4, па затоа сите елементи во првата четвртина на матрицата се заменуваат со 1.
*/

int main()
{
    int m,n,i,j,first;
    int max[4]={0},min[4]={0};
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    max[0]=min[0]=a[0][0];
    max[1]=min[1]=a[0][n/2];
    max[2]=min[2]=a[m/2][0];
    max[3]=min[3]=a[m/2][n/2];
    if(m%2==0 && n%2==0)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i<m/2 && j<n/2)
                {
                    if(max[0]<a[i][j])
                    {
                        max[0]=a[i][j];
                    }
                    if(min[0]>a[i][j])
                    {
                        min[0]=a[i][j];
                    }
                }
                if(i<m/2 && j>=n/2)
                {
                    if(max[1]<a[i][j])
                    {
                        max[1]=a[i][j];
                    }
                    if(min[1]>a[i][j])
                    {
                        min[1]=a[i][j];
                    }
                }
                if(i>=m/2 && j<n/2)
                {
                    if(max[2]<a[i][j])
                    {
                        max[2]=a[i][j];
                    }
                    if(min[2]>a[i][j])
                    {
                        min[2]=a[i][j];
                    }
                }
                if(i>=m/2 && j>=n/2)
                {
                    if(max[3]<a[i][j])
                    {
                        max[3]=a[i][j];
                    }
                    if(min[3]>a[i][j])
                    {
                        min[3]=a[i][j];
                    }
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i<m/2 && j<n/2)
                {
                    a[i][j]=max[0]-min[0];
                }
                if(i<m/2 && j>=n/2)
                {
                    a[i][j]=max[1]-min[1];
                }
                if(i>=m/2 && j<n/2)
                {
                    a[i][j]=max[2]-min[2];
                }
                if(i>=m/2 && j>=n/2)
                {
                    a[i][j]=max[3]-min[3];
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
    }
    else
    {
        printf("MATRICATA NE E KOMPATIBILNA");
    }

    return 0;
}
