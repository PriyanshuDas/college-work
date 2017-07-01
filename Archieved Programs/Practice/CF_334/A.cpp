#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

double score(int S, int m, int w)
{
    double ans = 3*250*S;
    double a2 = 10*((250-m)*S - 250*50*w);
    ans = max(ans, a2);
    return ans;
}

int main()
{
    int s[6] = {0, 500, 1000, 1500, 2000, 2500};
    int m[6] = {0}, w[6] = {0};
    int hs, hu;
    for(int i = 1; i < 6; i++)
    {
        cin >> m[i];
    }
    for(int i = 1; i < 6; i++)
    {
        cin >> w[i];
    }
    cin >> hs >> hu;
    double ans = 0;
    for(int i = 1; i < 6; i++)
    {
        ans += score(s[i], m[i], w[i]);
    }
    ans += 10*250*(hs*100 - hu*50);
    ans = ans/(2500);
    cout << ans;
    return 0;
}
