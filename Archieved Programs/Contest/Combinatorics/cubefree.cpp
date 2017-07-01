#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define lim 1000000

using namespace std;

int cub_count[lim+1];
bool prime[1001];
bool cub[lim+1];
int main()
{
	for(int i = 2; i < 1000001; i++)
	{
		cub_count[i] = cub_count[i-1];
		if(i <= 1000 && !prime[i])
		{
			for(int j = i*i; j <= 1001; j+= i)
			{
				prime[j]++;
			}
			ll cube = i*i*i;
			for(ll j = cube; j <= lim; j+= cube)
			{
				cub[j] = 1;
			}
		}
		if(cub[i])
			cub_count[i]++;
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		ll inp;
		sf("%lld", &inp);
		pf("Case %d: ", i+1);
		if(cub[inp])
			pf("Not Cube Free\n");
		else
		{
			pf("%lld\n", inp - cub_count[inp]);
		}
	}
}
