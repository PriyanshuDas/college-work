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

using namespace std;
vector <string> ans;
int marks[2] = {0, 0};
int memo[51][51][51];

int dp(int pos, int s1, int s2)
{
	if(pos == ans[0].size())
	{
		if(s1 == marks[0] && s2 == marks[1])
			return 0;
		else
			return -99;
	}

	if(memo[pos][s1][s2] != -1)
		return memo[pos][s1][s2];

	int true_s1 = s1, true_s2 = s2;
	if(ans[0][pos] == 'T')
		true_s1++;
	if(ans[1][pos] == 'T')
		true_s2++;

	int false_s1 = s1, false_s2 = s2;
	if(ans[0][pos] == 'F')
		false_s1++;
	if(ans[1][pos] == 'F')
		false_s2++;

	int ans_t = dp(pos+1, true_s1, true_s2);
	int ans_f = dp(pos+1, false_s1, false_s2);
	if(ans[2][pos] == 'T')
		ans_t++;
	else
		ans_f++;

	memo[pos][s1][s2] = max(ans_t, ans_f);
	return memo[pos][s1][s2];
}

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int N, Q;	cin >> N >> Q;
		int total = 0;
		ans.clear();
		for(int i = 0; i < N+1; i++)
		{
			string s;	cin >> s;
			ans.pb(s);
		}

		for(int i = 0; i < N; i++)
			sf("%d", &marks[i]);

		if(N == 1)
		{
			int same = 0, different = 0;
			//cout << ans[0] << endl << ans[1] << endl;
			for(int i = 0; i < Q; i++)
			{
				if(ans[0][i] == ans[1][i])
					same++;
			}
			different = Q - same;

			if(marks[0] <= same)
				total = marks[0] + different;

			else
			{
				total = same + (Q - marks[0]);
			}
			pf("Case #%d: %d\n", t, total);
		}
		else
		{
			memset(memo, -1, sizeof(memo));
			total = dp(0, 0, 0);
			pf("Case #%d: %d\n", t, total);
			continue;
		}
	}
	return 0;
}