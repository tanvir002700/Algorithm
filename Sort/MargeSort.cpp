#include<stdio.h>
typedef long long int LLD;
const LLD inf=0x7FFFFFFFF;
LLD cnt;
LLD A[500000+5];
void marge(LLD *A,int p,int q,int r)
{
    LLD n1=q-p+1;
    LLD n2=r-q;
    LLD L[n1+2],R[n2+2];
    LLD i,j;
    for(i=1; i<=n1; i++)
    {
        L[i]=A[p+i-1];
    }
    for(j=1; j<=n2; j++)
    {
        R[j]=A[q+j];
    }
    L[n1+1]=inf;
    R[n2+1]=inf;
    i=j=1;
    for(int k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            cnt+=(n1-i+1);
            A[k]=R[j];
            j++;
        }
    }
}
void marge_sort(LLD *A,int p,int r)
{
    int q=(p+r)/2;
    if(p>=r)return;
    marge_sort(A,p,q);
    marge_sort(A,q+1,r);
    marge(A,p,q,r);
}
int main()
{
    int N;
    while(scanf("%d",&N)&&N)
    {
        cnt=0;
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&A[i]);
        }
        marge_sort(A,0,N-1);
        printf("%lld\n",cnt);
    }
    return 0;
}
