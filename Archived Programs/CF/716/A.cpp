#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back
#define ins insert
#define loop(i,l,r) for(int i = l; i < r; i++)
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll>
#define pi4 pair<pi2, pi2>

using namespace std;

int main()
{
	ll n, c;	cin >> n >> c;
	ll c_t = 0, c_w = 0;
	for(ll i = 0; i < n; i++)
	{
		int t;	cin >> t;
		if (t - c_t > c)
		{
			c_w = 0;
		}
		c_w++;
		c_t = t;
	}
	cout << c_w;
	return 0;
}
