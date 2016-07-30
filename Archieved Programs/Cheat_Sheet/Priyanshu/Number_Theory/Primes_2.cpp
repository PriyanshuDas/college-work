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

using namespace std;

ll start, end;		//end is maximum ~~ 10^14 for 2 sec		difference should be maximum 10^8

bool not_prime_1[limit];
bool not_prime[limit];
vector <ll> primes;
vector <ll> factors[limit];

int main()
{
	pf("Enter Start and End : ");
	sf("%lld%lld", &start, &end);
	ll lower_limit = sqrt(end);
	for(ll i = 2; i < lower_limit; i++)
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
			for(ll j = low_lim*i; j <= end; j += i)
			{
				factors[j-start].pb(i);
				not_prime_1[j-start] = 1;
			}
		}
	}
	for(int i = 0; i < (end-start)/1000; i++)
	{
		if(!not_prime_1[i])
		{
			primes.pb(start + i);
			factors[i].pb(start + i);
		}
		pf("\nPrime Factors of %lld are :\n", (start + i));
		for(int j = 0; j < factors[i].size(); j++)
		{
			pf("%lld ", factors[i][j]);
		}
	}
}
