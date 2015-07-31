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
enum {WHITE,GREY,BLACK};

/**Sync off with stdio**/
#define __ cin.sync_with_stdio(false);\
           cin.tie();
/**Debug tools**/
#define what_is(x) cerr<<(#x)<<" is "<<x<<endl
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
struct point_int{int x,y;point_int(){}point_int(int a,int b){x=a,y=b;}
    bool operator==(const point_int &a)const{return x==a.x and y==a.y;}
}; ///Point for x,y (int) coordinate in 2D space
struct point_double{double x,y;point_double(){}point_double(double a,double b){x=a,y=b;}}; ///Point for x,y (double) coordinate in 2D space
struct Node{int v,w;Node() {}bool operator<(const Node &a)const{return w>a.w;}Node(int _v,int _w){v=_v,w=_w;}};///Node for Dijkstra
namespace my{
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
template <class T> void print_vector(T &v){int sz=v.size();if(sz)cout<<v[0];for(int i = 1; i < sz; i++)cout << ' '<<v[i];cout<<"\n";}/// prints all elements in a vector
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
const int MAX =3*5005;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
}arr[MAX];

int sorted[18][MAX], LCP[MAX], step;
string text;

bool comp(const info &a, const info &b)
{
    return a.tup[0] != b.tup[0]? a.tup[0] < b.tup[0] : a.tup[1] < b.tup[1];
}

void build_suffix_array(void)
{
    int i, n = text.size(), jump;
    for(i = 0; i < n; i++)
    {
        sorted[0][i] = text[i] - 'A'; ///rank suffixes according to 1st char
        memset(arr[i].tup, 0,sizeof(arr[i].tup));
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(i = 0; i <=n; i++)
        {
            arr[i].indx = i;
            arr[i].tup[0] = sorted[step - 1][i]; /// what i was in prev step
            arr[i].tup[1] = i + jump < n? sorted[step - 1][i + jump] : -1;
        }
        sort(arr, arr + n, comp);
        sorted[step][arr[0].indx] = 0;
        for(i = 1; i < n; i++)
            sorted[step][arr[i].indx] = arr[i].tup[0] == arr[i - 1].tup[0] &&
            arr[i].tup[1] == arr[i - 1].tup[1] ? sorted[step][arr[i - 1].indx] : i;
    }
//    cout << "Suffix Array : \n\n";
//    for(i = 0; i < n; i++)
//        cout<<arr[i].indx<<' '<<text.substr(arr[i].indx)<<endl;
}


void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        //cout << "id" << id1 << ' ' << id2 << endl;
        //cout << sorted[0][id1] << ' ' << sorted[0][id2] << endl;
        for(j = step - 1; j >= 0; j--)
            if(sorted[j][id1] == sorted[j][id2] && sorted[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
//        cout << arr[i - 1].indx << ' ' << arr[i].indx << ' ' << LCP[i] << endl;
    }
//    for(i = 0; i < n; i++)
//        cout << i << ' ' << LCP[i] << endl;
}
pp Index[3];
int Position(int indx)
{
    for(int i=0;i<3;i++)
    {
        if(indx>=Index[i].first and indx<Index[i].second)return i;
    }
    return -1;
}
bool Ok(int val)
{
    for(int i=1;i<text.size();i++)
    {
        if(LCP[i]>=val)
        {
            bool a,b,c;
            a=b=c=false;
            int indx=Position(arr[i].indx);
            if(indx==-1)continue;
            indx==0?a=true:indx==1?b=true:indx==2?c=true:c=false;
            indx=Position(arr[i-1].indx);
            indx==0?a=true:indx==1?b=true:indx==2?c=true:c=false;
            int r=i+1;
            while(r<text.size() and LCP[r]>=val and !(a and b and c))
            {
                indx=Position(arr[r].indx);
                indx==0?a=true:indx==1?b=true:indx==2?c=true:c=false;
                r++;
            }
            if(a and b and c)return true;
        }
    }
    return false;
}
int main()
{
    #ifdef _ANICK_
    //f_input;
    #endif // _ANICK_
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        char s[5005];
        text.clear();
        for(int i=0;i<3;i++)
        {
            scanf("%s",s);
            Index[i].first=text.size();
            text+=s;
            Index[i].second=text.size();
            if(i!=2)text+="#";
        }
        build_suffix_array();
        build_LCP_array();
        int ans=0;
        int low=0,high=text.size();
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(Ok(mid))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
