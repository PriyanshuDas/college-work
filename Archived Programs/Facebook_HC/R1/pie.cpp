#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define pi2 pair <ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >

using namespace std;

ll INF = 9999999999999999;
ll memo[301][301];
int N, M;
vector <ll> pies[301];

ll dp(int pos, int p_ct)
{
	if(pos == N)
	{
		if(p_ct >= N)
			return 0;
		return INF;
	}
	if(memo[pos][p_ct] != -1)
		return memo[pos][p_ct];

	memo[pos][p_ct] = INF;
	ll cur = 0;
	for(int c_p = 0; c_p <= pies[pos].size() && p_ct + c_p <= N; c_p++)
	{
		if(p_ct+c_p >= pos+1)
			memo[pos][p_ct] = min(memo[pos][p_ct], c_p*c_p + cur+dp(pos+1, p_ct+c_p));
		if(c_p < pies[pos].size())
			cur += pies[pos][c_p];
	}
	//pf("DP(%d, %d) == %lld\n", pos, p_ct, memo[pos][p_ct]);
	return memo[pos][p_ct];
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		sf("%d%d", &N, &M);
		for(int n = 0; n < N; n++)
		{
			pies[n].clear();
			for(int m = 0; m < M; m++)
			{
				ll tmp;	sf("%lld", &tmp);
				pies[n].pb(tmp);
			}
			sort(pies[n].begin(), pies[n].end());
		}
		memset(memo, -1, sizeof(memo));
		ll ans = dp(0, 0);
		pf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}