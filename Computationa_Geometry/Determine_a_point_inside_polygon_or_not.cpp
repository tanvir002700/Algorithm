#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
    point() {}
    point(int a,int b)
    {
        x=a,y=b;
    }
};
int trun(point p0,point p1,point p2)
{
    int result=(p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y);
    if(result>0)return 1;
    if(result < 0)return -1;
    return result;
}
bool on_segment(point pi,point pj,point pk)
{
    int minx=min(pi.x,pj.x);int maxx=max(pi.x,pj.x);
    int miny=min(pi.y,pj.y);int maxy=max(pi.y,pj.y);
    if(pk.x>=minx&&pk.x<=maxx&&pk.y>=miny&&pk.y<=maxy)return true;
    return false;
}
bool Segment_intersect(point p1,point p2,point p3,point p4)
{
    int d1=trun(p3,p4,p1);
    int d2=trun(p3,p4,p2);
    int d3=trun(p1,p2,p3);
    int d4=trun(p1,p2,p4);
    if((d1*d2<0)&&(d3*d4<0))return true;
    //if(d1==0&&on_segment(p3,p4,p1))return true;
    //if(d2==0&&on_segment(p3,p4,p2))return true;
    if(d3==0&&on_segment(p1,p2,p3))return true;
    if(d4==0&&on_segment(p1,p2,p4))return true;
    return false;
}
bool in_poligon(vector<point>p,point given,point inf2)
{
    int intersect=0;
    int N=p.size();
    for(int i=0;i<N;i++)
    {
        point p1=p[i];
        point p2=p[(i+1)%N];
        if(Segment_intersect(p1,p2,given,inf2))
        {
            intersect++;
        }
    }
    return intersect%2==1;
}
int main()
{
    int N;
    while(scanf("%d",&N)&&N)
    {
        int Max=-10005;
        vector<point>poligon;
        for(int i=0;i<N;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            poligon.push_back(point(x,y));
            Max=max(x,Max);
        }
        int x,y;
        scanf("%d %d",&x,&y);
        if(in_poligon(poligon,point(x,y),point(Max,y)))
        {
            printf("T\n");
        }
        else
        {
            printf("F\n");
        }
    }
    return 0;
}

