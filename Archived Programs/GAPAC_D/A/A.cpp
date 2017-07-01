#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		int n,m;	cin >> n >> m;
		double num = n-m;
		double den = n+m;
		double ans = num/den;
		pf("Case #%d: %0.9lf\n",i, ans);
	}
	return 0;
}
