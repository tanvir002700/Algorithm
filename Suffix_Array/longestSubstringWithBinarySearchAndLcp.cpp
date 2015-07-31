#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
const int MAX =3*5005;
struct info
{
    int tup[2], indx; ///tup[0] = prev rank, tup[1] = new rank
}arr[MAX];

int sorted[18][MAX], LCP[MAX], step;
string text;

bool comp(const info &a, const info &b)
{
    return a.tup[0] != b.tup[0]? a.tup[0] < b.tup[0] : a.tup[1] < b.tup[1];
}

void build_suffix_array(void)
{
    int i, n = text.size(), jump;
    for(i = 0; i < n; i++)
    {
        sorted[0][i] = text[i] - 'A'; ///rank suffixes according to 1st char
        memset(arr[i].tup, 0,sizeof(arr[i].tup));
    }
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(i = 0; i <=n; i++)
        {
            arr[i].indx = i;
            arr[i].tup[0] = sorted[step - 1][i]; /// what i was in prev step
            arr[i].tup[1] = i + jump < n? sorted[step - 1][i + jump] : -1;
        }
        sort(arr, arr + n, comp);
        sorted[step][arr[0].indx] = 0;
        for(i = 1; i < n; i++)
            sorted[step][arr[i].indx] = arr[i].tup[0] == arr[i - 1].tup[0] &&
            arr[i].tup[1] == arr[i - 1].tup[1] ? sorted[step][arr[i - 1].indx] : i;
    }
//    cout << "Suffix Array : \n\n";
//    for(i = 0; i < n; i++)
//        cout<<arr[i].indx<<' '<<text.substr(arr[i].indx)<<endl;
}


void build_LCP_array(void)
{
    LCP[0] = 0;
    int n = text.size(), i, j, id1, id2;
    for(i = 1; i < n; i++)
    {
        id1 = arr[i - 1].indx;
        id2 = arr[i].indx;
        LCP[i] = 0;
        //cout << "id" << id1 << ' ' << id2 << endl;
        //cout << sorted[0][id1] << ' ' << sorted[0][id2] << endl;
        for(j = step - 1; j >= 0; j--)
            if(sorted[j][id1] == sorted[j][id2] && sorted[j][id2])
            {
                LCP[i] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
//        cout << arr[i - 1].indx << ' ' << arr[i].indx << ' ' << LCP[i] << endl;
    }
//    for(i = 0; i < n; i++)
//        cout << i << ' ' << LCP[i] << endl;
}
pp Index[3];
int Position(int indx)
{
    for(int i=0;i<3;i++)
    {
        if(indx>=Index[i].first and indx<Index[i].second)return i;
    }
    return -1;
}
bool Ok(int val)
{
    for(int i=1;i<text.size();i++)
    {
        if(LCP[i]>=val)
        {
            bool a,b,c;
            a=b=c=false;
            int indx=Position(arr[i].indx);
            if(indx==-1)continue;
            indx==0?a=true:indx==1?b=true:indx==2?c=true:c=false;
            indx=Position(arr[i-1].indx);
            indx==0?a=true:indx==1?b=true:indx==2?c=true:c=false;
            int r=i+1;
            while(r<text.size() and LCP[r]>=val and !(a and b and c))
            {
                indx=Position(arr[r].indx);
                indx==0?a=true:indx==1?b=true:indx==2?c=true:c=false;
                r++;
            }
            if(a and b and c)return true;
        }
    }
    return false;
}
int main()
{
    #ifdef _ANICK_
    //f_input;
    #endif // _ANICK_
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        char s[5005];
        text.clear();
        for(int i=0;i<3;i++)
        {
            scanf("%s",s);
            Index[i].first=text.size();
            text+=s;
            Index[i].second=text.size();
            if(i!=2)text+="#";
        }
        build_suffix_array();
        build_LCP_array();
        int ans=0;
        int low=0,high=text.size();
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(Ok(mid))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
