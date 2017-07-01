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
	int n, k;	cin >> n >> k;
	vector <int> A[2];
	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		A[0].pb(tmp);
	}

	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		A[1].pb(tmp);
	}
	ll tot = 0;
	vector <int> diff;
	for(int i = 0; i < n; i++)
	{
		diff.pb(A[1][i]-A[0][i]);
	}
	sort(diff.begin(), diff.end());
	
	for(int i = 0; i < n; i++)
		tot += A[1][i];

	for(int i = 0; i < k; i++)
		tot -= diff[n-i-1];

	for(int i = k; i < n; i++)
		if(diff[n-i-1] > 0)
			tot -= diff[n-i-1];
	cout << tot;
	return 0;
}