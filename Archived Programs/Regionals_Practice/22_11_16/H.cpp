#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int

using namespace std;

ll dist[105][105];
ll dp[105][105];
ll l_sum[105];

ll find(int i,int j)
{
	if(i >= j)
	{
		dp[i][j] = 0;
		return 0;
	}
	if(dp[i][j] != -1)
		return dp[i][j];
	
	ll ans = 999999;
	
	if(i == 0)
	{
		dp[i][j] = l_sum[j];
		return dp[0][j];
	}
	if(j == 0)
	{
		dp[i][j] = l_sum[i];
		return dp[i][j];
	}
	if(j > i+1)
		ans = find(i, i+1) + l_sum[j] - l_sum[i+1];
	else
	{
		for(int k = 0; k < i; k++)
		{
			ll curr = find(k, i) + dist[k][i+1];
			ans = min(ans, curr);
		}
	}
	
	dp[i][j] = ans;
	return ans;
}

int main()
{
	ll N;	sf("%lld", &N);
	for(ll t = 1; t <= N; t++)
	{
		ll K, R;	sf("%lld%lld", &K, &R);
		for(ll i = 0; i < K+2; i++)
		{
			ll x;	sf("%lld", &x);
			dist[x][x] = 0;
			for(ll j = 0; j < K+1; j++)
			{
				ll y, d;	sf("%lld%lld", &y, &d);
				dist[x][y] = d;
			}
		}
		ll ans = 999999;
		l_sum[0] = 0;
		memset(l_sum, 0, sizeof(l_sum));
		for(int i = 1; i <= K+1; i++)
			l_sum[i] = l_sum[i-1] + dist[i-1][i];
		
		memset(dp, -1, sizeof(dp));
		
		/*for (int i = 0; i <= K+1; i++)
		{
			for(int j = 0; j <= K+1; j++)
				pf("%lld\t", find(i, j));
			cout << endl;
		}*/
		
		for(int i = 0; i < K+1; i++)
		{
			ans = min(find(i, K+1) + dist[i][K+1], ans);
		}
		ans += (K+1)*R;
		pf("Case %lld: %lld\n", t, ans);
	}
	return 0;
}
