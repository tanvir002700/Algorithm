/**
**Give a array Of N numbers. Finding Maximum cumulative number frequency in **the range.
**input:
**10 4
**1 1 1 3 3 3 3 2 2 2
**1 5
**1 6
**1 7
**Output:
**3
**3
**4
**2
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LLD;
#define MAX 50005
struct info
{
    int Lcnt,Rcnt,Max,Lnum,Rnum;
    info(int Lcnt=0,int Rcnt=0,int Max=0,int Lnum=0,int Rnum=0):Lcnt(Lcnt),Rcnt(Rcnt),Max(Max),Lnum(Lnum),Rnum(Rnum){};
};
info Tree[3*MAX];
int arr[MAX];
info marge(const info &L,const info &R)
{
    info ret;
    if(L.Rnum==R.Lnum)
    {
        ret.Max=max(L.Rcnt+R.Lcnt,max(L.Max,R.Max));
    }
    else ret.Max=max(L.Max,R.Max);
    ret.Lnum=L.Lnum;
    ret.Rnum=R.Rnum;
    if(L.Lnum==R.Lnum)ret.Lcnt=L.Lcnt+R.Lcnt;
    else ret.Lcnt=L.Lcnt;
    if(L.Rnum==R.Rnum)ret.Rcnt=L.Rcnt+R.Rcnt;
    else ret.Rcnt=R.Rcnt;
    return ret;
}
void build(int L,int R,int indx)
{
    if(L==R)
    {
        Tree[indx]=info(1,1,1,arr[L],arr[R]);
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,2*indx);
    build(mid+1,R,2*indx+1);
    Tree[indx]=marge(Tree[2*indx],Tree[2*indx+1]);
}
info query(int L,int R,int indx,int x,int y)
{
    if(L>=x&&R<=y)return Tree[indx];
    int mid=(L+R)>>1;
    info c1,c2;
    if(x<=mid)c1=query(L,mid,2*indx,x,y);
    if(y>mid)c2=query(mid+1,R,2*indx+1,x,y);
    return marge(c1,c2);
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int N,C,Q;
        scanf("%d %d %d",&N,&C,&Q);
        for(int i=0;i<N;i++)
        {
            int x;
            scanf("%d",&arr[i+1]);
        }
        build(1,N,1);
        printf("Case %d:\n",t);
        while(Q--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",query(1,N,1,x,y).Max);
        }
    }
    return 0;
}
