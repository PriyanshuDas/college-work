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

/*
	Cases:
	1) b = 0			-> check for 0
	2) b != 0, q = 0	-> check b <= l and then 0
	3) b != 0, q = 1	-> check b
	4) b != 0, q = -1	-> check b and -b
*/

using namespace std;

int main()
{
	ll b, q, l, m, ans = 0;
	cin >> b >> q >> l >> m;
	set <ll> S;
	for(int i = 0; i < m; i++)
	{
		ll tmp;	sf("%lld", &tmp);
		S.ins(tmp);
	}
	if(b == 0)
	{
		if(S.find(0) == S.end())
			cout << "inf";
		else
			cout << 0;
		return 0;
	}
	if(q == 0)
	{
		ll ans = 0;
		if(abs(b) <= l && S.find(b) == S.end())
		{
			ans++;
		}
		if(abs(b) > l)
		{
			cout << 0;
			return 0;
		}
		if(S.find(0) == S.end())
		{
			pf("inf");
			return 0;
		}
		pf("%lld", ans);
		return 0;
	}
	if(q == 1)
	{
		if(abs(b) <= l && S.find(b) == S.end())
		{
			cout << "inf";
			return 0;
		}
		else
			cout << 0;
		return 0;
	}
	if(q == -1)
	{
		if((abs(b) <= l && S.find(b) == S.end()) || (abs(b) <= l && S.find(-b) == S.end()))
		{
			cout << "inf";
			return 0;
		}
		else
			cout << 0;
		return 0;
	}

	ll ct = 0, v = b;
	while(abs(v) <= l)
	{
		if(S.find(v) == S.end())
			ct++;
		v = v*q;
	}
	cout << ct;
	return 0;
}