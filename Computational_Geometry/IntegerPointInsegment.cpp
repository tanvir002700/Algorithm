int IntegerPointsOnSegment(const point &P1, const point &P2)
{
    point P;
    P.x=abs(P1.x-P2.x);
    P.y=abs(P1.y-P2.y);
    if(P.x==0) return P.y-1;
    if(P.y==0) return P.x-1;
    return (__gcd(P.x,P.y))-1;
}
