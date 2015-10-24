int big_mod(int n, int p, int m)
{
    if(!n) return 0;
    int x=(n, p>>1 , m);
    x= (x*x)%m;
    if(p&1) x=(x*n)%m;
    return x;
}
