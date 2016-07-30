#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	ll T;
	scanf("%lld", &T);
	for (ll i = 0; i < T; i++)
	{
		ll N;
		scanf("%lld", &N);
		int odd = 0, even = 0;

		for (ll j = 2; j*j <= N; j++)
		{
			int ct = 0;
			while(N%j == 0)
			{
				N /= j;
				ct++;
			}
			if(ct%2 == 0 && ct != 0)
				even++;
			else if (ct != 0)
				odd++;
		}
		if(N > 1)
			odd++;
		if (even > odd)
			printf("Psycho Number\n");
		else
			printf("Ordinary Number\n");
	}
	return 0;
}