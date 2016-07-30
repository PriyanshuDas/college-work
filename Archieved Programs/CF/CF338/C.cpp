#include <bits/stdc++.h>

#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair <int, int>

using namespace std;

string shop;
string shop_r;
string coat;
string cache_1;
vector <pii> curr;
vector <pii> ans;

int reached[2101];

void dp(int pos, int total)
{
    if(reached[pos] != -1 && reached[pos] <= total)
        return;
    reached[pos] = total;
    pf("At pos %d, with total %d\n", pos, total);
    if(pos == coat.size())
    {
        ans.clear();
        if(curr.size() < ans.size())
        {
            for(int i = 0; i < curr.size(); i++)
                ans.pb(curr[i]);
        }
        return;
    }
    int c_p = pos;
    for(int i = 0; i < shop.size(); i++)
    {
        c_p = pos;
        while(c_p < coat.size() && shop[i+c_p-pos] == coat[c_p])
        {
            c_p++;
            curr.pb(mp(i+1, c_p-pos+1));
            dp(c_p, total+1);
            curr.erase(curr.begin() + curr.size() -1);
        }
        c_p = pos;
        while(c_p < coat.size() && shop_r[i+c_p-pos] == coat[c_p])
        {
            c_p++;
            curr.pb(mp(shop.size() - i, shop.size() - (c_p-pos)));
            dp(c_p, total+1);
            curr.erase(curr.begin() + curr.size() - 1);
        }
    }
}

int main()
{
    memset(reached, -1, sizeof(reached));
    cin >> shop;
    cin >> coat;
    shop_r = shop;
    for(int i = 0; i < shop.size()/2; i++)
        shop_r[i] = shop_r[shop.size()-i-1];
    dp(0, 0);
    cout << ans.size();
    for(int i = 0; i < ans.size(); i++)
    {
        pf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
