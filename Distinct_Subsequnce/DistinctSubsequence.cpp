LLD solve()
{
    dp[0]=1;
    mem(Last_occurance,0);
    for(int i=1;s[i];i++)
    {
        dp[i]=2*dp[i-1];
        int x=s[i]-'A';
        if(Last_occurance[x])dp[i]-=dp[Last_occurance[x]-1];
        Last_occurance[x]=i;
        dp[i]=dp[i];
    }
    return dp[strlen(s+1)];
}
