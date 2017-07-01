#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define n_max 1000006

using namespace std;

ll MOD = 1000000007;
ll N, K;
vector <ll> A;

ll memo[n_max+1];

ll dp(int pos)
{
	if(pos > N)
		return 0;
	if(pos == N)
		return 1;
	if(memo[pos] != -1)
		return memo[pos];
	map<int, int> mex;
	ll ans = 0;
	for(int i = pos; i < N; i++)
	{
		mex[A[i]] = 1;
		int flag = 0;
		for(int j = 0; j <= K; j++)
			if(mex[j] == 0)
				flag = 1;

		if(flag == 1)
			ans = (ans + dp(i+1))%MOD;
	}
	memo[pos] = ans;
	return ans;
}

int main()
{
	/*memset(memo, -1, sizeof(memo));
	sf("%lld%lld", &N, &K);
	for(int i = 0; i < N; i++)
	{
		ll tmp;
		sf("%lld", &tmp);
		A.pb(tmp);
	}
	ll ans = dp(0);
	pf("%lld", ans);*/

	pf("%lld", -105%MOD);
	return 0;
}