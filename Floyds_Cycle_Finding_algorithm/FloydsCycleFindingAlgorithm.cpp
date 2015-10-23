#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
int Z,L,M,I;
int f(int L)
{
    return (Z*L+I)%M;
}
pp CycleFinding()
{
    ///L here initial seed
    int hare,tortoise,lambda,meu;
    bool cyclefind=false;
    hare=tortoise=L;
    while(!cyclefind)
    {
        tortoise=f(tortoise);
        hare=f(hare);
        hare=f(hare);
        if(hare==tortoise)cyclefind=true;
    }
    hare=L;
    meu=0;
    while(hare!=tortoise)
    {
        meu++;
        hare=f(hare);
        tortoise=f(tortoise);
    }
    int i=0;
    hare=L;
    while(i<=meu)
    {
        i++;
        hare=f(hare);
    }
    tortoise=f(hare);
    lambda=1;
    while(hare!=tortoise)
    {
        tortoise=f(tortoise);
        lambda++;
    }
    return {meu,lambda}; ///meu is starting index and lambda is cycle length
}
int main()
{
    int t=1;
    while(scanf("%d %d %d %d",&Z,&I,&M,&L) and (Z or I or M or L))
    {
        pp a=CycleFinding();
        cout<<"Cycle starts from index "<<a.first<<"\nCycle length is "<<a.second<<endl;
    }
    return 0;
}
