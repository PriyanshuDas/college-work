#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert
#define n_max 2000

using namespace std;

int memo[n_max+1][n_max+1];
string s1, s2;

int dp(int x, int y)
{
	if (x >= s1.size() && y >= s2.size())
		return 1;
	if(x >= s1.size() || y >= s2.size())
		return 0;
	if(memo[x][y] != -1)
		return memo[x][y];
	memo[x][y] = 0;
	if(s1[x] == '*')
	{
		memo[x][y] = max(max(dp(x+1, y), dp(x+1, y+1)), max((max(dp(x+1, y+2), dp(x+1, y+3))), max(memo[x][y], dp(x+1, y+4))));
	}
	if(s2[y] == '*')
	{
		memo[x][y] = max(max(dp(x, y+1), dp(x+1, y+1)), max((max(dp(x+2, y+1), dp(x+3, y+1))), max(memo[x][y], dp(x+4, y+1))));
	}
	if(s1[x] != s2[y])
		return memo[x][y];
	else
		return dp(x+1, y+1);
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		memset(memo, -1, sizeof(memo));
		cin >> s1 >> s2;
		int ans = dp(0, 0);
		pf("Case #%d: ", t+1);
		if(ans == 1)
			pf("TRUE\n");
		else
			pf("FALSE\n");
	}
	return 0;
}