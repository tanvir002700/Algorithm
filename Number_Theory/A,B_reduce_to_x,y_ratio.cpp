int main()
{
    int A,B,x,y;
    cin>>A>>B>>x>>y;
    int g=__gcd(x,y);
    x/=g,y/=g;
    int t=min(A/x,B/y);
    cout<<x*t<<" "<<y*t<<endl;
    return 0;
}
