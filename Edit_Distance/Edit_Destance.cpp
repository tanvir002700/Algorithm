#include<bits/stdc++.h>
using namespace std;
int dp[88][88];
int N,M,step;
char S1[88],S2[88];
int solve(int i,int j)
{
    if(i==N and j==M)return 0;
    if(i==N)return M-j;
    if(j==M)return N-i;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=(1<<28);
    if(S1[i]==S2[j])ret=solve(i+1,j+1);
    else
    {
        ret=min(ret,solve(i,j+1)+1);
        ret=min(ret,solve(i+1,j)+1);
        ret=min(ret,solve(i+1,j+1)+1);
    }
    return ret;
}
void pathPrint(int i,int j,int del,int ins,int st)
{
    if(i==N&&j==M) return ;
    if(i==N)
    {
        for(int k=j; k<M; k++,i++)
        {
            printf("%d Insert %d,%c\n",st++,i-del+1+ins,S2[k]);
        }
        return ;
    }
    if(j==M)
    {
        for(; i<N; i++)
        {
            printf("%d Delete %d\n",st++,i-del+1+ins);
            del++;
        }
        return ;
    }
    int ret = solve(i,j);
    int tmp;
    if(S1[i]==S2[j])
    {
        tmp=solve(i+1,j+1);
        if(ret==tmp)
        {
            pathPrint(i+1,j+1,del,ins,st);
            return ;
        }
    }
    tmp=solve(i,j+1)+1;
    if(tmp==ret)
    {
        printf("%d Insert %d,%c\n",st,i-del+1+ins,S2[j]);
        pathPrint(i,j+1,del,ins+1,st+1);
        return ;
    }
    tmp=solve(i+1,j)+1;
    if(tmp==ret)
    {
        printf("%d Delete %d\n",st,i-del+1+ins);
        pathPrint(i+1,j,del+1,ins,st+1);
        return ;
    }
    tmp=solve(i+1,j+1)+1;
    if(tmp==ret)
    {
        printf("%d Replace %d,%c\n",st,i-del+1+ins,S2[j]);
        pathPrint(i+1,j+1,del,ins,st+1);
        return ;
    }
    return ;
}
int main()
{
    bool New=false;
    while(gets(S1))
    {
        gets(S2);
        if(New)printf("\n");
        New=true;
        N=strlen(S1);
        M=strlen(S2);
        memset(dp,-1,sizeof(dp));
        step=solve(0,0);
        printf("%d\n",step);
        pathPrint(0,0,0,0,1);
    }
    return 0;
}


