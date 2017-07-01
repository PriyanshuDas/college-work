#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned ll
#define pos_max 100001
#define n_max 100001

using namespace std;

ll k_max = 0, cd;

ull dp(int N, int pos, int mx)
{
	if(N == cd && pos == k_max)
	{
		return 1;
	}
	if(N < cd || pos == k_max)
		return 0;
	if(mx == 1)
	{
		int req = N - cd*(k_max-pos+1);
		if(req <= k_max - pos && req >= 0)
		{
			return 1;
		}
		return 0;
	}
	if(mx == 0)
	{
		int req = N - cd*(k_max-pos+1);
		if(req == 0)
			return 1;
		return 0;
	}
	//pf("@(%d\t%d\t%d)\t%llu\t%llu\n", N, pos, mx, k_max, cd);
	ull ans = dp(N-cd,pos+1, 0) + dp(N - (cd+1), pos+1, 1) + dp(N-(cd+2), pos+1, 2);
	return ans;
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N, D;
		cin >> N >> D;
		ull ans = 0;
		for(int i = 1; D*i <= N; i++)
		{
				k_max = i-1;
				cd = ((N/i) - (N/i)%D);
				while(cd > 0 && cd*i + (i-1)*(2) >= N)
				{
					ull ans2 = dp(N, 0, 2);
					ans += ans2;
					cd = cd-D;
					//pf("For (%d\t%lld)\t%lld\n", i, cd, ans2);
				}
		}
		pf("Case #%d: %llu\n", t+1, ans);
	}
	return 0;
}
