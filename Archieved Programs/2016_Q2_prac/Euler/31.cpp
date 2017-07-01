#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back

using namespace std;

vector <int> coins;
ll req_val = 0;
ll mem[9][400] = {0};

ll recurse(int pos, ll val)
{
    if(pos == coins.size())
    {
        if(val == req_val)
            return 1;
        return 0;
    }
    //pf("(%d, %lld)\n", pos, val);
    ll n_val = val;
    ll ans = 0;
    while(n_val <= req_val)
    {
        ans += recurse(pos+1, n_val);
        n_val += coins[pos];
    }
    mem[pos][val] = ans;
    return ans;
}

int main()
{
    req_val = 200;
    coins.pb(1);    coins.pb(2);    coins.pb(5);    coins.pb(10);
    coins.pb(20);   coins.pb(50);   coins.pb(100);  coins.pb(200);
    sort(coins.begin(), coins.end());
    memset(mem, -1, sizeof(mem));
    ll ret = recurse(0, 0);
    pf("No of ways is : %lld\n", ret);
    return 0;
}
