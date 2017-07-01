#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    ll start, end_y;
    cin >> start >> end_y;
    ll mask = 0;
    ll tmp = 1;
    ll ans = 0;
    for(int i = 1; i < 64; i++)
    {
        mask |= tmp;
        tmp = tmp << 1;
        ll t2 = 1;
        for(int j = 1; j < i; j++)
        {
            ll cur = mask ^ t2;
            if(cur >= start && cur <= end_y)
                ans++;
            t2 = t2 << 1;
        }
    }
    tmp = 1;
    /*for(int i = 0; i < 64; i++)
    {
        bool bin = mask&tmp;
        cout << bin;
        tmp= tmp << 1;
    }*/
    cout << ans;
    return 0;
}
