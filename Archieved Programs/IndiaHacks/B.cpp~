#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;
vector <char> ai[6];

ll dp (char c, int pos)
{
	int n_v = c - 'a';
	ll ans = 0;
	if(pos == 1)
	{
		return ai[n_v].size();
	}
	for(int i = 0; i < ai[n_v].size(); i++)
	{
		char c1 = ai[n_v][i];
		ans += dp(c1, pos-1);
	}
	return ans;
}

int main()
{
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < q; i++)
	{
		string s;
		char c;
		cin >> s >> c;
		ai[c-'a'].pb(s[0]);
	}
	ll ans = dp('a', n-1);
	cout << ans;
	return 0;
}
