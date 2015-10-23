#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
typedef long long LLD;
LLD FAC[22];
int Freq[27];
string S;
void FACTORIAL()
{
    FAC[0]=1;
    for(int i=1;i<=20;i++)FAC[i]=FAC[i-1]*i;
}
LLD Permutation(int n)
{
    LLD per=FAC[n];
    for(int i=0;i<26;i++)per/=FAC[Freq[i]];
    return per;
}
string NthPermutation(int nth)
{
    string ans="";
    int len=S.size();
    while(len)
    {
        LLD upto=0;
        for(int i=0;i<26;i++)
        {
            if(Freq[i])
            {
                Freq[i]-=1;
                LLD now=Permutation(len-1);
                if(upto+now>=nth)
                {
                    nth-=upto;
                    ans+=('a'+i);
                    len--;
                    break;
                }
                else
                {
                    upto+=now;
                    Freq[i]+=1;
                }
            }
        }
    }
    return ans;
}
int main()
{
    FACTORIAL();
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        mem(Freq,0);
        char inp[100];
        LLD Nth;
        scanf("%s %lld",inp,&Nth);
        S=inp;
        for(int i=0;inp[i];i++)Freq[inp[i]-'a']++;
        string Ans="Impossible";
        if(Permutation(S.size())>=Nth)
        {
            Ans=NthPermutation(Nth);
        }
        printf("Case %d: %s\n",t,Ans.c_str());
    }
    return 0;
}
