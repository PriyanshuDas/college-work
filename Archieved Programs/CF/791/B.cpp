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
#define n_max 150001

using namespace std;

int graph_no[n_max+1];
vector <int> adj[n_max+1];

vector <int> graph[n_max+1];

int c_g = 0;
int n, m;

void dfs(int u, int p)
{
	graph_no[u] = c_g;
	graph[c_g].pb(u);
	for (int i = 0; i < adj[u].size(); i++)
	{
		if(graph_no[adj[u][i]] != c_g)
			dfs(adj[u][i], u);
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;	sf("%d%d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(graph_no, -1, sizeof(graph_no));
	for(int i = 1; i <= n; i++)
	{
		if(graph_no[i] == -1)
		{
			c_g++;
			dfs(i, i);
		}
	}


	for(int i = 1; i <= c_g; i++)
	{
		int sz = graph[i].size()-1;
		for(int j = 0; j < graph[i].size(); j++)
		{
			if(adj[graph[i][j]].size() != sz)
			{
				pf("NO");
				return 0;
			}
		}
	}
	pf("YES");
	return 0;
}