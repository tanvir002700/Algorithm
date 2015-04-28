///color will be initial with -1
int color[20005];
bool dfs(int u,int c)
{
    if(color[u]==c)return true;
    if(color[u]==(1-c))return false;
    color[u]=c;
    bool ret=true;
    for(auto v:graph[u])ret&=dfs(v,1-c);
    return ret;
}
