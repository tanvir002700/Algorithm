///N/1+N/2+N/3+.........+N/N= ?
LLD calculate(LLD n)
{
    LLD ans=0;
    LLD sq=sqrt(n);
    for(int i=1;i<=sq;i++)
    {
        LLD temp1=n/i;
        LLD temp2=n/(i+1);
        if(temp1!=sq)
        {
            ans+=temp1;
        }
        LLD freq=temp1-temp2;
        if(freq>0)
        {
            ans+=(i*(freq));
        }
    }
    return ans;
}
