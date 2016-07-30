#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

map <ll, pair <ll, ll> > M_X;
map <ll, pair <ll, ll> > M_Y;



int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll x[2], y[2];
        sf("%lld%lld%lld%lld", &x[0], &y[0], &x[1], &y[1]);
        if(x[0] == x[1])
        {
            M_X[x[0]] = mp()
        }
    }
    return 0;
}
