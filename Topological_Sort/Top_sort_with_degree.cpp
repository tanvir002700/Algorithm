for(int i=1; i<=n; i++)
{
    for(int j=1; j<=n; j++)
    {
        if(deg[j]==0)
        {
            ans.pb(j);
            int sz=graph[j].size();
            for(int k=0; k<sz; k++)
            {
                deg[graph[j][k]]--;
            }
            deg[j]=-1;
            break;
        }
    }
}
