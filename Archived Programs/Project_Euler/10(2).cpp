#include <bits/stdc++.h>
#define pf printf
#define sf scanf

using namespace std;

long long int sum = 0;
bool sieve[100000001];
int main()
{
	long long int ct = 0;
	long long int inp;
	sf ("%lld", &inp);
	for(long long int i = 2; i < inp+1 ; i++)
	{
		if (sieve[i] == 0)
		{
			sum += i;
			ct++;
			long long int lim = (inp+1)/i;
			for (long long int j = i; j <= lim; j++)
				sieve[i*j] = 1;
		}
		if (i == inp)
			pf ("Ans is %lld", sum);
	}
	return 0;
}