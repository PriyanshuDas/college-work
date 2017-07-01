#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

#define A 1234567
#define B 123456
#define C 1234

using namespace std;

set<ll> M;
ll n;

int dp(ll val, int pos)
{
    int flag = 0;
    if(val == n)
        return 1;
    if(val > n)
        return 0;
   set<ll>::iterator it = M.find(val);
    if(it != M.end())
    {
        return 0;
    }
    M.insert(val);
    //cout << val << endl;
    if(pos == 2)
    {
        ll tmp = val;
        flag = max(flag, dp(tmp, 3));
        while(tmp + B <= n)
        {
            tmp += B;
            flag = max(flag, dp(tmp, 3));
        }
    }
    if(pos == 3)
    {
        ll tmp = val;
        flag = max(flag, dp(tmp, 4));
        while(tmp + C <= n)
        {
            tmp += C;
            flag = max(flag, dp(tmp, 4));
        }
    }
    if(pos == 4)
        flag = max(flag, 0);
    return flag;
}

int main()
{
    cin >> n;
    n = n%A;
    int ans = dp(0, 2);
    if(ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
