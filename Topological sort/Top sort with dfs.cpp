#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int> graph[100005];
vector<int> ans;
int visit[100005];
bool dfs(int u)
{
    visit[u]=GREY;
    bool no_cycle=true;
    int sz=graph[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=graph[u][i];
        if(visit[v]==WHITE)
        {
            no_cycle=dfs(v);
        }
        else if(visit[v]==GREY)return false;
    }
    visit[u]=BLACK;
    ans.push_back(u);
    return no_cycle;
}
bool topsort(int N)
{
    ans.clear();
    memset(visit,false,sizeof(visit));
    int no_cycle=true;
    for(int i=0;i<N;i++)
    {
        if(visit[i]==WHITE)no_cycle&=dfs(i);
    }
    return no_cycle;
}
int main()
{
    #ifdef _ANICK_
    //f_input;
    #endif // _ANICK_
    return 0;
}
