const int MX = 1000005 ;
int grunday[MX] , rev[6] = { 1 , 4 , 27, 256, 3125, 46656} ; // in a single move n*n can be removed
int Cal(int x)
{
    if( x == 0 ) return 0 ; // base case , grunday is always zero
    int &ret = grunday[x];
    if( ret != -1 ) return ret;
    set <int> s ;
    int i ;
    for (i = 0 ;  i < 6 ; i++ )
    {
        if( x - rev[i] >= 0 )
            s.insert(Cal(x-(rev[i])));
    }
    int ans = 0 ;
    while(s.find(ans) != s.end()) ans++;
    return ret = ans ;
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    memo(grunday,-1);
    int cs , t ;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int n , i , ans = 0 , x ;
        scanf("%d",&n);
        for ( i = 0 ; i < n ; i++ )
        {
            scanf("%d",&x);
            ans ^= Cal(x);
        }
        if( ans ) puts("Little Chef"); // first mover win
        else puts("Head Chef");
    }

    return 0;
}
