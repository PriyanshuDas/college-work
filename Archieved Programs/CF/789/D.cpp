#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define n_max 1000005

using namespace std;

using namespace std;

int visited[n_max+1];
int loop[n_max+1];
vector <int> adj[n_max+1];

void dfs(int n, int p)
{
	visited[n] = 1;
	for(int i = 0; i < adj[n].size(); i++)
		if(visited[adj[n][i]] != 1)
			dfs(adj[n][i], n);
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int self_loops = 0;
	for(int i = 0; i < m; i++)
	{
		int u, v;	sf("%d%d", &u, &v);
		adj[u].pb(v);
		if(u != v)
			adj[v].pb(u);
		else
		{
			self_loops++;
			loop[u] = 1;
		}
	}
	memset(visited, -1, sizeof(visited));
	dfs(1, 1);
	ll ans = 0;
	int flag = 0;
	for(int i = 1; i <= n; i++)
	{
		ll s = adj[i].size();
		s = s*(s-1);
		if(s > 2 || n == 2)
			ans += s;
		if(visited[i] != 1)
			flag = 1;
	}
	ans /= 2;
	ll t = (self_loops*(self_loops-1))/2;
	ans += t;
	if(flag)
		cout << 0;
	else
		cout << ans;
	return 0;
}