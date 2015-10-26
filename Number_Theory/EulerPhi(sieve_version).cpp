int phi[10000];
const int M=1000;
void Generate_phi()
{
    int i,j;
    phi[1]=1;
    for(i=2; i<M; i++)
    {
        if(!phi[i])
        {
            phi[i]=i-1;
            for(j=i+i; j<M; j+=i)
            {
                if(!phi[j])phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
