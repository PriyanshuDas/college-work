#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define mp make_pair

using namespace std;

int main()
{
	int n, a, b, c, d;	cin >> n >> a >> b >> c >> d;
	int min_v = min(min(a+b, b+d), min(d+c, c+a));
	int max_v = max(max(a+b, b+d), max(d+c, c+a));
	ll ans = 0;
	/*Sum of two chosen values + max_sum, must be such that sum - (min_sum + i) < n
	=>		1 <= (v2 + i + max_val) - (min_val + i)<= n
	=>		1 <= (v2 + max_val) - min_val <= n
	=>	min_v-max_v + 1 <= v2 <= n + min_val - max_val
	=>				1 <= v2 <= n + min_val - max_val		*/
	if(n + min_v - max_v >= 0)
	{
		ans = (n + min_v - max_v);
		ans *= n;
	}
	cout << ans;
	return 0;
}
