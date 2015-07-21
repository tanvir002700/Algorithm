/**
    There is N stone of pile, every player in each move can remove Move[i] stone. If Any move there is no Stone remain
    these player will be lost.
**/
#include<bits/stdc++.h>
using namespace std;
int Move[100],k,n;
int dp[1000000+5];
bool is_valid(int x)
{
    return x>=0;
}
bool solve(int sum)
{
    if(sum==0)return false;
    if(dp[sum]!=-1)return dp[sum];
    for(int i=1;i<=k;i++)
    {
        if(is_valid(sum-Move[i]) and !solve(sum-Move[i]))return dp[sum]=true;
    }
    return dp[sum]=false;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&Move[i]);
        }
        memset(dp,-1,sizeof(dp));
        if(solve(n))printf("A\n");
        else printf("B\n");
    }
    return 0;
}

