void find_bridge(int node, int parent)
{
    discovery_time[node] = bedge[node] = ++T;
    int to, i, connected = adj[node].size();
    for(i = 0; i < connected; i++)
    {
        to = adj[node][i];
        if(to == parent) continue;
        if(!discovery_time[to])
        {
            printf("%d %d\n", node, to);
            find_bridge(to, node);
            bedge[node] = min(bedge[node], bedge[to]);
            if(bedge[to] > discovery_time[node]) printf("%d %d\n", to, node);
        }
        else if(discovery_time[node] > discovery_time[to])
        {
            printf("%d %d\n", node, to);
            bedge[node] = min(bedge[node], discovery_time[to]);
        }
    }
}

