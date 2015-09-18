#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
int positionK[505][505];
int Csum[505];
int main()
{
    int N;
    while(scanf("%d",&N)==1)
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&Csum[i]);
            Csum[i]+=Csum[i-1];
        }
        for(int L=1;L<=N;L++)
        {
            for(int i=1;i<=N;i++)
            {
                int j=L+i-1;
                if(j>N)continue;
                if(L==1)
                {
                    dp[i][j]=0;
                    positionK[i][j]=i;
                }
                else
                {
                    dp[i][j]=(1<<28);
                    for(int k=positionK[i][j-1];k<=positionK[i+1][j];k++)
                    {
                        int cost=dp[i][k-1];
                        cost+=dp[k+1][j];
                        cost+=(Csum[j]-Csum[k]);
                        cost+=(Csum[k-1]-Csum[i-1]);
                        if(cost<dp[i][j])
                        {
                            dp[i][j]=cost;
                            positionK[i][j]=k;
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[1][N]);
    }
    return 0;
}
