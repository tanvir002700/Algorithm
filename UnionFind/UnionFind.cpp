int parent[10000];
void init(int N)
{
    	for(int i=0;i<=N;i++)
       	 parent[i]=i;
}
int Find(int r)
{
    	if(parent[r]==r)return r;
    	return parent[r]=Find(parent[r]);
}
void make_parent(int p,int q)
{
    	parent[p]=q;
}
void check(int x,int y)
{
    	int p=Find(x);
    	int q=Find(y);
    	if(p!=q)
    	{
        		make_parent(p,q);
        		printf("Make friend\n");
        		return;
    	}
    	printf("they allready friend\n");
    	return;
}
