int Bit[50][50];
int Max=35;
void update(int x,int y)
{
    while(x<=Max)
    {
        int Yy=y;
        while(Yy<=Max)
        {
            Bit[x][Yy]++;
            Yy+=(Yy&-Yy);
        }
        x+=(x&-x);
    }
}
int query(int x,int y)
{
    int ret=0;
    while(x>0)
    {
        int Yy=y;
        while(Yy>0)
        {
            ret+=Bit[x][Yy];
            Yy-=(Yy&-Yy);
        }
        x-=(x&-x);
    }
    return ret;
}
int racQuery(int x1,int y1,int x2,int y2)
{
    int Full=query(x2,y2);
    int add=query(x1-1,y1-1);
    int sub1=query(x1-1,y2);
    int sub2=query(x2,y1-1);
    return Full-sub1-sub2+add;
}

