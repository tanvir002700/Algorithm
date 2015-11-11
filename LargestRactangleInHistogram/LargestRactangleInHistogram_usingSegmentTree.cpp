#include<bits/stdc++.h>
using namespace std;
#define MN 1000005
typedef long long LLD;
LLD Histogram[MN],N;
template<class T> T MAX3(T a,T b,T c)
{
    return max(a,max(b,c));   ///maximum of 3 number
}
struct info
{
    int Num;
    int pos;
    info(int Num=0,int pos=0):Num(Num),pos(pos) {};
};
info Tree[3*MN];
info marge(const info &L,const info &R)
{
    if(L.Num<R.Num)return L;
    return R;
}
void build(int L,int R,int indx)
{
    if(L==R)
    {
        Tree[indx]=info(Histogram[L],L);
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,2*indx);
    build(mid+1,R,2*indx+1);
    Tree[indx]=marge(Tree[2*indx],Tree[2*indx+1]);
}
info query(int L,int R,int indx,int x,int y)
{
    if(L==x&&R==y)return Tree[indx];
    int mid=(L+R)>>1;
    if(y<=mid)return query(L,mid,2*indx,x,y);
    else if(x>mid)return query(mid+1,R,2*indx+1,x,y);
    return marge(query(L,mid,2*indx,x,mid),query(mid+1,R,2*indx+1,mid+1,y));
}
LLD GetMaximumArea(int L,int R)
{
    if(L>R)return -1;
    if(L==R)return Histogram[L];
    info p=query(1,N,1,L,R);
    LLD a=GetMaximumArea(L,p.pos-1);
    LLD b=GetMaximumArea(p.pos+1,R);
    LLD c=(LLD)p.Num*(R-L+1);
    return MAX3(a,b,c);
}
int main()
{
    while(scanf("%d",&N) and N)
    {
        for(int i=1; i<=N; i++)scanf("%lld",&Histogram[i]);
        build(1,N,1);
        printf("%lld\n",GetMaximumArea(1,N));
    }
    return 0;
}

