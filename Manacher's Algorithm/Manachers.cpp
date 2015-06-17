#include<bits/stdc++.h>
using namespace std;
string s, t;
char str[1000005];
void prepare_string()
{
    int i;
    t = "^#";
    for(i = 0; i < s.size(); i++)
        t += s[i], t += "#";
    t += "$";
}

int manacher()
{
    prepare_string();

    int P[t.size()], c = 0, r = 0, i, i_mirror, n = t.size() - 1;

    for(i = 1; i < n; i++)
    {
        i_mirror = (2 * c) - i;

        P[i] = r > i? min(r - i, P[i_mirror]) : 0;

        while(t[i + 1 + P[i]] == t[i - 1 - P[i]])
            P[i]++;

        if(i + P[i] > r)
        {
            c = i;
            r = i + P[i];
        }
    }
    return *max_element(P + 1, P + n);
}

int main()
{
    int kase = 1;
    while(scanf(" %s", str) && str[0] != 'E')
    {
        s = str;
        printf("Case %d: %d\n", kase++, manacher());
    }
    return 0;
}


