#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pf printf
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    ll amt = 0;
    vector<int> P,D;
    vector<pair<int, int> > A;
    ll tot = 0;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;    sf("%d%d", &t1, &t2);
        P.pb(t1);   D.pb(t2);
        A.pb(mp(t1+t2, t2));
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    for(int i = A.size()-1; i >= 0; i--)
    {
        ll g = A[i].first;
        ll l = A[i].second;
        if(k > 0)
        {
            ans += (g-l);
            k--;
        }
        else
        {
            ans -= l;
        }
    }
    if(ans > 0)
        cout << ans;
    else
        cout << 0;
    return 0;
}
