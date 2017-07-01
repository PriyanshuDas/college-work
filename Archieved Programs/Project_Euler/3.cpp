#include <bits/stdc++.h>
#define ll long long int
#define sf scanf
#define pf printf

using namespace std;

ll N = 600851475143;
ll B = 775146;
int main()
{
	ll ans = 0;
	int sieve[775147] = {0};
	for (ll i = 2; i < B; i++)
	{
		if (sieve[i] == 0)
		{
			for (int j = i; i*j <= B;j++)
			{
				sieve[i*j] = 1;
			}
		
		if (N%i == 0)
			ans = i;
		}

	}
	pf("Ans is : %lld\n", ans);
	return 0;
}