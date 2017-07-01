#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int

using namespace std;

int main()
{
	ll l1, r1, l2, r2, k;	cin >> l1 >> r1 >> l2 >> r2 >> k;
	ll lo = max(l1, l2);
	ll hi = min(r1, r2);
	ll ans = hi - lo + 1;
	if(k >= lo && k <= hi)
		ans--;
	if(ans < 0)
		ans = 0;
	cout << ans;
	return 0;
}
