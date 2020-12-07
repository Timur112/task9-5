#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(float *a, float *b)
{
    float c;
    c=*a;
    *a=*b;
    *b=c;
}
void toptriangle(float **a, int n, int d)
{
    int i,j;
    float p;
    if(d<n-1)
    {
        if(a[d][d]==0)
        {
            i=d;
            while(a[i][d]==0)
            {
                i++;
            }
             for(j=0;j<=n;j++)
            {
                swap(&a[d][j],&a[i][j]);
            }
        }
        for(i=d+1;i<n;i++)
        {
            p=a[i][d]/a[d][d];
            for(j=d;j<=n;j++)
            {
                a[i][j]=a[i][j]-a[d][j]*p;

            }
        }
        toptriangle(a,n,d+1);
    }
}
float* Gauss1(float **a, int n)
{
    int i,j;
    float *x;
    x=(float*) malloc(n*sizeof(float));
    for (i=n-1;i>=0;i--)
    {
        x[i]=a[i][n]/a[i][i];
        for(j=n-2;j>=0;j--)
        {
            a[j][n]=a[j][n]-a[j][i]*x[i];
        }
    }
    return x;
}
int main()
{
    int n,i,j;
    float **a,*x;
    scanf("%d", &n);
    a=(float**) malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
    {
        a[i]=(float*) malloc((n+1)*sizeof(float));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    toptriangle(a,n,0);
    x=Gauss1(a,n);
    for(i=0;i<n;i++)
    {
        printf("%f ", x[i]);
    }
    return 0;
}
