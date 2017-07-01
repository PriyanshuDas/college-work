#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert

using namespace std;

int main()
{
	int n, m;	cin >> n;
	set <ll> T[2][2];
	for(int i = 0; i < n; i++)
	{
		ll l, r;	sf("%lld%lld", &l, &r);
		T[0][0].ins(l);
		T[0][1].ins(r);
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		ll l, r;	sf("%lld%lld", &l, &r);
		T[1][0].ins(l);
		T[1][1].ins(r);
	}
	ll left[2], right[2];
	set<ll>::iterator it = T[0][0].end();
	it--;
	left[0] = *(it);
	it = T[1][0].end();
	it--;
	left[1] = *(it);
	right[0]= *(T[0][1].begin());
	right[1]= *(T[1][1].begin());
	ll ans = max(left[0]-right[1], left[1]-right[0]);
	if(ans <= 0)
		ans = 0;
	cout << ans;
	return 0;
}