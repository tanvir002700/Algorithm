typedef vector<int> vint;
vint G[100000+5];
vint G2[100000+5];
vint sorted;
vint cycle;
bool color[100000+5];
void dfs(int u)
{
    color[u]=false;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(color[v])
        {
            dfs(v);
        }
    }
    sorted.pb(u);
}
void dfs2(int u)
{
    cycle.pb(u);
    color[u]=false;
    for(int i=0; i<G2[u].size(); i++)
    {
        int v=G2[u][i];
        if(color[v])
        {
            dfs2(v);
        }
    }
}
void SCC(int N)
{
    mem(color,true);
    for(int i=1; i<=N; i++)
    {
        if(color[i])
        {
            dfs(i);
        }
    }
    mem(color,true);
    for(int i=sorted.size()-1; i>=0; i--)
    {
        int u=sorted[i];
        if(color[u])
        {
            cycle.clear();
            dfs2(u);
            print_vector(cycle);
        }
    }
}
