#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back

using namespace std;

vector <ll> Ext_Euclid (ll a, ll b)
{
    if(b == 0)
    {
        vector <ll> tmp;
        tmp.pb(1);  tmp.pb(0);  tmp.pb(a);
        return tmp;
    }
    vector <ll> curr = Ext_Euclid(b, a%b), nu;
    nu.pb(curr[1]);
    nu.pb(curr[0] - (a/b)*curr[1]);
    nu.pb(curr[2]);
    return nu;
}

ll inverse_mod(ll n, ll mod)
{
    vector<ll> temp = Ext_Euclid(n, mod);
    if(temp[0] < 0) temp[0] += mod;
    return temp[0];
}

int main()
{
    int T;  cin >> T;
    for(int t = 0; t < T; t++)
    {
        ll A, N;   sf("%lld%lld", &A, &N);
        vector <ll> ans = Ext_Euclid(A, N);
        if(A == 1)
        {
            pf("1\n");
            continue;
        }
        if(ans[2] == 1)
        {
            if(ans[0] < 0)
                ans[0] += N;
            pf("%lld\n", ans[0]);
        }
        else
        {
            pf("-1\n");
        }
    }
}
