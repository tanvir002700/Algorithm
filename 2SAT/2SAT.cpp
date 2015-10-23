/*
A or B
A’=>B
Algo Steps:
1. Construct Graph with A’->B & B’->A Edges
2. Find the Strongly Connected component of Graph & ranked them.
3. Check A & A’ is not in the same connected component. If in same group then, there is no solution
4.If there is solution exist, then solution will be higher rank between A & A’ node.
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
typedef vector<int> vint;
vint Graph1[5*8000];
vint Graph2[5*8000];
bool visit[5*8000];
int color[5*8000];
vint ans;
struct info
{
    int u,v;
    info(int u,int v):u(u),v(v){};
};
vector<info>Edges;
vint topsort;
void init(int N)
{
    Edges.clear();
    for(int i=0;i<=3*N;i++)
    {
        Graph1[i].clear();
        Graph2[i].clear();
    }
}
void construct_graph(int N)
{
    int sz=Edges.size();
    for(int i=0;i<sz;i++)
    {
        int u=Edges[i].u;
        int v=Edges[i].v;
        int a,b,acomp,bcomp;
        if(u>0)
        {
            a=2*u;
            acomp=2*u+1;
        }
        else
        {
            a=2*(-u)+1;
            acomp=2*(-u);
        }
        if(v>0)
        {
            b=2*v;
            bcomp=2*v+1;
        }
        else
        {
            b=2*(-v)+1;
            bcomp=2*(-v);
        }
        Graph1[acomp].pb(b);
        Graph1[bcomp].pb(a);
        Graph2[b].pb(acomp);
        Graph2[a].pb(bcomp);
    }
}
void dfs(int u)
{
    if(visit[u])return;
    visit[u]=true;
    int sz=Graph1[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=Graph1[u][i];
        dfs(v);
    }
    topsort.pb(u);
}
void dfs2(int u,int Rank)
{
    if(visit[u])return;
    visit[u]=true;
    color[u]=Rank;
    int sz=Graph2[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=Graph2[u][i];
        dfs2(v,Rank);
    }
}
void SCC(int N)
{
    topsort.clear();
    mem(visit,false);
    for(int i=2;i<=2*N+1;i++)
    {
        if(visit[i]==false)dfs(i);
    }
    int r=1;
    mem(visit,false);
    for(int i=topsort.size()-1;i>=0;i--)
    {
        if(visit[topsort[i]]==false)dfs2(topsort[i],r++);
    }
}
bool is2satpossible(int N)
{
    for(int i=1;i<=N;i++)
    {
        int a=2*i;
        int acomp=2*i+1;
        if(color[a]==color[acomp])return false;
    }
    return true;
}
void solution(int N)
{
    ans.clear();
    for(int i=1;i<=N;i++)
    {
        int a=2*i;
        int acomp=2*i+1;
        if(color[a]>color[acomp])ans.pb(i);
    }
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int M,N;
        scanf("%d %d",&M,&N);
        init(N);
        for(int i=0;i<M;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            Edges.pb(info(u,v));
        }
        construct_graph(N);
        SCC(N);
        printf("Case %d: ",t);
        if(is2satpossible(N))
        {
            cout<<"Yes"<<endl;
            solution(N);
            int sz=ans.size();
            printf("%d",sz);
            for(int i=0;i<sz;i++)printf(" %d",ans[i]);
            printf("\n");
        }
        else cout<<"No"<<endl;
    }
    return 0;
}
