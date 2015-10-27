const int Max=1000000;
bool prime_check[Max+5];
vint prime;
void sieve()
{
    int i,j;
    int sq=sqrt(Max);
    for(i=2;i*i<=Max;i++)
    {
        if(!prime_check[i])
        {
            prime.pb(i);
            for(j=i*i;j<=Max;j+=i)
            {
                prime_check[j]=true;
            }
        }
    }
    for(i=sq+1;i<=Max;i++)
    {
        if(!prime_check[i])prime.pb(i);
    }
}
