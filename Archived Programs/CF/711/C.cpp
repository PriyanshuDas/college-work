#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define mp make_pair
#define pi2 pair <ll, ll>
#define pi3 pair <ll, pair<ll, ll> >
#define n_max 101
#define k_max 101
#define m_max 101
#define INF 999999999999

using namespace std;

int n, k, m;
ll mem[n_max][m_max][k_max];			//(tree, last_tree_col, beauty so far)
vector <int> color;
ll cost[n_max][m_max];

ll dp(ll tree, ll l_col, ll beauty)
{
	//pf("@(%lld, %lld, %lld)\n", tree, l_col, beauty);
	if(mem[tree][l_col][beauty] != -999999999)
		return mem[tree][l_col][beauty];
	if(tree == n && beauty == m)
	{
		mem[tree][l_col][beauty] = 0;
		return 0;
	}
	if(tree == n && beauty != m)
	{
		return INF;
	}
	ll ans = INF;
	if(color[tree] != 0)
	{
		if(color[tree] != l_col)
			mem[tree][l_col][beauty] = dp(tree+1, color[tree], beauty+1);
		else
			mem[tree][l_col][beauty] = dp(tree+1, color[tree], beauty);
		ans = mem[tree][l_col][beauty];
		return mem[tree][l_col][beauty];
	}
	for(int i = 0; i < k; i++)
	{
		if(i+1 != l_col)
			ans = min(ans, dp(tree+1, i+1, beauty+1) + cost[tree][i]);
		else
			ans = min(ans, dp(tree+1, i+1, beauty) + cost[tree][i]);
	}
	mem[tree][l_col][beauty] = ans;
	return ans;
}

int main()
{
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		color.pb(tmp);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			sf("%lld", &cost[i][j]);
		}
	}
	for(int i = 0; i < n_max; i++)
		for(int j = 0; j < m_max; j++)
			for(int k = 0; k < k_max; k++)
				mem[i][j][k] = -999999999;
	ll ans = dp(0, 0, 0);
	if(ans >= INF)
		cout << "-1";
	else
		cout << ans << endl;
	return 0;
}
