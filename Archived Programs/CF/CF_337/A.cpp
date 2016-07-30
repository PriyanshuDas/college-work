#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    ll n;
    cin >> n;
    if(n%2 != 0)
    {
        cout << 0;
        return 0;
    }
    ll ans = n/4;
    if(n%4 == 0)
        ans--;
    cout << ans;
    return 0;
}
