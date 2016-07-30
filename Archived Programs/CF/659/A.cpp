#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = (a+b)%n;
    if(ans < 0)
        ans += n;
    if(ans == 0)
        ans = n;
    cout << ans;
    return 0;
}
