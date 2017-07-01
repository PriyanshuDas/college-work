#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >
#define pi4 pair<pair<ll, ll>, pair<ll, ll> >

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		ll L, R;	sf("%lld%lld", &L, &R);
		ll m = min(L, R);
		ll ans = m*(m+1);
		ans /= 2;
		pf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}
