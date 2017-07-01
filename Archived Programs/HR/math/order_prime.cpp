#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define max_l 1000000000000

using namespace std;

ll count(ll L, ll p)
{
	ll ans = 0;
	while(L > 0)
	{
		ans += (L/p);
		L = L/p;
	}
	return ans;
}

int main()
{
	int T;	cin >> T;
	for(int i = 0; i < T; i++)
	{
		ll p, L;	sf("%lld%lld", &p, &L);
		ll ans = 0;
		if(L < p)
		{
			pf("%lld\n", L);
			continue;
		}
		if(p <= max_l/p)
		{
			ans = (L-p+1)/(p*p);
			ll del = 0;
			if (L/(p*p) > ans)
			{
				del = 
			}
			ans = ans*p;
		}
		ans += (p-2);
		pf("%lld\n", ans);
	}
	return 0;
}

