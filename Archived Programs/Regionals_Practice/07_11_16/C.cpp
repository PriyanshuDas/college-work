#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;

ll ans[1000001];

int main()
{
	int p;	cin >> p;
	memset(ans, -1, sizeof(ans));
	for(ll i = 0; i < p; i++)
	{
		ll t = (i*i)%p;
		ans[t] = i;
	}
	for(int i = 0; i < p; i++)
	{
		printf("%lld ", ans[i]);
	}
	return 0;
}

// Check max case before submitting if possible!!
