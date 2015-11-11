#include<bits/stdc++.h>
using namespace std;
#define Max 26
int getID(char c)
{
    return c>='a'?c-'a':c-'A';
}
char inp[1000005];
char text[1000005];
int ans[5000];
map<string,int>Map;
vector<int>v;
struct Trie
{
    Trie *next[26],*fail;
    int stringMap;
    Trie()
    {
        stringMap=0;
        for(int i=0; i<Max; i++)next[i]=NULL;
        fail=NULL;
    }
};
Trie *root;
void Insert(const char *str,int M)
{
    Trie *p=root;
    for(int i=0; str[i]; i++)
    {
        int id=getID(str[i]);
        if(p->next[id]==NULL)p->next[id]=new Trie();
        p=p->next[id];
    }
    p->stringMap=M;
}
void computeFailure()
{
    Trie *u,*prefix;
    queue<Trie*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        u=Q.front(); ///Take a new node
        Q.pop();
        for(int i=0; i<Max; i++)
        {
            if(u->next[i]!=NULL) ///select fail position of ith node of parent u
            {
                prefix=u->fail; /// Going to u node fail position/ prefix position
                while(prefix!=NULL)
                {
                    if(prefix->next[i]!=NULL) ///if match found
                    {
                        u->next[i]->fail=prefix->next[i];
                        break;
                    }
                    prefix=prefix->fail; /// match not found, going to upper child prefix position
                }
                if(prefix==NULL)u->next[i]->fail=root;
                Q.push(u->next[i]);
            }
        }
    }
}
void AhoCorasick(const char *str)
{
    Trie *p=root;
    for(int i=0; str[i]; i++)
    {
        int id=getID(str[i]);
        while(p->next[id]==NULL&&p!=root)p=p->fail;
        if(p->next[id]!=NULL)p=p->next[id];
        Trie *tp=p;
        while(tp!=root)
        {
            if(tp->stringMap>0)ans[tp->stringMap]++;
            tp=tp->fail;
        }
    }
}
void Delete(Trie *u)
{
    if(u==NULL)return;
    for(int i=0; i<Max; i++)Delete(u->next[i]);
    delete u;
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int t=1; t<=test; t++)
    {
        Map.clear();
        v.clear();
        memset(ans,0,sizeof(ans));
        root=new Trie();
        int N;
        scanf("%d",&N);
        scanf("%s",text);
        int cnt=1;
        for(int i=0; i<N; i++)
        {
            scanf("%s",inp);
            if(Map.find(inp)==Map.end())Map[inp]=cnt++;
            Insert(inp,Map[inp]);
            v.push_back(Map[inp]);
        }
        computeFailure();
        AhoCorasick(text);
        printf("Case %d:\n",t);
        for(int i=0; i<N; i++)
        {
            printf("%d\n",ans[v[i]]);
        }
        Delete(root);
    }
    return 0;
}

