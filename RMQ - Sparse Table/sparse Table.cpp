/**
    Compute sparse table in O(NlogN)
    query in O(1)
    Ref link: https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
**/
#include<bits/stdc++.h>
using namespace std;
#define Max 10000005
int rmq[24][Max];
void Compute_ST(int N)
{
    for (int i = 0; i < N; ++i)rmq[0][i] = i;
    for (int k = 1; (1 << k) < N; ++k)
    {
        for (int i = 0; i + (1 << k) <= N; i++)
        {
            int x = rmq[k - 1][i];
            int y = rmq[k - 1][i + (1 << k - 1)];
            rmq[k][i] = A[x] <= A[y] ? x : y;
        }
    }
}

int RMQ(int i, int j)
{
    int k = log2(j-i);
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return A[x] <= A[y] ? x : y;
}

int main()
{

    return 0;
}
