const int Max=10000000;
bool prime_check[Max];
void sieve()
{
    int i,j;
    int sq = sqrt(Max);
    for(i=2; i<=sq; i++)
    {
        if(!prime_check[i])   // here check i is prime
        {
            for(j=i*i; j<Max; j+=i)
            {
                prime_check[j]=true; //j is multiple of i & make it not prime
            }
        }
    }
}
