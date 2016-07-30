#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define pb push_back
#define max = 10000001
#define ll long long int
using namespace std;

vector <int> prime;

int no_factors(ll num)
{
	int a = 1;
	for (int i = 0; i < prime.size(); i++)
	{
		int temp = 0;
		while (num%prime[i] == 0)
		{
			num /= prime[i];
			temp++;
		}
		a *= (temp+1);
		if (num < prime[i])
			break;
	}
	pf ("Factors = %d\n", a);
	return a;
}

bool sieve[10000001];
int main()
{
	ll ans = 0;
	for (long long int i = 2; i < 10000000; i++)
	{
		if (sieve[i] == 0)
		{
			prime.push_back (i);
			int limit = 10000000/i;
			for (int j = i; j < limit ;j++)
			{
				sieve[i*j] = 1;
			}
		}
	}
	pf ("H E R E !\n");
	long long int curr_num = 1;
	for (int i = 2; i < 10000000; i++)
	{
		curr_num += i;
		if (no_factors(curr_num) >= 500)
		{
			pf ("The answer is %lld\n", curr_num);
			return 0;
		}
	}
	return 0;
}