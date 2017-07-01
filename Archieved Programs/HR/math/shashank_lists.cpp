#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define llu unsigned long long int

using namespace std;

llu MOD = 1000000007;

llu pow_2(ll x)
{
	ll ans = 1;
	if(x == 0)
		ans = 1;
	else if(x == 1)
	{
		ans = 2;
	}
	else if(x%2 == 0)
	{
		ans = pow_2(x/2)%MOD;
		ans = (ans*ans)%MOD;
	}
	else
	{
		ans = pow_2(x-1)%MOD;
		ans = (ans*2)%MOD;
	}
	return ans;
}

int main()
{
	int N;	sf("%d", &N);
	vector <ll> arr;
	for(int i = 0; i < N; i++)
	{
		ll tmp;	 sf("%lld", &tmp);
		arr.pb(tmp);
	}
	llu ans = 1;
	for(int i = 0; i < N; i++)
	{
		llu tmp = (pow_2(arr[i])+1)%MOD;
		//cout << tmp << endl;
		ans = (ans*((tmp)%MOD))%MOD;
		if (ans < 0)
			ans += MOD;
	}
	ans--;
	if(ans < 0)
		ans += MOD;
	cout << ans << endl;
}
