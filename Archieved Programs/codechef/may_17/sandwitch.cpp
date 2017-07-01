/*	Includes :
1>	Extended Euclid					2>	Inverse Modulo
3>	Permutation (Memorized) % MOD	4>	Combination (Memorized) % MOD
Written by Priyanshu Das*/

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define max_n 1000010

using namespace std;
ll perm[max_n+1], MOD = 0;
bool not_prime[max_n+1];		//limit defined in preprocessor directive
vector <ll> primes;
ll prime_loc[max_n+1];
vector <ll> Factors[max_n+1];

ll combine(ll n, ll r)
{
	ll ans = 1;
	ll ct[primes.size()] = {0};
	memset(ct, 0, sizeof(ct));
	for(int curr = 1; curr <= n; curr++)
	{
		ll tmp = curr;
		for(int i = 0; i < Factors[curr].size(); i++)
		{
			ll c = 0, fac = Factors[curr][i];
			while(tmp%fac == 0)
			{
				c++;
				tmp /= fac;
			}
			ct[prime_loc[fac]] += c;
			if(curr <= r)
				ct[prime_loc[fac]] -= c;
			if(curr <= (n-r))
				ct[prime_loc[fac]] -= c;
		}
	}
	for(int i = 0; i < primes.size(); i++)
	{
		while(ct[i] > 0)
		{
			ct[i]--;
			ans = (ans*primes[i])%MOD;
		}
	}
	return ans;
}

ll lucas(ll n, ll r)
{
	//pf("Finding C(%lld, %lld)\tMOD\t%lld\n", n, r, MOD);
	vector <ll> ni, ri;
	ll nx = n, rx = r, ans = 1, i = 0;
	while(nx > 0 || rx > 0)
	{
		ni.pb(nx%MOD);	ri.pb(rx%MOD);
		nx /= MOD;
		rx /= MOD;
		if(rx > nx)
			return 0;
		ll cur = combine(ni[i], ri[i])%MOD;
		//pf("(%lld, %lld)\t==\t%lld\n", ni[i], ri[i], cur);
		ans = (ans*cur)%MOD;
		i++;
	}
	return ans;
}

int main()
{
    not_prime[0] = 1;
    not_prime[1] = 1;
	for(ll i = 2; i < max_n; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			prime_loc[i] = (ll)primes.size();
			primes.pb(i);
			for(ll j = i; j < max_n && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				Factors[j].pb(i);
				not_prime[j] = 1;
			}
		}
	}
	int T;	cin >> T;
	while(T--)
	{
		ll n, k;	sf("%lld%lld%lld", &n, &k, &MOD);
		perm[0] = 1;
		for(int i = 1; i < max_n; i++)
			perm[i] = (perm[i-1]*i)%MOD;
		ll X = n/k;
		if(n%k != 0)
			X++;
		ll Y = (k - n%k)%k;
		ll ans = lucas(X+Y-1, Y);
		pf("%lld %lld\n", X, ans);
	}
	return 0;
}