#include<bits/stdc++.h>
using namespace std;
const int MAX =400004;
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
    cout << "Suffix Array : \n\n";
    for(i = 0; i < n; i++)
        cout<<arr[i].indx<<' '<<text.substr(arr[i].indx)<<endl;
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
        cout << arr[i - 1].indx << ' ' << arr[i].indx << ' ' << LCP[i] << endl;
    }
    for(i = 0; i < n; i++)
        cout << i << ' ' << LCP[i] << endl;
}

int main()
{
    text = "helloworld";
    build_suffix_array();
    build_LCP_array();
    return 0;
}
