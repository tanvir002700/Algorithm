vector<int>Graph[10000];
bool visit[10000];
int arti[100000];
int discover[100000],Back[100000];
int predfn;
int source;
int child_of_root;
int cnt=0;
void reset()
{
    memset(visit,false,sizeof(visit));
    memset(arti,false,sizeof(arti));
    predfn=child_of_root=0;
}
void articulation(int v)
{
    visit[v]=true;
    predfn++;
    discover[v]=Back[v]=predfn;
    for(int i=0;i<Graph[v].size();i++)
    {
        int w=Graph[v][i];
        if(!visit[w])
        {
            articulation(w);
            Back[v]=min(Back[v],Back[w]);
            if(Back[w]>=discover[v]&&v!=source)
            {
                arti[v]=true;
            }
            else if(v==source)
            {
                child_of_root++;
                if(child_of_root==2)
                {
                    arti[v]=true;
                }
            }
        }
        else
        {
            Back[v]=min(Back[v],discover[w]);
        }
    }
}
