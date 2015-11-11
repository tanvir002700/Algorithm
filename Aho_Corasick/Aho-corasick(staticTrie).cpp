#include<bits/stdc++.h>
using namespace std;
#define root 0
#define NuLL -1
#define Max 248878
#define MC 26
int ans[10000];
char text[1000005];
char inp[100000];
map<string,int>Map;
vector<int> v;
int getID(const char c)
{
    return c>='a'?c-'a':c-'A';
}
struct Trie
{
    struct node
    {
        int Next[26],fail;
        int stringMap;
        void clear()
        {
            memset(Next,-1,sizeof(Next));
            fail=-1;
            stringMap=0;
        }
    } T[Max];
    int ptr;
    void clear()
    {
        ptr=1;
        T[0].clear();
    }
    void Insert(char *str,int M)
    {
        int p=0;
        for(int i=0; str[i]; i++)
        {
            int id=getID(str[i]);
            if(T[p].Next[id]==-1)
            {
                T[p].Next[id]=ptr;
                T[ptr++].clear();
            }
            int q=p;
            p=T[p].Next[id];
        }
        T[p].stringMap=M;
    }
    void ComputeFailure()
    {
        queue<int>Q;
        Q.push(root);
        int u,prefix;
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            for(int i=0; i<MC; i++)
            {
                if(T[u].Next[i]!=NuLL)
                {
                    int now=T[u].Next[i];
                    prefix=T[u].fail;
                    while(prefix!=NuLL)
                    {
                        if(T[prefix].Next[i]!=NuLL)
                        {
                            T[now].fail=T[prefix].Next[i];
                            break;
                        }
                        prefix=T[prefix].fail;
                    }
                    if(prefix==NuLL)T[now].fail=root;
                    Q.push(now);
                }
            }
        }
    }
};
void AhoCorasick(const Trie &A, const char *str)
{
    int p=root;
    for(int i=0; str[i]; i++)
    {
        int id=getID(str[i]);
        while(A.T[p].Next[id]==NuLL&&p!=root)p=A.T[p].fail;
        if(p!=NuLL&&A.T[p].Next[id]!=NuLL)p=A.T[p].Next[id];
        int tp=p;
        while(tp!=root)
        {
            if(A.T[tp].stringMap>0)ans[A.T[tp].stringMap]++;
            tp=A.T[tp].fail;
        }
    }
}
Trie A;
int main()
{
#ifdef _ANICK_
    freopen("input.txt","r",stdin);
#endif // _ANICK_
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        Map.clear();
        v.clear();
        memset(ans,0,sizeof(ans));
        A.clear();
        int N;
        scanf("%d",&N);
        scanf("%s",text);
        int cnt=1;
        for(int i=0; i<N; i++)
        {
            scanf("%s",inp);
            if(Map.find(inp)==Map.end())Map[inp]=cnt++;
            A.Insert(inp,Map[inp]);
            v.push_back(Map[inp]);
        }
        A.ComputeFailure();
        AhoCorasick(A,text);
        printf("Case %d:\n",t);
        for(int i=0; i<N; i++)
        {
            printf("%d\n",ans[v[i]]);
        }
    }
    return 0;
}

