#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int

using namespace std;

ll Combin(ll N)
{
	return N*(N-1)/2;
}

int main()
{
	ll n, m;		// n - part, m - teams
	cin >> n >> m;
	ll Max = n - (m-1);
	Max = Combin(Max);
	ll Min = 0;
	ll lim_1 = n%m;
	Min = (m - lim_1)*(Combin(n/m));
	Min += (lim_1)*(Combin(n/m + 1));
	pf("%lld %lld\n", Min, Max);
	return 0;
}
