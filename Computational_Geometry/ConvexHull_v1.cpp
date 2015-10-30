POINT P0;
int area2(POINT p0,POINT p1,POINT p2)
{
    return (p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y);
}
int dist2(POINT a,POINT b)
{
    int dx=a.x-b.x,dy=a.y-b.y;return dx*dx+dy*dy;
}
bool angle_comp(POINT a,POINT b)
{
    if(area2(P0,a,b)<0)return true;
    else if(area2(P0,a,b)==0)return dist2(P0,a)<dist2(P0,b);
    return false;
}

vector<POINT> Find_convex_hull(vector<POINT>P)
{
    int i,N=(int)P.size();
    int po=0;
    for ( i=0; i<N; i++)
    {
        if(P[i].y < P[po].y || (P[i].y== P[po].y && P[i].x < P[po].x))po=i;
    }
    P0 = P[po];
    sort(P.begin(),P.end(),angle_comp);
    POINT prev(0,0),now(0,0);
    stack<POINT> S;
    S.push(P0);
    i=1;
    while(i<N)
    {
        if(S.size()<2)
        {
            S.push(P[i++]);
        }
        else
        {
            now = S.top();
            S.pop();
            prev=S.top();
            S.push(now);
            if(area2(prev,now,P[i])<0)
                S.push(P[i++]);
            else S.pop();
        }
    }

    vector<POINT> ConvexHull;
    ConvexHull.push_back(P0);
    while(!S.empty())
    {

        ConvexHull.push_back(S.top());
        S.pop();
    }
    return ConvexHull;
}
