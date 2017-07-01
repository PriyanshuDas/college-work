#include <bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

bool sieve[1000001];
int main()
{
	int ct = 0;
	for(long long int i = 2; i < 1000000; i++)
	{
		if (sieve[i] == 0)
		{
			ct++;
			long long int lim = 1000000/i;
			for (int j = i; j <= lim; j++)
				sieve[i*j] =1;
			if (ct == 10001)
			pf ("%d - %lld\n", ct, i);
		}
	}
	return 0;
}