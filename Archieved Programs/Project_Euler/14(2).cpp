#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define pb push_back
#define ll long long int
#define MAX 100000000
#define MAX2 1000000000
using namespace std;

ll mem[MAX];

int Collatz(ll n, ll step)
{
	ll s;
	if (n==1)
	{
		return step;
	}
	if (n < MAX && mem[n])
		return (mem[n]+step);
	if (n%2 == 0)
		s = Collatz(n/2, step+1);
	else
		s = Collatz(3*n + 1, step+1);
	
	return s;
}
int main()
{
	int max = 0;
	int curr = 0;
	/*while (1)
	{
		sf("%llu", &curr);
		ll ans = Collatz(curr, 0);
		pf ("%llu", ans);
	}*/
	for(int i = 1; i < MAX2; i++)
	{
		curr = Collatz(i, 1);
		if (i < MAX)
			mem[i] = curr;
		//pf("%d  %lld \n", i, curr);
		if (curr > max)
		{
			pf("Maxima at i = %d, Length = %d\n", i, curr);
			max = curr;
		}
	}
	pf("max is %d\n", max);
	return 0;
}