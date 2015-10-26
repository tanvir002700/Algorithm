vector<pp>Graph[2005];
int Level[2005];
int Lavel_cost[2005];
int sparse_table[2005][20];
int sparse_cost[2005][20];
void init()
{
    mem(parents,-1);
    mem(sparse_table,-1);
    mem(sparse_cost,0);
}
void dfs(int from,int u,int deep)
{
    Level[u]=deep;
    parents[u]=from;
    int sz=Graph[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=Graph[u][i].second;
        int c=Graph[u][i].first;
        if(v==from)continue;
        Cost[v]=c;
        dfs(u,v,deep+1);
    }
}
void Sparse(int N)
{
    for(int i=0;i<N;i++)
    {
        sparse_cost[i][0]=Cost[i];
        sparse_table[i][0]=parents[i];
    }
    for(int j=1;(1<<j)<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(sparse_table[i][j-1]!=-1)
            {
                int a=sparse_table[i][j-1];
                sparse_table[i][j]=sparse_table[a][j-1];
                sparse_cost[i][j]=sparse_cost[i][j-1]+sparse_cost[a][j-1];
            }
        }
    }
}
int LCA(int p,int q)
{
    if(Level[p]<Level[q])swap(p,q);
    int Log=log2(Level[p])+1;
    int ans=0;
    for(int i=Log;i>=0;i--)
    {
        if((Level[p]-(1<<i))>=Level[q])
        {
            ans+=sparse_cost[p][i];
            p=sparse_table[p][i];
        }
    }
    if(p==q)return ans;
    for(int i=Log;i>=0;i--)
    {
        if(sparse_table[p][i]!=-1&&sparse_table[p][i]!=sparse_table[q][i])
        {
            ans+=sparse_cost[p][i]+sparse_cost[q][i];
            p=sparse_table[p][i],q=sparse_table[q][i];
        }
    }
    ans+=Cost[p]+Cost[q];
    ///Lca will be parent[p];
    return ans;
}
