/**
**You are given an array of N elements, which are initially all 0. After **that you will be given C commands. They are –
**0 p q v - you have to add v to all numbers in the range **of p to q (inclusive), where p and q are two indexes of the array.
**1 p q - output a line containing a single integer which is the sum of all **the array elements between p and q (inclusive)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LLD;
LLD tree[3*100005];
LLD lazy[3*100005];
void update(int left,int right,int index,int x,int y,int value)
{
    if(x<=left&&y>=right)
    {
        tree[index]+=(LLD)(right-left+1)*value;
        lazy[index]+=value;
        return;
    }
    int mid=(left+right)/2;
    if(lazy[index]!=0)
    {
        tree[2*index]+=(LLD)(mid-left+1)*lazy[index];
        tree[2*index+1]+=(LLD)(right-mid)*lazy[index];
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
    }
    if(x<=mid)
    {
        update(left,mid,2*index,x,y,value);
    }
    if(y>mid)
    {
        update(mid+1,right,2*index+1,x,y,value);
    }
    tree[index]=tree[2*index]+tree[2*index+1];
}
LLD query(int left,int right,int index,int x,int y)
{
    LLD a1=0,a2=0;
    if(x<=left&&y>=right)
    {
        return tree[index];
    }
    int mid=(left+right)/2;
    if(lazy[index]!=0)
    {
        tree[2*index]+=(LLD)(mid-left+1)*lazy[index];
        tree[2*index+1]+=(LLD)(right-mid)*lazy[index];
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
    }
    if(x<=mid)
    {
        a1=query(left,mid,2*index,x,y);
    }
    if(y>mid)
    {
        a2=query(mid+1,right,2*index+1,x,y);
    }
    return (a1+a2);
}
int main()
{
    int test,t;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof*lazy);
        int s,q;
        scanf("%d %d",&s,&q);
        while(q--)
        {
            int x,y,v,dec;
            scanf("%d",&dec);
            if(dec)
            {
                scanf("%d %d",&x,&y);
                LLD ans=query(0,s-1,1,x-1,y-1);
                printf("%lld\n",ans);
            }
            else
            {
                scanf("%d %d %d",&x,&y,&v);
                update(0,s-1,1,x-1,y-1,v);
            }
        }
    }
    return 0;
}
