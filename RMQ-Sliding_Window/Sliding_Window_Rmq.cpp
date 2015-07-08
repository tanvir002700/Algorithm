/**
    every K size window RMQ
    Calculate in O(N+K) time
**/
#include<bits/stdc++.h>
using namespace std;
vector<int>SlidingRMQ(int *A,int N,int k)
{
    /** Create a Double Ended Queue, Qi that will store indexes of array elements
        The queue will store indexes of useful elements in every window and it will
        maintain decreasing order of values from front to rear in Qi, i.e.,
        arr[Qi.front[]] to arr[Qi.rear()] are sorted in increasing order
    **/
    vector<int>MinWindow;
    deque<int>Q;
    int i;
    /* Process first k (or first window) elements of array */
    for(i=0;i<k;i++)
    {
        /// For very element, the previous largest elements are useless so
        /// remove them from Qi
        while(!Q.empty() and A[i]<=A[Q.back()])Q.pop_back();
        Q.push_back(i);
    }
    /// Process rest of the elements, i.e., from arr[k] to arr[n-1]
    while(i<N)
    {
        /// The element at the front of the queue is the smallest element of
        /// previous window, so insert it result
        MinWindow.push_back(A[Q.front()]);

        /// Remove the elements which are out of this window
        while(!Q.empty() and Q.front()<=i-k)Q.pop_front();

        /// Remove all elements larger than the currently
        /// being added element (remove useless elements)
        while(!Q.empty() and A[i]<=A[Q.back()])Q.pop_back();

        /// Add current element at the rear of Qi
        Q.push_back(i);
        i++;
    }
    /// insert the minimum element of last window
    MinWindow.push_back(A[Q.front()]);
    return MinWindow;
}
int main()
{
    int A[]={100,10, -1, 2,-3,-4,10, 1,100,20};
    vector<int>a=SlidingRMQ(A,10,2);
    for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
    return 0;
}
