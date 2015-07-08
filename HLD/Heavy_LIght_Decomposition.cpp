/*
    Tanvir Hasan Anick
    University of Asia pacific
*/
/**Header file**/
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<list>
#include<iostream>
#include<assert.h>

/**Define file I/O **/
#define f_input freopen("input.txt","r",stdin)
#define f_output freopen("output.txt","w",stdout)

/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))

/**Define function and object**/
#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define RSort(v) sort(v.rbegin(),v.rend())
#define CSort(v,C) sort(v.begin(),v.end(),C)
#define all(v) (v).begin(),(v).end()
#define sqr(x) ((x)*(x))
#define find_dist(a,b) sqrt(sqr(a.x-b.x)+sqr(a.y-b.y))

/**Define constant value**/
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793

/**Define input**/
#define scanint(a) scanf("%d",&a)
#define scanLLD(a) scanf("%lld",&a)
#define scanstr(s) scanf("%s",s)
#define scanline(l) scanf(" %[^\n]",l);

/**Define Bitwise operation**/
#define check(n, pos) (n & (1<<(pos)))
#define biton(n, pos) (n | (1<<(pos)))
#define bitoff(n, pos) (n & ~(1<<(pos)))

/**Define color**/
#define WHITE 0
#define GREY 1
#define BLACK 2

/**Sync off with stdio**/
#define __ cin.sync_with_stdio(false);\
           cin.tie();

using namespace std;

/**Typedef**/
typedef vector<int> vint;
typedef vector< vint > vint2D;
typedef vector<string> vstr;
typedef vector<char>vchar;
typedef vector< vchar >vchar2D;
typedef queue<int> Qi;
typedef queue< Qi > Qii;
typedef map<int,int> Mii;
typedef map<string,int> Msi;
typedef map<int,string> Mis;
typedef stack<int> stk;
typedef pair<int,int> pp;
typedef pair<int, pp > ppp;
typedef long long int LLD;
const int inf=0x7FFFFFFF;

/**Template & structure**/
namespace my{
struct point_int{int x,y;point_int(){}point_int(int a,int b){x=a,y=b;}}; ///Point for x,y (int) coordinate in 2D space
struct point_double{double x,y;point_double(){}point_double(double a,double b){x=a,y=b;}}; ///Point for x,y (double) coordinate in 2D space
struct Node{int v,w;Node() {}bool operator<(const Node &a)const{return w>a.w;}Node(int _v,int _w){v=_v,w=_w;}};///Node for Dijkstra
template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}
template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}
template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}
template<class T>T multiplication(T n,T p,T m){if(p==0)return (T)0;T x=multiplication(n,p/2,m);x=(x+x)%m;if(p&1)x=(x+n)%m;return x;}
template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}/// distance between a & b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}/// extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}/// convert a number to string
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} ///For Positive Negative No.
template<class T> T MIN3(T a,T b,T c) {return min(a,min(b,c));} /// minimum of 3 number
template<class T> T MAX3(T a,T b,T c) {return max(a,max(b,c));} ///maximum of 3 number
template <class T> void print_vector(T &v){int sz=v.size();if(sz)cout<<v[0];for(int i = 1; i < sz; i++)cout << ' '<<v[i];cout<<endl;}/// prints all elements in a vector
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConsonant(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}}
/**Shortcut input function**/
int read_int(){int n;scanf("%d",&n);return n;}
int read_LLD(){LLD n;scanf("%lld",&n);return n;}
inline int buffer_input() { char inp[1000]; scanstr(inp); return atoi(inp); }

/**Direction**/
///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};int row[8] = {1, 1, 0, -1, -1, -1, 0, 1}; ///8 Direction
///int col[4] = {1, 0, -1, 0};int row[4] = {0, 1, 0, -1}; ///4 Direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; ///Hexagonal Direction


/******************************Ajaira Jinish Sesh******************************/

const int Max=10000;
struct info
{
    int v,cost;
    info(int v=0,int cost=0):v(v),cost(cost){};
};
vector<pp>edges;
vector<info>Graph[Max+5];
int Tree[5*Max+5],BaseArray[Max+5],SubTreeSize[Max+5];
int ChainHead[Max+5],ChainNum[Max+5],PosInBaseArray[Max+5],ChainNo;
int Level[Max+5],Parent[Max+5],SparseTable[Max+5][16];
int ptr;
void init(int N)
{
    for(int i=0;i<=N;i++)
    {
        Graph[i].clear(),ChainHead[i]=-1;
        for(int j=0;j<=15;j++)SparseTable[i][j]=-1;
    }
    edges.clear();
    ptr=ChainNo=0;
}
void buildSegmentTree(int l,int r,int indx)
{
    if(l==r)
    {
        Tree[indx]=BaseArray[l];
        return;
    }
    int mid=(l+r)>>1;
    int lindx=indx<<1;
    int rindx=lindx|1;
    buildSegmentTree(l,mid,lindx);
    buildSegmentTree(mid+1,r,rindx);
    Tree[indx]=max(Tree[lindx],Tree[rindx]);
}
void updateSegmentTree(int l,int r,int indx,int update_indx,int value)
{
    if(l==r)
    {
        Tree[indx]=value;
        return;
    }
    int mid=(l+r)>>1;
    int lindx=indx<<1;
    int rindx=lindx|1;
    if(update_indx<=mid)updateSegmentTree(l,mid,lindx,update_indx,value);
    else updateSegmentTree(mid+1,r,rindx,update_indx,value);
    Tree[indx]=max(Tree[lindx],Tree[rindx]);
}
int querySegmentTree(int l,int r,int indx,int x,int y)
{
    if(l>y||r<x)return 0;
    if(x<=l&&y>=r)return Tree[indx];
    int mid=(l+r)>>1;
    int lindx=indx<<1;
    int rindx=lindx|1;
    int c1=0,c2=0;
    if(x<=mid)c1=querySegmentTree(l,mid,lindx,x,y);
    if(y>mid)c2=querySegmentTree(mid+1,r,rindx,x,y);
    return max(c1,c2);
}
void dfs(int from,int u,int depth)
{
    Level[u]=depth;
    Parent[u]=from;
    SubTreeSize[u]=1;
    int sz=Graph[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=Graph[u][i].v;
        if(v==from)continue;
        dfs(u,v,depth+1);
        SubTreeSize[u]+=SubTreeSize[v];
    }
}
void sparseTable(int N)
{
    for(int i=0;i<=N;i++)SparseTable[i][0]=Parent[i];
    for(int j=1;(1<<j)<=N;j++)
    {
        for(int i=0;i<=N;i++)
        {
            if(SparseTable[i][j-1]!=-1)
            {
                int a=SparseTable[i][j-1];
                SparseTable[i][j]=SparseTable[a][j-1];
            }
        }
    }
}
int LCA(int p,int q)
{
    if(Level[p]<Level[q])swap(p,q);
    int Log=log2(Level[p])+1;
    for(int i=Log;i>=0;i--)
    {
        if((Level[p]-(1<<i))>=Level[q])p=SparseTable[p][i];
    }
    if(p==q)return p;
    for(int i=Log;i>=0;i--)
    {
        if(SparseTable[p][i]!=-1&&SparseTable[p][i]!=SparseTable[q][i])
        {
            p=SparseTable[p][i],q=SparseTable[q][i];
        }
    }
    return Parent[p];
}
/**
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 **/
void heavyLightDecompositon(int from,int curNode,int cost)
{
    if(ChainHead[ChainNo]==-1)ChainHead[ChainNo]=curNode; /// Assign chain head
    ChainNum[curNode]=ChainNo;
    PosInBaseArray[curNode]=ptr; /// Position of this node in baseArray which we will use in Segtree
    BaseArray[ptr++]=cost;
    int sc=-1,nextCost;
    int sz=Graph[curNode].size();
    for(int i=0;i<sz;i++)  /// Loop to find special child
    {
        int v=Graph[curNode][i].v;
        if(v==from)continue;
        if(sc==-1||SubTreeSize[sc]<SubTreeSize[v])
        {
            sc=v;
            nextCost=Graph[curNode][i].cost;
        }
    }
    if(sc!=-1)heavyLightDecompositon(curNode,sc,nextCost); /// Expand the chain
    for(int i=0;i<sz;i++)
    {
        int v=Graph[curNode][i].v;
        int cost=Graph[curNode][i].cost;
        if(v==from||sc==v)continue;
        ChainNo++;
        heavyLightDecompositon(curNode,v,cost);
    }
}
void updateTree(int ith,int val)
{
    pp a=edges[ith];
    int u=a.first,v=a.second;
    int indx=PosInBaseArray[u];
    if(Level[u]<Level[v])indx=PosInBaseArray[v];
    updateSegmentTree(0,ptr-1,1,indx,val);
}
/**
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 **/
int queryUp(int u,int v)
{
    if(u==v)return 0;
    int uchain,vchain=ChainNum[v],ans=-1;
    while(true)
    {
        uchain=ChainNum[u];
        if(uchain==vchain)
        {
            if(u==v)        /// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
                break;      /// We break because we came from u up till v, we are done
            ans=max(ans,querySegmentTree(0,ptr-1,1,PosInBaseArray[v]+1,PosInBaseArray[u]));
            break;
        }
        int uchainhead=ChainHead[uchain];
        ans=max(ans,querySegmentTree(0,ptr-1,1,PosInBaseArray[uchainhead],PosInBaseArray[u]));
                    /// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        u=Parent[uchainhead];
    }
    return ans;
}
int queryTree(int u,int v)
{
    int lca=LCA(u,v);
    return max(queryUp(u,lca),queryUp(v,lca));
}
int main()
{
    #ifdef _ANICK_
    //f_input;
    #endif // _ANICK_
    __
    int test;
    cin>>test;
    while(test--)
    {
        int N;
        cin>>N;
        init(N);
        for(int i=0;i<N-1;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            u--,v--;
            Graph[u].pb(info(v,c));
            Graph[v].pb(info(u,c));
            edges.pb(pp(u,v));
        }
        dfs(-1,0,0);
        sparseTable(N);
        heavyLightDecompositon(-1,0,-1);
        buildSegmentTree(0,ptr-1,1);
        string ch;
        int x,y;
        while(true)
        {
            cin>>ch;
            if(ch[0]=='D')break;
            cin>>x>>y;
            if(ch[0]=='Q')printf("%d\n",queryTree(x-1,y-1));
            else if(ch[0]=='C')updateTree(x-1,y);
        }
    }
    return 0;
}
