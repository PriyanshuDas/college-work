#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

int main()
{
    int n, m;   cin >> n >> m;
    ll arr[2][5] = {0};
    for(int i = 1; i <= n || i <= m; i++)
    {
        if(i <= m)
        {
            arr[0][i%5]++;
        }
        if(i <= n)
            arr[1][i%5]++;
    }
    ll ans = 0;
    for(int i = 0; i < 5; i++)
    {
        ll tmp = arr[0][i]*arr[1][(5-i)%5];
        ans += tmp;
    }
    cout << ans;
    return 0;
}
