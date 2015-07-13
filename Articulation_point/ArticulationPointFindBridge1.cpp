#include<bits/stdc++.h>
using namespace std;
vector<int>Graph[200];
int Back[205],Discover[205];
bool visit[205];
bool bridge[205][205];
int brcount;
void reset(int n)
{
    for(int i=0;i<=n;i++)Graph[i].clear();
    memset(visit,false,sizeof(visit));
    memset(bridge,false,sizeof(false));
    brcount=0;
}
void find_bridge(int u, int parent, int depth)
{
    visit[u] = true;
    Discover[u] = Back[u] = depth;

    for (int i=0 ; i<Graph[u].size() ; i++)
    {
        int v = Graph[u][i];

        if (visit[v] && v!=parent)
        {
            Back[u] = min(Back[u],Discover[v]);
        }
        if (!visit[v])
        {
            find_bridge(v, u, depth+1);
            Back[u] = min(Back[u],Back[v]);
            if (Back[v]>Discover[u])
            {
                brcount++;
                bridge[u][v] = bridge[v][u] = true;
            }
        }
    }

}
