#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define M 1000000007

using namespace std;
//********** Careful when mod > 10^9, Might Overflow*************
ll expon(ll num, ll p, ll mod)	//(num, pow, mod)
{
	ll pow_arr[64] = {0};
	ll tmp = num;
	for(int i = 0; i < 63; i++)
	{
		pow_arr[i] = tmp%mod;
		tmp = (tmp*tmp)%mod;
		//cout << pow_arr[i] << '\t';
	}
	tmp = 1;
	ll tmp2 = 1;
	for(int i = 0; i < 63; i++)
	{
		ll curr = tmp2<<i;
		//pf("@pos %d\t %lld\n", i, (p&curr));
	 	if((p&curr) > 0)
			tmp = (tmp*pow_arr[i])%mod;
	}
	if(tmp  < 0)
		tmp += mod;
	return tmp;
}

int main()
{
	ll T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		ll A, B, N, K;		sf("%lld%lld%lld%lld", &A, &B, &N, &K);
		//cout << "Pak Pak\n";
		vector<ll> pow_A, pow_B, inv;
		vector<ll> inv_pow_B[K];
		for(int i = 0; i < K; i++)
		{
			ll a = expon(i, A, K);
			pow_A.pb(a%K);
			ll b = expon(i, B, K);
			pow_B.pb(b%K);
			ll inv0 = (K - i)%K;
			inv.pb(inv0);
		}
		for(ll i = 0; i < K; i++)
		{
			inv_pow_B[pow_B[i]].pb(i);
		}
		ll ans = 0;
		for(int i = 0; i < K; i++)
		{
			ll a = i;
			ll ct_a = N/K + ((N%K) >= a && a != 0);
			
			for(int j = 0; j < inv_pow_B[inv[pow_A[a]]].size(); j++)
			{
				ll b = inv_pow_B[inv[pow_A[a]]][j];
				ll ct_b = N/K + ((N%K) >= b && b != 0);
				ll ans_c = 0;
				if(a < 0 || b < 0 || ct_a < 0 || ct_b < 0)
					pf("(%lld, %lld) (%lld, %lld)\n", a, b, ct_a, ct_b);
				if(a == b)
					ans_c = (ct_a*(ct_a - 1))%M;
				else
					ans_c = (ct_a*ct_b)%M;
				if(ans_c < 0)
					ans_c += M;
				ans = (ans + ans_c)%M;
				if(ans < 0)
					ans += M;
			}
		}
		pf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}
