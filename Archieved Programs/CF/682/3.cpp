#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define max_s 100001

using namespace std;

ll tree_size[max_s], sad[max_s];
vector<pair<int, ll> > conn[max_s];

ll dfs(int n, int p)
{
    tree_size[n] = 1;
    for(int i = 0; i < conn[n].size(); i++)
    {
        int curr = conn[n][i].first;
        if(curr != p)
        {
            tree_size[n] += dfs(curr, n);
        }
    }
    return tree_size[n];
}

ll ans = 0;

ll cut_no(int n, int p, ll curr_d)
{
    //pf("@ (%d) with %lld\n", n, curr_d);
    for(int i = 0; i < conn[n].size(); i++)
    {
        int curr = conn[n][i].first;
        ll dist = conn[n][i].second;
        ll val = sad[curr];
        if(curr != p)
        {
            if(val < curr_d + dist)
            {
                //pf("Cutting at %d\n", curr);
                ans += tree_size[curr];
                continue;
            }
            else
            {
                cut_no(curr, n, max(curr_d + dist, (long long int) 0));
            }
        }
    }
}

int main()
{
    int n;   cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> sad[i+1];
    }
    for(int i = 2; i <= n; i++)
    {
        int a; ll b;   cin >> a >> b;
        conn[i].pb(mp(a, b));  conn[a].pb(mp(i, b));
    }
    dfs(1, 0);
    cut_no(1, 0, 0);
    cout << ans;
    /*cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << i << ' ' << tree_size[i] << endl;
    }*/
    return 0;
}
