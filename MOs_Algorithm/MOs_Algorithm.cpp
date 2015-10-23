/**
    MO's Algorithm
    problem: http://www.spoj.com/problems/DQUERY

    MO’s algorithm is just an order in which we process the queries.
    We were given M queries, we will re-order the queries in a particular order and then process them.
    Clearly, this is an off-line algorithm. Each query has L and R, we will call them opening and closing.
    Let us divide the given input array into Sqrt(N) blocks.
    Each block will be N / Sqrt(N) = Sqrt(N) size.
    Each opening has to fall in one of these blocks.
    Each closing has to fall in one of these blocks.

    All the queries are first ordered in ascending order of their block number (block number is the block in which its opening falls).
    Ties are ordered in ascending order of their R value.

**/
#include<bits/stdc++.h>
using namespace std;
#define Mx 30005
#define MxNum 1000005
int BlockSize;
int Answer;
int Freq[MxNum],Num[Mx];
struct info
{
    int L,R,qno;
    info(int L=0,int R=0,int qno=0):L(L),R(R),qno(qno){};
    bool operator<(const info &a)const
    {
        if(L/BlockSize!=a.L/BlockSize)return L/BlockSize<a.L/BlockSize;
        return R<a.R;
    }
}Query[200005];
int StoreAnswer[200005];
void Add(int indx)
{
    Freq[Num[indx]]++;
    if(Freq[Num[indx]]==1)Answer++;
}
void Remove(int indx)
{
    Freq[Num[indx]]--;
    if(Freq[Num[indx]]==0)Answer--;
}
int main()
{
    int N;
    scanf("%d",&N);
    BlockSize=sqrt(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&Num[i]);
    }
    int Q;
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        Query[i]=info(x-1,y-1,i);
    }
    sort(Query,Query+Q);
    int currentL=0,currentR=0;
    Answer=0;
    for(int i=0;i<Q;i++)
    {
        int L=Query[i].L;
        int R=Query[i].R;
        while(currentL<L)
        {
            Remove(currentL);
            currentL++;
        }
        while(currentL>L)
        {
            Add(currentL-1);
            currentL--;
        }
        while(currentR<=R)
        {
            Add(currentR);
            currentR++;
        }
        while(currentR>R+1)
        {
            Remove(currentR-1);
            currentR--;
        }
        StoreAnswer[Query[i].qno]=Answer;
    }
    for(int i=0;i<Q;i++)
    {
        printf("%d\n",StoreAnswer[i]);
    }
    return 0;
}
