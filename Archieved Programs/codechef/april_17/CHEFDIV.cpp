/*	Primes Part II
	Includes:
(1)	Segmented Sieve
(2)	Segmented Prime Factorization

	Written By :- Priyanshu Das	*/

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair
#define limit 10000000
#define fi first
#define se second
#define mem_lt 100000000
using namespace std;

ll start, End;		//end is maximum ~~ 10^14 for 2 sec		difference should be maximum 10^8

bool not_prime_1[limit];
bool not_prime[limit];
vector <ll> primes;
vector <ll> factors[limit];
//map<ll, ll> memo;
int memo[mem_lt];

ll curr;

ll dp(ll n)
{
	if(n < mem_lt && memo[n] != -1)//memo.find(n) != memo.end())
		return memo[n];
	ll c_ans = 0;
	//pf("Prime Factors for %lld\t", n);
	for(int i = 0; i < factors[curr-start].size(); i++)
	{
		//pf("%lld\t", factors[curr-start][i]);
		if(n%factors[curr-start][i] == 0)
			c_ans = max(c_ans, dp(n/factors[curr-start][i]));
	}
	ll c_t = 1;
	for(int i = 0; i < factors[curr-start].size(); i++)
	{
		int ct = 0;
		ll n2 = n;
		while(n2%factors[curr-start][i] == 0)
		{
			ct++;
			n2 /= factors[curr-start][i];
		}
		c_t *= (ct+1);
	}
	//pf("\n(%lld, %lld)\n", n, c_t);
	c_ans = c_ans + c_t;
	if(n < mem_lt)
		memo[n] = c_ans;
	return c_ans;
}

int main()
{
	memset(memo, -1, sizeof(memo));
	sf("%lld%lld", &start, &End);
	ll lower_limit = sqrt(End)+1;
	if(lower_limit < 1000000)
		lower_limit= 1000000;
	not_prime[1] = 1;
	if(start == 1)
		not_prime_1[0] = 1;
	for(ll i = 2; i <= lower_limit; i++)
	{
		if(!not_prime[i])
		{
			ll low_lim = start/i;
			if(start%i != 0)
				low_lim++;
			for(ll j = i*i; j <= lower_limit; j+=i)
			{
				not_prime[j] = 1;
			}
			for(ll j = low_lim*i; j <= End; j += i)
			{
				if(j-start >= 0)
				{
					factors[j-start].pb(i);
					not_prime_1[j-start] = 1;
				}
			}
		}
	}
	ll fin_ans = 0;
	for(int i = 0; i <= (End-start); i++)
	{
		if(!not_prime_1[i])
		{
			primes.pb(start + i);
			factors[i].pb(start + i);
		}
		curr = i+start;
		//pf("Calculating for %lld\n", curr);
		ll c_ans = dp(curr);
		//pf("For %lld\t:\t%lld\n", start+i, c_ans);
		fin_ans += c_ans - 1;
	}
	pf("%lld\n", fin_ans);
	return 0;
}
