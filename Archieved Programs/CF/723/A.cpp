#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair <ll, pi2 >
#define pi4 pair<pi2, pi2>
#define loop(l,r) for(int i = l; i < r; i++)
#define ull unsigned long long int

using namespace std;

int main()
{
	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;
	int ans = 300;
	for(int i = 0; i < 101; i++)
	{
		int d1 = abs(x1-i), d2 = abs(x2-i), d3 = abs(x3-i);
		int a = d1+d2+d3;
		ans = min(a, ans);
	}
	cout << ans;
	return 0;
}
