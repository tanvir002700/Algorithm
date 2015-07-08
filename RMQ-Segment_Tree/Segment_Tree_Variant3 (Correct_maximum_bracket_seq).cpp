/**
**Given a bracket sequence.
** On a bracket word one can do the following operations:
**replacement -- changes the i-th bracket into the opposite one
**check -- if the word is a correct bracket expression
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long LLD;
#define MAX 50005
struct info
{
    int sum,sub;
    info(int sum=0,int sub=0):sum(sum),sub(sub){};
};
info Tree[4*MAX];
char inp[MAX];
info marge(const info &L,const info &R)
{
    info ret;
    ret.sum= L.sum+R.sum;
    ret.sub=L.sub;
    ret.sub=min(ret.sub,L.sum+R.sub);
    return ret;
}
void build(int L,int R,int indx)
{
    if(L==R)
    {
        int x;
        if(inp[L]=='(')x=1;
        else x=-1;
        Tree[indx]=info(x,x);
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,2*indx);
    build(mid+1,R,2*indx+1);
    Tree[indx]=marge(Tree[2*indx],Tree[2*indx+1]);
}
void update(int L,int R,int indx,int x)
{
    if(L==R)
    {
        int x;
        if(inp[L]=='(')x=1;
        else x=-1;
        Tree[indx]=info(x,x);
        return;
    }
    int mid=(L+R)>>1;
    if(x<=mid)update(L,mid,2*indx,x);
    else update(mid+1,R,2*indx+1,x);
    Tree[indx]=marge(Tree[2*indx],Tree[2*indx+1]);
}
info query(int L,int R,int indx,int x,int y)
{
    if(L==x&R==y)return Tree[indx];
    int mid=(L+R)>>1;
    if(y<=mid)return query(L,mid,2*indx,x,y);
    else if(x>mid)return query(mid+1,R,2*indx+1,x,y);
    else return marge(query(L,mid,2*indx,x,mid),query(mid+1,R,2*indx+1,mid+1,y));
}
int main()
{
    int N,t=1;
    while(scanf("%d",&N)==1)
    {
        scanf("%s",inp);
        build(0,N-1,1);
        int Q;
        printf("Test %d:\n",t++);
        scanf("%d",&Q);
        while(Q--)
        {
            int x;
            scanf("%d",&x);
            if(x)
            {
                if(inp[x-1]=='(')inp[x-1]=')';
                else inp[x-1]='(';
                update(0,N-1,1,x-1);
            }
            else
            {
                info y=query(0,N-1,1,0,N-1);
                if(y.sum==0&&y.sub>=0)printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
