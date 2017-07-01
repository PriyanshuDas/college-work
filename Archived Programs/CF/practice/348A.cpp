#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pii pair <ll, ll>

using namespace std;

int main()
{
	int n;	cin >> n;
	ll sum = 0, mx = 0;
	for(int i = 0; i < n; i++)
	{
		ll tmp;	sf("%lld", &tmp);
		mx = max(mx, tmp);
		sum += tmp;
	}
	ll ans = ceil((double)sum/(double)(n-1));
	ans = max(ans, mx);
	cout << ans;
	return 0;
}