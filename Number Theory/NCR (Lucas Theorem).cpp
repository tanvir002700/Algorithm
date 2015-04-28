/**
    Fine NCR % M when N C M are large number.
    using Lucas theorem.
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long LLD;
LLD mod=1000003;
LLD big_mod(LLD n,LLD p,LLD m)
{
    if(p==0)return (LLD)1;
    LLD x=big_mod(n,p/2,m);
    x=(x*x)%m;
    if(p&1)x=(x*n)%m;
    return x;
}
LLD inverse_modulo(LLD t,LLD m)
{
    return big_mod(t,m-2,m);
}
LLD combi(LLD n, LLD k,LLD m)
{
    if(n<k)
        return 0;
    if(n-k<k)
        return combi(n,n-k,m);
    LLD i,p=1,t=1;
    for(i=n-k+1; i<=n; i++)
        p=(p*i)%m;
    for(i=1; i<=k; i++)
        t=(t*i)%m;
    return (p*inverse_modulo(t,m))%m;
}
LLD lucas(LLD n, LLD k, LLD m)
{
    if(n<k)
        return 0;
    if(k==0 || n==k)
        return 1;
    return (lucas(n/m,k/m,m)*combi(n%m,k%m,m))%m;
}
int main()
{
    return 0;
}
