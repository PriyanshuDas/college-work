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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	set <ll> vis;
	for(ll i = 0; i <= 100000; i++)
	{
		vis.ins(b+i*a);
	}
	ll ans = -1;
	for(ll j = 0; j <= 100000; j++)
	{
		if(vis.find(d+j*c) != vis.end())
		{
			ans = d+j*c;
			break;
		}
	}
	cout << ans;
	return 0;
}