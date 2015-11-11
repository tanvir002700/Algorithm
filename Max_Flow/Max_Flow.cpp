#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MN 1000
typedef vector< vector<int> > vint2D;
const int inf=(1<<29);
vint2D graph;
int Cost[MN][MN];
int parent[MN+5];
int flow;
void init(int N)
{
    graph=vint2D(N);
    memset(Cost,0,sizeof(Cost));
}
void AddEdge(int u,int v,int cost)
{
    graph[u].pb(v);
    graph[v].pb(u);
    Cost[u][v]+=cost;
    Cost[v][u]+=cost;
}
bool augmenting_path(int source,int sink)
{
    memset(parent,-1,sizeof(parent));
    queue<int>Q;
    Q.push(source);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int sz=graph[u].size();
        for(int i=0; i<sz; i++)
        {
            int v=graph[u][i];
            if(parent[v]==-1 and Cost[u][v]>0)
            {
                parent[v]=u;
                Q.push(v);
                if(v==sink)return true;
            }
        }
    }
    return false;
}
void path(int v,int source)
{
    int u=parent[v];
    flow=min(flow,Cost[u][v]);
    if(source!=u)path(u,source);
    Cost[u][v]-=flow;
    Cost[v][u]+=flow;
    return;
}
int max_flow(int source,int sink)
{
    int ret=0;
    while(augmenting_path(source,sink))
    {
        flow=inf;
        path(sink,source);
        ret+=flow;
    }
    return ret;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int P,S,C,M;
        scanf("%d %d %d %d",&P,&S,&C,&M);
        init(P+S+5);
        int superSource=0,SuperSikn=P+S+1;
        for(int i=1; i<=P; i++)AddEdge(superSource,i,1);
        for(int i=1; i<=S; i++)AddEdge(P+1,SuperSikn,C);
        for(int i=0; i<M; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            AddEdge(x,P+y,(1<<30));
        }
        printf("%d\n",max_flow(superSource,SuperSikn));
    }
    return 0;
}
