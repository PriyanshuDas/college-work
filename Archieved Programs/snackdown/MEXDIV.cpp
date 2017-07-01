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

int main()
{
	ll N, K;
	sf("%lld%lld", &N, &K);
	vector <ll> A;
	for(int i = 0; i < N; i++)
	{
		ll tmp;
		sf("%lld", &tmp);
		A.pb(tmp);
	}
	ll dp[N+5] = {0};
	ll sum[N+5] = {0};

	int x = N-1;						// x is the last element st mex[i, x] <= k
	map <ll, int> ct;
	ll mex = 0;
	dp[N] = 1;
	sum[N] = 1;

	for(int i = N-1; i >= 0; i--)
	{
		ct[A[i]]++;
		while(ct[mex] > 0)
			mex++;

		while(mex > K)
		{
			ct[A[x]]--;
			if(A[x] < mex && ct[A[x]] == 0)
				mex = A[x];
			while(ct[mex-1] == 0 && mex != 0)
				mex--;
			x--;
		}
		dp[i] = (sum[i+1] + (MOD - sum[x+2]))%MOD;
		while(dp[i] < 0)
			dp[i] += MOD;
		sum[i] = (sum[i+1] + dp[i])%MOD;
	//pf("@(%d\tmex : %d\tx : %d\tdp[i] == %lld)\n", i, mex, x, dp[i]);
	}
	pf("%lld", dp[0]);
	return 0;
}