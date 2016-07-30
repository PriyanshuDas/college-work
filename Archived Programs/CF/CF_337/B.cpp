#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <ll> paint;
    ll minim = 9999999999;
    for(int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        if(tmp < minim)
            minim = tmp;
        paint.pb(tmp);
    }
    int ct = 0;
    int max_ct = 0;
    for(int i = 0; i < 2*paint.size(); i++)
    {
        if(paint[i%paint.size()] > minim)
            ct++;
        else
        {
            if(ct > max_ct)
                max_ct = ct;
            ct = 0;
        }
    }
    if(ct > max_ct)
        max_ct = ct;
    ll ans = minim*n + max_ct;
    cout << ans;
    return 0;
}
