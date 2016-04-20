LLD RangeSum(LLD a,LLD b)
{
    if(b<a)return 0;
    LLD x=((a-1)*a)/2;
    LLD y=(b*(b+1))/2;
    return y-x;
}
LLD sumOfDiv(LLD n)
{
    LLD sq=sqrt(n);
    LLD sum=0;
    for(LLD i=1;i<=sq;i++)
    {
        LLD x=n/i;
        sum+=x*i;
        LLD y=n/(i+1);
        if(x!=i)
        {
            sum+=RangeSum(y+1,x)*i;
        }
    }
    return sum;
}
