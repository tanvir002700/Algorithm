int find_divisor(int n)
{
    int i,ans=1,count=1;
    while(n%2==0)
    {
        n/=2;
        count++;
    }
    ans*=count;
    for(i=3; i*i<=n; i+=2)
    {
        count=1;
        while(n%i==0)
        {
            n/=i;
            count++;
        }
        ans*=count;
    }
    if(n>1)
    {
        ans*=2;
    }
    return ans;
}

