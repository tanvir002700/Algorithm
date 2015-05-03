/*
**You have an array with n elements which is indexed from 0 to n - 1. **Initially all elements are zero. Now you have to deal with two types of **operations
**1.Increase the numbers between indices i and j (inclusive) by 1. This **is **represented by the command '0 i j'.
**2.Answer how many numbers between indices i and j (inclusive) are **divisible by 3. This is represented by the command '1 i j'.
*/
#include<bits/stdc++.h>
using namespace std;
#define Max 100010
int Tree[8*Max][4];
int lazy[8*Max];
int temp[4];
void build(int left,int right,int indx)
{
    if(left==right)
    {
        Tree[indx][0]=1;
        Tree[indx][1]=Tree[indx][2]=lazy[indx]=0;
        return;
    }
    int mid=(left+right)/2;
    build(left,mid,2*indx);
    build(mid+1,right,2*indx+1);
    for(int i=0;i<3;i++)
    {
        Tree[indx][i]=Tree[2*indx][i]+Tree[2*indx+1][i];
    }
}
void update(int left,int right,int indx,int x,int y,int add)
{
    if(lazy[indx])
    {
        int lazy_val=lazy[indx];
        lazy[2*indx]=(lazy[2*indx]+lazy_val)%3;
        lazy[2*indx+1]=(lazy[2*indx+1]+lazy_val)%3;
        for(int i=0;i<3;i++)temp[(lazy_val+i)%3]=Tree[indx][i];
        for(int i=0;i<3;i++)Tree[indx][i]=temp[i];
        lazy[indx]=0;
    }
    if(left>y||right<x)return;
    if(x<=left&&right<=y)
    {
        for(int i=0;i<3;i++)
        {
            temp[(i+add)%3]=Tree[indx][i];
        }
        for(int i=0;i<3;i++)Tree[indx][i]=temp[i];
        lazy[2*indx]=(lazy[2*indx]+add)%3;
        lazy[2*indx+1]=(lazy[2*indx+1]+add)%3;
        return;
    }
    int mid=(left+right)/2;
    update(left,mid,2*indx,x,y,add);
    update(mid+1,right,2*indx+1,x,y,add);
    for(int i=0;i<3;i++)
    {
        Tree[indx][i]=Tree[2*indx][i]+Tree[2*indx+1][i];
    }
}
int query(int left,int right,int indx,int x,int y)
{
    if(lazy[indx])
    {
        int lazy_val=lazy[indx];
        lazy[2*indx]=(lazy[2*indx]+lazy_val)%3;
        lazy[2*indx+1]=(lazy[2*indx+1]+lazy_val)%3;
        for(int i=0;i<3;i++)temp[(lazy_val+i)%3]=Tree[indx][i];
        for(int i=0;i<3;i++)Tree[indx][i]=temp[i];
        lazy[indx]=0;
    }
    if(left>y||right<x)return 0;
    if(x<=left&&right<=y)return Tree[indx][0];
    int mid=(left+right)/2;
    return query(left,mid,2*indx,x,y)+query(mid+1,right,2*indx+1,x,y);
}
int main()
{
    int x,y;
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        memset(lazy,0,sizeof(lazy));
        int N,Q;
        scanf("%d %d",&N,&Q);
        build(0,N-1,1);
        printf("Case %d:\n",t);
        for(int i=0;i<Q;i++)
        {
            int d;
            scanf("%d %d %d",&d,&x,&y);
            if(d==0)
            {
                update(0,N-1,1,x,y,1);
            }
            else printf("%d\n",query(0,N-1,1,x,y));
        }
    }
    return 0;
}
