#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define pb push_back
const int Max=10000;
struct info
{
    int v,cost;
    info(int v=0,int cost=0):v(v),cost(cost){};
};
vector<pp>edges;
vector<info>Graph[Max+5];
int Tree[5*Max+5],BaseArray[Max+5],SubTreeSize[Max+5];
int ChainHead[Max+5],ChainNum[Max+5],PosInBaseArray[Max+5],ChainNo;
int Level[Max+5],Parent[Max+5],SparseTable[Max+5][16];
int ptr;
void init(int N)
{
    for(int i=0;i<=N;i++)
    {
        Graph[i].clear(),ChainHead[i]=-1;
        for(int j=0;j<=15;j++)SparseTable[i][j]=-1;
    }
    edges.clear();
    ptr=ChainNo=0;
}
void buildSegmentTree(int l,int r,int indx)
{
    if(l==r)
    {
        Tree[indx]=BaseArray[l];
        return;
    }
    int mid=(l+r)>>1;
    int lindx=indx<<1;
    int rindx=lindx|1;
    buildSegmentTree(l,mid,lindx);
    buildSegmentTree(mid+1,r,rindx);
    Tree[indx]=max(Tree[lindx],Tree[rindx]);
}
void updateSegmentTree(int l,int r,int indx,int update_indx,int value)
{
    if(l==r)
    {
        Tree[indx]=value;
        return;
    }
    int mid=(l+r)>>1;
    int lindx=indx<<1;
    int rindx=lindx|1;
    if(update_indx<=mid)updateSegmentTree(l,mid,lindx,update_indx,value);
    else updateSegmentTree(mid+1,r,rindx,update_indx,value);
    Tree[indx]=max(Tree[lindx],Tree[rindx]);
}
int querySegmentTree(int l,int r,int indx,int x,int y)
{
    if(l>y||r<x)return 0;
    if(x<=l&&y>=r)return Tree[indx];
    int mid=(l+r)>>1;
    int lindx=indx<<1;
    int rindx=lindx|1;
    int c1=0,c2=0;
    if(x<=mid)c1=querySegmentTree(l,mid,lindx,x,y);
    if(y>mid)c2=querySegmentTree(mid+1,r,rindx,x,y);
    return max(c1,c2);
}
void dfs(int from,int u,int depth)
{
    Level[u]=depth;
    Parent[u]=from;
    SubTreeSize[u]=1;
    int sz=Graph[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=Graph[u][i].v;
        if(v==from)continue;
        dfs(u,v,depth+1);
        SubTreeSize[u]+=SubTreeSize[v];
    }
}
void sparseTable(int N)
{
    for(int i=0;i<=N;i++)SparseTable[i][0]=Parent[i];
    for(int j=1;(1<<j)<=N;j++)
    {
        for(int i=0;i<=N;i++)
        {
            if(SparseTable[i][j-1]!=-1)
            {
                int a=SparseTable[i][j-1];
                SparseTable[i][j]=SparseTable[a][j-1];
            }
        }
    }
}
int LCA(int p,int q)
{
    if(Level[p]<Level[q])swap(p,q);
    int Log=log2(Level[p])+1;
    for(int i=Log;i>=0;i--)
    {
        if((Level[p]-(1<<i))>=Level[q])p=SparseTable[p][i];
    }
    if(p==q)return p;
    for(int i=Log;i>=0;i--)
    {
        if(SparseTable[p][i]!=-1&&SparseTable[p][i]!=SparseTable[q][i])
        {
            p=SparseTable[p][i],q=SparseTable[q][i];
        }
    }
    return Parent[p];
}
/**
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 **/
void heavyLightDecompositon(int from,int curNode,int cost)
{
    if(ChainHead[ChainNo]==-1)ChainHead[ChainNo]=curNode; /// Assign chain head
    ChainNum[curNode]=ChainNo;
    PosInBaseArray[curNode]=ptr; /// Position of this node in baseArray which we will use in Segtree
    BaseArray[ptr++]=cost;
    int sc=-1,nextCost;
    int sz=Graph[curNode].size();
    for(int i=0;i<sz;i++)  /// Loop to find special child
    {
        int v=Graph[curNode][i].v;
        if(v==from)continue;
        if(sc==-1||SubTreeSize[sc]<SubTreeSize[v])
        {
            sc=v;
            nextCost=Graph[curNode][i].cost;
        }
    }
    if(sc!=-1)heavyLightDecompositon(curNode,sc,nextCost); /// Expand the chain
    for(int i=0;i<sz;i++)
    {
        int v=Graph[curNode][i].v;
        int cost=Graph[curNode][i].cost;
        if(v==from||sc==v)continue;
        ChainNo++;
        heavyLightDecompositon(curNode,v,cost);
    }
}
void updateTree(int ith,int val)
{
    pp a=edges[ith];
    int u=a.first,v=a.second;
    int indx=PosInBaseArray[u];
    if(Level[u]<Level[v])indx=PosInBaseArray[v];
    updateSegmentTree(0,ptr-1,1,indx,val);
}
/**
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 **/
int queryUp(int u,int v)
{
    if(u==v)return 0;
    int uchain,vchain=ChainNum[v],ans=-1;
    while(true)
    {
        uchain=ChainNum[u];
        if(uchain==vchain)
        {
            if(u==v)        /// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
                break;      /// We break because we came from u up till v, we are done
            ans=max(ans,querySegmentTree(0,ptr-1,1,PosInBaseArray[v]+1,PosInBaseArray[u]));
            break;
        }
        int uchainhead=ChainHead[uchain];
        ans=max(ans,querySegmentTree(0,ptr-1,1,PosInBaseArray[uchainhead],PosInBaseArray[u]));
                    /// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        u=Parent[uchainhead];
    }
    return ans;
}
int queryTree(int u,int v)
{
    int lca=LCA(u,v);
    return max(queryUp(u,lca),queryUp(v,lca));
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int N;
        cin>>N;
        init(N);
        for(int i=0;i<N-1;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            u--,v--;
            Graph[u].pb(info(v,c));
            Graph[v].pb(info(u,c));
            edges.pb(pp(u,v));
        }
        dfs(-1,0,0);
        sparseTable(N);
        heavyLightDecompositon(-1,0,-1);
        buildSegmentTree(0,ptr-1,1);
        string ch;
        int x,y;
        while(true)
        {
            cin>>ch;
            if(ch[0]=='D')break;
            cin>>x>>y;
            if(ch[0]=='Q')printf("%d\n",queryTree(x-1,y-1));
            else if(ch[0]=='C')updateTree(x-1,y);
        }
    }
    return 0;
}
