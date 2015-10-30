#include<bits/stdc++.h>
using namespace std;
const int inf = 2000000000; // a large value as infinity

int n; // the number of items in the sequence
int Sequence[32]; // the sequence of integers
int L[32]; // L[] as described in the algorithm
int I[32]; // I[] as described in the algorithm
vector<int>LIS;
void takeInput()
{
    scanf("%d", &n); // how many numbers in the sequence ?
    for( int i = 0; i < n; i++ ) // take the sequence
        scanf("%d", &Sequence[i]);
}

int LisNlogK()   // which runs the NlogK LIS algorithm
{
    int i; // auxilary variable for iteration

    I[0] = -inf; // I[0] = -infinite
    for( i = 1; i <= n; i++ ) // observe that i <= n are given
        I[i] = inf; // I[1 to n] = infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted

    for( i = 0; i < n; i++ )   // iterate left to right
    {
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high )   // binary search to find the correct position
        {
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        L[i]=low;
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }


    i=0;
    for(int j=0; j<n; j++)
    {
        if(L[j]>L[i])
        {
            i=j;
        }
    }
    LIS.push_back(Sequence[i]);
    for(int j=i-1; j>=0; j--)
    {
        if(Sequence[j]<Sequence[i]&&L[j]==L[i]-1)
        {
            i=j;
            LIS.push_back(Sequence[j]);
        }
    }
    reverse(LIS.begin(),LIS.end());
    return LisLength; // return the result
}
int main()
{
    takeInput();
    int result = LisNlogK();
    printf("The LIS length is %d\n", result);
    for(int i=0; i<LIS.size(); i++)printf("%d ",LIS[i]);
    return 0;
}
