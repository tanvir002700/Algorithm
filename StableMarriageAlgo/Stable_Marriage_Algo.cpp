const int Max=400;
int position[Max][Max];
int Husband[Max];
queue<int>womenlist[Max];
void stable_marage(int N)
{
    mem(Husband,-1);
    queue<int>freeman;
    for(int i=1;i<=N;i++)freeman.push(i);
    while(!freeman.empty())
    {
        int man=freeman.front();
        int woman=womenlist[man].front();
        womenlist[man].pop();
        if(Husband[woman]==-1)
        {
            Husband[woman]=man;
            freeman.pop();
        }
        else
        {
            int herhusband=Husband[woman];
            if(position[woman][man]<position[woman][herhusband])
            {
                Husband[woman]=man;
                freeman.pop();
                freeman.push(herhusband);
            }
        }
    }
}
