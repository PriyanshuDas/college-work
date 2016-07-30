#include <bits/stdc++.h>

#define ll long long int
#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair
#define max_s 100000

using namespace std;

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

bool solve(ll N, ll C)
{
    ll X = N - C%N;
    ll num = N - X;
    ll den = (N*(N-1))/2;
    ll g1 = gcd(num, den);
    double mul = (den/g1);
    if(X+ mul*num < C)
        return true;
}

int main()
{
    int T;  cin >> T;
    for(int i = 0; i < T; i++)
    {
        ll N, C; sf("%lld%lld", &N, &C);
        bool ans = solve(N, C);
        if(ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
