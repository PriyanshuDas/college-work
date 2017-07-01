#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ins insert
#define pb push_back
#define mp make_pair
#define max_pos 100001
#define max_par 501
#define INF 100000000000000000

using namespace std;
vector <ll> A;
int N, K;
ll memo[max_pos+1][max_par+1];

ll dp(int pos, int par)
{
	if(par == K && pos == N)
		return 0;
	if(pos >= N || par >= K)
		return INF;
	if(memo[pos][par] != -1)
		return memo[pos][par];
	memo[pos][par] = INF;
	ll mx_v = A[pos], mn_v = A[pos];
	for(int i = pos+1; i < N; i++)
	{
		if(A[i] < mn_v)
			mn_v = A[i];
		if(A[i] > mx_v)
			mx_v = A[i];
		memo[pos][par] = min(memo[pos][par], mx_v - mn_v + dp(i+1, par+1));
	}
	//pf("@(%d, %d) \t \t %lld\n", pos, par, memo[pos][par]);
	return memo[pos][par];
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		sf("%d%d", &N, &K);
		A.clear();
		for(int i = 0; i < N; i++)
		{
			ll tmp;	sf("%lld", &tmp);
			A.pb(tmp);
		}
		for(int i = 0; i <= N; i++)
		{
			for(int j = 0; j <= K; j++)
				memo[i][j] = -1;
		}
		sort(A.begin(), A.end());
		ll ans = dp(0, 0);
		pf("%lld\n", ans);
	}
	return 0;
}
