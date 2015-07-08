#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int N;
    while(scanf("%d",&N) and N)
    {
        priority_queue<int>Q;
        bool Ok=true;
        int Odd_Node=0;
        for(int i=0;i<N;i++)
        {
            int x;
            scanf("%d",&x);
            if(x>=N or x<0)Ok&=false;
            Odd_Node+=(x%2);
            Q.push(x);
        }
        Ok&=(Odd_Node%2==0); ///Handshaking Theorem
        for(int i=0;i<N and Ok;i++)
        {
            int k=Q.top();
            Q.pop();
            vector<int> v;
            for(int j=0;j<k and Ok;j++)
            {
                int x=Q.top();
                Q.pop();
                x--;
                Ok&=(x>=0);
                v.push_back(x);
            }
            for(int j=0;j<k and Ok;j++)
            {
                Q.push(v[j]);
            }
        }
        if(Ok)printf("Possible\n");
        else printf("Not possible\n");
    }
    return 0;
}
