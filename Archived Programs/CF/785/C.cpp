#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert
#define n_max 1000000001
using namespace std;

ll n, m;
ll a,b, c;
ll N = n_max;

bool val(ll x)
{
	ll v = x*(x+1);
	if(v >= 2*(n-m))
		return true;
	return false;
}

ll bin_search()
{
	ll l = 0, r = (ll)((ceil(sqrt(2*(n-m))))+1);
	ll ans = l;
	while(l < r)
	{
		ll mid = (l+r)>>1;
		//pf("(%lld, %lld, %lld)\n", l, mid, r);
		if(val(mid))
		{
			r = mid;
		}
		else
		{
			l = mid+1;
		}
	}
	return r;
}

int main()
{
	cin >> n >> m;
	a = 1, b = (2*m + 1), c = -2*(n-m);
	ll ans = m + bin_search();
	if(m > n)
		ans = n;
	cout << ans;
	return 0;
}