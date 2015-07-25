const int MAX=100005;
struct point{int x, y, i;};
point arr[MAX], sortedY[MAX];
bool flag[MAX];
template <class T> int getdist(T a, T b){return max(abs(a.x - b.x), abs(a.y - b.y));}
bool compareX(const point &a, const point &b){
    return a.x < b.x;
}
bool compareY(const point &a, const point &b){
    return a.y < b.y;
}

int closest_pair(point X[], point Y[], int n)
{
    int left_call, right_call, mindist;
    if(n == 1) return inf;
    if(n == 2) return getdist(X[0], X[1]);
    int n1, n2, ns, j, m = n / 2, i;
    point xL[m + 1], xR[m + 1], yL[m + 1], yR[m + 1], Xm = X[m - 1], yS[n];
    for(i = 0; i < m; i++)
    {
        xL[i] = X[i];
        flag[X[i].i] = 0;
    }
    for(; i < n; i++)
    {
        xR[i - m] = X[i];
        flag[X[i].i] = 1;
    }
    for(i = n2 = n1 = 0; i < n; i++)
    {
        if(!flag[Y[i].i]) yL[n1++] = Y[i];
        else yR[n2++] = Y[i];
    }
    left_call = closest_pair(xL, yL, n1);
    right_call = closest_pair(xR, yR, n2);
    mindist = min(left_call, right_call);
    for(i = ns = 0; i < n; i++)
        if((Y[i].x - Xm.x) < mindist)
            yS[ns++] = Y[i];
    for(i = 0; i < ns; i++)
        for(j = i + 1; j < ns && (yS[j].y - yS[i].y) < mindist; j++)
            mindist = min(mindist, getdist(yS[i], yS[j]));
    return mindist;
}

int Find_closestpair(int n)
{
    sort(arr, arr + n, compareX);
    sort(sortedY, sortedY + n, compareY);
    int ans = closest_pair(arr, sortedY, n);
    return ans;
}
