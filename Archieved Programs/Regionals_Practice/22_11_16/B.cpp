#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back

using namespace std;

int main()
{
	int N;	cin >> N;
	for(int n = 0; n < N; n++)
	{
		int P, Q;	sf("%d%d", &P, &Q);
		string X, Y;
		cin >> X >> Y;
		int dp[P+1][Q+1];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= X.size(); i++)
		{
			for(int j = 1; j <= Y.size(); j++)
			{
				int c = max(dp[i-1][j], dp[i][j-1]);
				if(X[i-1] == Y[j-1])
				{
					c = max(c, dp[i-1][j-1]+1);
				}
				dp[i][j] = c;
			}
		}
		ll ans = P + Q - dp[P][Q];
		pf("Case %d: %lld\n", n+1, ans);
	}
	return 0;
}
