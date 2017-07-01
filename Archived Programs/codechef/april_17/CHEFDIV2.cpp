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
#define ull unsigned ll

using namespace std;

ll start, End;		//end is maximum ~~ 10^14 for 2 sec		difference should be maximum 10^8

bool not_prime_1[limit];
bool not_prime[limit];
vector <ll> primes;
vector <ll> factors[limit];
//map<ll, ll> memo;


/*
Some problem for Large numbers...? overflow?
*/
int main()
{
	sf("%lld%lld", &start, &End);
	ll lower_limit = sqrt(End)*10;
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
			for(ll j = low_lim*i; j <= End && j >= 0; j += i)
			{
				if(j-start >= 0)
				{
					factors[j-start].pb(i);
					not_prime_1[j-start] = 1;
				}
			}
		}
	}
	ull fin_ans = 0;
	for(int i = 0; i <= (End-start); i++)
	{
		if(!not_prime_1[i])
		{
			primes.pb(start + i);
			factors[i].pb(start + i);
		}
		ll curr = i+start;
		//pf("Calculating for %lld\n", curr);
		ll c_n = 0;
		ull c_mult = 1;
		ull c_ans = 0;
		vector <ll> ct;
		ll tmp = curr;
		for(int j = 0; j < factors[i].size(); j++)
		{
			int c = 0;
			while(tmp%factors[i][j] == 0)
			{
				c++;
				tmp /= factors[i][j];
			}
			ct.pb(c);
		}
		if(tmp > 1)
		{
			ct.pb(1);
			factors[i].pb(tmp);
		}
		sort(ct.rbegin(), ct.rend());
		while(ct.size() > 0 && ct[0] > 0)
		{
			c_n++;
			for(int j = 0; j < ct.size(); j++)
			{
				if(ct[j] == 0)
					break;
				ct[j]--;
				c_mult = (c_mult*(c_n+1))/c_n;
				c_ans += c_mult;
				
			}
		}
		//pf("%lld\t%lld\n", curr, c_ans);
		fin_ans += c_ans;
	}
	pf("%llu\n", fin_ans);
	return 0;
}
