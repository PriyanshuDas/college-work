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
#define n_max 200000
using namespace std;

int col[n_max+1];
int max_col = 0;
vector <int> adj[n_max+1];

void dfs(int pos, int par)
{
	int color = 1;
	for(int i = 0; i < adj[pos].size(); i++)
	{
		if(adj[pos][i] == par)
			continue;
		while(color == col[pos] || color == col[par])
			color++;
		col[adj[pos][i]] = color;
		max_col = max(color, max_col);
		color++;
	}
	for(int i = 0; i < adj[pos].size(); i++)
	{
		if(adj[pos][i] != par)
			dfs(adj[pos][i], pos);
	}
}

int main()
{
	int n;	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int x, y;	sf("%d%d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	col[1] = 1;
	dfs(1, 1);
	pf("%d\n", max_col);
	for(int i = 1; i <= n; i++)
	{
		pf("%d ", col[i]);
	}
	return 0;
}