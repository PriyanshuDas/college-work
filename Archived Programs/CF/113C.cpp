#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define P_max 300000001
#define limit 300000001
#define sq_lim 17321
using namespace std;

//ull l_pr[P_max+1];
bool sq[P_max+1] = {0};
bool not_prime[limit];		//limit defined in preprocessor directive
int main()
{
	//				N*log(N) Sieve
	not_prime[0] = 1;
    not_prime[1] = 1;
	for(int i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			for(ll j = i*i; j < limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				not_prime[j] = 1;
			}
		}
	}

	/*				Linear Prime Sieve
	for(int i = 2; i < P_max; i++)
	{
		if(l_pr[i] == 0)
		{
			primes.pb(i);
			l_pr[i] = i;
		}
		for(int j=0;j<primes.size()&&primes[j]*i<P_max&&primes[j]<=l_pr[i];j++)
		{
			l_pr[primes[j]*i] = primes[j];
		}
	}
	*/
	//cout << primes.size() << endl;
	for(ull i = 1; i < sq_lim; i++)
	{
		for(ull j = i+1; j < sq_lim; j++)
		{
			ull tmp = i*i + j*j;
			if(tmp >= P_max)
				break;
			sq[i*i+j*j] = 1;
		}
	}
	/*for(int i = 0; i < 100; i++)
	{
		ull sq_l = sqrt(primes[i]);
		for(ull j = 1; j <= sq_l; j++)
		{
			ull n = primes[i]-(j*j);
			if(n > 0 && sq[(ull)sqrt(n)] == n)
			{
				ct++;
				pf("%llu\t==\t%llu\t+\t%llu\t\t%d\n", primes[i], j*j,  n, ct);
				break;
			}
		}	
	}*/
	ull l, r, ct = 0;
	sf("%llu%llu", &l, &r);
	for(ull i = l; i <= r; i++)
	{
		if(not_prime[i] == 0 && sq[i] == 1)
			ct++;
	}
	cout << ct;
	return 0;
}
