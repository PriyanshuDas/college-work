#include<bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

int main()
{

	ll T;
	scanf("%lld", &T);
	for (ll i = 0; i < T; i++)
	{
		int even = 0, odd = 0;
		ll N;
		scanf("%lld", &N);
		for(ll j = 0; primes[j]*primes[j] <= N; j++)
		{
			int ct = 0;
			int curr_p = primes[j];
			while(N%curr_p == 0)
			{
				ct++;
				N/=curr_p;
			}
			if (ct%2 == 0 && ct != 0)
				even++;
			else if(ct!=0)
				odd++;
		}
		if(N>1)
			odd++;
		if(even>odd)
			printf("Psycho Number\n");
		else
			printf("Ordinary Number\n");
	}
	return 0;
}