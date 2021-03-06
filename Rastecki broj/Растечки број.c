#include <stdio.h>
#include <stdlib.h>

/*
Да се напише рекурзивна функција која што прима еден аргумент - број x која што ќе враќа 1 доколку секоја цифра во бројот е поголема од претходната, а во спротивно0.

Пример бројот 12345 е растечки, додека пак бројот 12325 не е растечки број.

Од стандарден влез се вчитува прво број N, а потоа N броеви. За секој број да се испечати порака DA или NE (во нов ред), доколку бројот е растечки или не е растечки.
*/

int raste(int n)
{
    int a=n%10,b=(n/10)%10;
    if(n<10)
    {
        return 1;
    }
    else
    {
        if(a>b)
        {
            return raste(n/10);
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&x);
        y=raste(x);
        if(y)
        {
            printf("DA\n");
        }
        else
        {
            printf("NE\n");
        }
        n--;
    }
    return 0;
}
