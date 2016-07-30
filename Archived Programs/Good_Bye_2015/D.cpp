#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;
string s;
int n;
ll memo[5000][5000];
string cache_1;
string cache_2;
int pos_en;

ll dp(int prev, int curr)
{
    /*if(prev >= 0)
        cout << cache_1 << '\t' << cache_2 << endl;*/
    if(curr == n)
        return 1;
    if(s[curr+1] == '0')
        return 0;
    ll ans = 0;
    if(memo[prev][curr] != -1)
        return memo[prev][curr];
    bool flag = true;
    for(int i = curr+1; i <= n; i++)
    {
        if(prev == 0 && curr == 0)
        {
            ans = (ans + dp(1, i))%mod;
            continue;
        }
        if(flag)
        {
            cache_1 = s.substr(prev, curr-prev+1);
            cache_2 = s.substr(curr+1,i-curr);
            flag = 0;
        }
        else
        {
            cache_2 += s[i];
        }
        if(cache_2.size() >= cache_1.size())
        {
            //cout << cache_1 << '\t' << cache_2 << endl;
            if(cache_2.size() > cache_1.size())
            {
                flag = true;
                ans = (ans + dp(curr+1, i))%mod;
            }
            else if(cache_2 > cache_1)
            {
                flag = true;
                ans = (ans + dp(curr+1, i))%mod;
            }
        }
    }
    memo[prev][curr] = ans;
    return ans;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    cin >> n;
    cin >> s;
    string s2 = "0";
    s2 += s;
    s = s2;
    ll ans = dp(0, 0);
    cout << ans << endl;
    return 0;
}
