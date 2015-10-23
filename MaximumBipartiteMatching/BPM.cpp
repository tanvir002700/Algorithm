bool khun(int u)
{
    int sz=graph[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=graph[u][i];
        if(seen[v])continue;
        seen[v]=true;
        if(Right[v]==-1||khun(Right[v]))
        {
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching(int m)
{
    mem(Left,-1);
    mem(Right,-1);
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        mem(seen,false);
        if(khun(i))cnt++;
    }
    return cnt;
}
