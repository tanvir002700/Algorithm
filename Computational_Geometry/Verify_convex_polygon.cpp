int trun(point p0,point p1,point p2)
{
    int result=(p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y);
    return result;
}
bool isConvex(int n,vector<point>v)
{
    int pos=0,neg =0;
    for(int i = 0; i < n; i++)
    {
        int prev = (i + n -1) % n , next = (i  + 1) % n;
        point A=v[i];
        point B=v[prev];
        point C=v[next];
        int pv=trun(A,B,C);
        if(pv > 0) pos++;
        else
        {
            if(pv < 0) neg++;
        }
    }
    return (pos == 0) || (neg == 0);
}
