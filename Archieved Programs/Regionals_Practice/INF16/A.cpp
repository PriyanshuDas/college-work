/*	Prime Numbers Part I
	Includes :
(1)	Prime Generation (Sieve of Erastothenes)
(2) Prime Factorisation (No powers)

	Written by Priyanshu Das	*/

#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 1000001
#define se second

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <int> primes;
map<ll, int> prime_pos;
vector<int> Factors[limit];

vector <ll> Ext_Euclid(ll a, ll b)	//Solve Ax + By = gcd(A, B)
{
	if(b == 0)
	{
		vector <ll> tmp;	tmp.pb(1);	tmp.pb(0);	tmp.pb(a);
		return tmp;
	}
	vector <ll> curr = Ext_Euclid(b, a%b), nu;
	nu.pb(curr[1]);	nu.pb(curr[0] - (a/b)*curr[1]);	nu.pb(curr[2]);
	return nu;
}
ll inverse_mod(ll n, ll MOD)				//find inverse mod of a number
{
	vector <ll> temp = Ext_Euclid(n, MOD);
	if(temp[0] < 0)	temp[0] += MOD;
	return temp[0];
}
ll comb(ll n, ll r, ll mod)
{
	ll num = 1;
	r = max(r, n-r);
	for(int i = n; i > 0; i--)
		num = (num*i)%mod;
		
	ll den = 1;
	for(int i = 1; i <= r; i++)
		den = (den*i)%mod;
		
	for(int i = 1; i <= n-r; i++)
		den = (den*i)%mod;
	
	den = inverse_mod(den, mod);
	ll ans = (num*den)%mod;
	return ans;
}

ll Lucas (ll n, ll r, ll mod)
{
	vector <ll> N, R;
	while(n != 0)
	{
		N.pb(n%mod);
		n /= mod;
	}
	while(r != 0)
	{
		R.pb(r%mod);
		r /= mod;
	}
	ll ans = 1;
	for(int i = 0; i < N.size(); i++)
	{
		ll n = N[i];
		ll r = 0;
		if(i < R.size())
			r = R[i];
		ans = (ans*comb(n, r, mod))%mod;
	}
	return ans;
}

int main()
{
    not_prime[0] = 1;
    not_prime[1] = 1;
	for(int i = 2; i < limit; i++)
		if(!not_prime[i])
		{
			prime_pos[i] = primes.size();
			primes.pb(i);
			for(ll j = i*i; j < limit && j > 0; j+= i)
				not_prime[j] = 1;
		}
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int L, q;	sf("%d%d", &L, &q);
		pf("Case %d:\n", t+1);
		for(int l = 0; l < L; l++)
		{
			ll N;	sf("%lld", &N);
			ll p1, p2;
			ll st_pos = sqrt(N/10);
			auto it = prime_pos.lower_bound(st_pos);
			int i = 0;
			if(it != prime_pos.end())
				i = it->se;
			for(i; i < primes.size(); i++)
			{
				if(N%primes[i] == 0)
				{
					p1 = primes[i];
					p2 = N/primes[i];
					break;
				}
			}
			ll ans = Lucas(N, p1, q);
			pf("%lld\n", ans);
		}
	}
	return 0;
}
