#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define i_m 10000000000000001
using namespace std;

map<ll, ll> sum)fact;
map<ll, int> prime;

ll sum_factors(ll Pika, map<ll, int> fct_use)
{
	ll sum = 0;
	if(prime[Pika] == 1)
		sum += prime[Pika];
	else
	{
		for(ll I = 2; I*I <= Pika ; I++)
		{
			if(Pika%I == 0)
			{
				int Pika_I = Pika/I;
				sum_fact[Pika_I] = sum_factors(Pika_I, fct_use);
				if(fct_use[Pika_I] == 0)
				{
					sum += prime[Pika_I];
					fct_use[Pika_I] = 1;	
				}
				
			}
		}
	}
	return sum+Pika;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		ll N;
		scanf("%d", &N);
		for(ll j = 2; j*j <= N; j++)
		{
			if()
		}
	}
	return 0;
}