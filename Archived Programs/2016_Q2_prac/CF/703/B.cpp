#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define pi2 pair<ll,ll>
#define pi3 pair<ll, pair<ll, ll> >

using namespace std;

int main()
{
    int n, k;   cin >> n >> k;
    ll ans = 0, sum = 0, b_sum = 0;
    vector<ll> beauty;
    vector<ll> capital;
    int is_cap[100001] = {0};
    for(int i = 0; i < n; i++)
    {
        ll tmp;    cin >> tmp;
        beauty.pb(tmp);
    }
    for(int j = 0; j < k; j++)
    {
        ll tmp; cin >> tmp;
        capital.pb(tmp-1);
        is_cap[tmp-1] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(is_cap[i] == 0)
            sum += beauty[i];
    }
    //cout << "Sum : " << sum << endl;
    for(int i = 0; i < capital.size(); i++)
    {
        ll c_ind = capital[i];
        ans += beauty[c_ind]*sum;
        ans += beauty[c_ind]*b_sum;
        b_sum += beauty[capital[i]];
    }
    //cout << ans << endl;
    for(int j = 0; j < beauty.size(); j++)
    {
        ll nex = beauty[(j+1)%(n)];
        if(is_cap[j] == 0 && is_cap[(j+1)%n] == 0)
        {
            ans += beauty[j]*nex;
        }
    }
    cout << ans;
    return 0;
}
