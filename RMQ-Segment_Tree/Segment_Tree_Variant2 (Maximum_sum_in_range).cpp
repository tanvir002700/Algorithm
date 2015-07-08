/**
**You are given a sequence A of N (N <= 50000) integers between -10000 and 10000.
**On this sequence you have to apply M (M <= 50000) operations:
**modify the i-th element in the sequence or for given x y print max{Ai + Ai+1 + .. + Aj | x<=i<=j<=y }.
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long LLD;
template<class T> T MAX3(T a,T b,T c) {return max(a,max(b,c));}
LLD Inf=(1ll<<60);
#define MN 50005
struct info
{
    LLD prefixSum;
    LLD suffixSum;
    LLD Total;
    LLD TotalMax;
    info(int pre=-Inf,int suff=-Inf,int total=-Inf,int totalmax=-Inf):prefixSum(pre),suffixSum(suff),Total(total),TotalMax(totalmax){};
};
info marge(const info &a,const info &b)
{
    info ret;
    ret.Total=a.Total+b.Total;
    ret.prefixSum=max(a.prefixSum,a.Total+b.prefixSum);
    ret.suffixSum=max(a.suffixSum+b.Total,b.suffixSum);
    ret.TotalMax=MAX3(a.TotalMax,b.TotalMax,a.suffixSum+b.prefixSum);
    return ret;
}
LLD arr[MN];
info Tree[3*MN];
void build(int L,int R,int indx)
{
    if(L==R)
    {
        Tree[indx]=info(arr[L],arr[L],arr[L],arr[L]);
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,2*indx);
    build(mid+1,R,2*indx+1);
    Tree[indx]=marge(Tree[2*indx],Tree[2*indx+1]);
}
void update(int L,int R,int indx,int x,LLD val)
{
    if(L==R)
    {
        Tree[indx]=info(val,val,val,val);
        return;
    }
    int mid=(L+R)>>1;
    if(x<=mid)update(L,mid,2*indx,x,val);
    else update(mid+1,R,2*indx+1,x,val);
    Tree[indx]=marge(Tree[2*indx],Tree[2*indx+1]);
}
info query(int L,int R,int indx,int x,int y)
{
    if(L==x and y==R)return Tree[indx];
    int mid=(L+R)>>1;
    if(y<=mid)return query(L,mid,2*indx,x,y);
    else if(x>mid)return query(mid+1,R,2*indx+1,x,y);
    return marge(query(L,mid,2*indx,x,mid),query(mid+1,R,2*indx+1,mid+1,y));
}
int main()
{
    #ifdef _ANICK_
    //f_input;
    #endif // _ANICK_
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)scanf("%lld",&arr[i]);
    build(1,N,1);
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int t,x,y;
        scanf("%d %d %d",&t,&x,&y);
        if(t)printf("%lld\n",query(1,N,1,x,y).TotalMax);
        else update(1,N,1,x,y);
    }
    return 0;
}
