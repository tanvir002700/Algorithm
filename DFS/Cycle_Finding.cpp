int color[20005];
bool dfs(int u)
{
    color[u]=GREY;
    bool no_cycle=true;
    for(auto v:graph[u])
    {
        if(color[v]==WHITE)
        {
            no_cycle=dfs(v);
        }
        else if(color[v]==GREY)return false;
    }
    color[u]=BLACK;
    return no_cycle;
}
