#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back

using namespace std;

map < int, set<int> > M;
vector <int> S;

int main()
{
    int N, D;   cin >> N >> D;
    for(int n = 0; n < N; n++)
    {
        int tmp;    sf("%d", &tmp);
        M[tmp].insert(n);
        S.pb(tmp);
    }
    for(int d = 0; d < D; d++)
    {
        int tmp;    sf("%d", &tmp);
        int ans = 9999999, d1 = 0, d2 = 0;
        for(int i = 0; i < N; i++)
        {
            int cur = S[i];
            int req = cur+tmp;
            map<int, set<int> >:: iterator it = M.find(req);
            if(it != M.end())
            {
                set<int>::iterator it2 = (it->second).upper_bound(i);
                if(it2 != (it->second).end())
                {
                    int days = *it2 - i;
                    if(days < ans)
                    {
                        ans = days;
                        d1 = i; d2 = i+days;
                    }
                }
            }
        }
        d1++;   d2++;
        if(ans == 9999999)
            pf("-1\n");
        else
        pf("%d %d\n", d1, d2);
    }
    return 0;
}
