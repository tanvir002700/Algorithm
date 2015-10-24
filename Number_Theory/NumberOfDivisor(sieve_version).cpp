int nod[100000+5];
void Generate()
{
    nod[1]=1;
    for(int i=2; i<=100000; i++)
    {
        if(!nod[i])   //here checking i is prime or not ???
        {
            nod[i]=2;
            for(int j=i+i; j<=100000; j+=i)
            {
                if(!nod[j])nod[j]=1;
                int n=j,cnt=0;
                while(!(n%i))
                {
                    cnt++;
                    n/=i;
                }
                nod[j]*=(cnt+1);
            }
        }
    }
}
