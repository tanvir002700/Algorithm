#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<iostream>
#include<assert.h>
using namespace std;
typedef pair<int,int> pp;
template<class T> T MAX3(T a,T b,T c) {return max(a,max(b,c));}
map<pp,set<pp> >slope;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        slope.clear();
        int N;
        cin>>N;
        int ans=0;
        set<pp>A,B;
        for(int i=0;i<N;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            int g=__gcd(a,b);
            int g2=__gcd(b,c);
            if(a==0)
            {
                int g=__gcd(b,c);
                b/=g;
                c/=g;
                A.insert(pp(-c,b));
                continue;
            }
            else if(b==0)
            {
                int g=__gcd(a,c);
                a/=g;
                c/=g;
                B.insert(pp(-c,a));
                continue;
            }
            slope[pp(a/g,b/g)].insert(pp(c/g2,b/g2));
        }
        for(auto x:slope)
        {
            int y=x.second.size();
            ans=max(ans,y);
        }
        ans=MAX3((int)A.size(),(int)B.size(),ans);
        cout<<ans<<endl;
    }
    return 0;
}