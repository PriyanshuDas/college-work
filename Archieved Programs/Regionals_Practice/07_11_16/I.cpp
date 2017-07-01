#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define ins insert
#define n_max 200005
#define m_max 200005

using namespace std;

vector<int> adj[n_max];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int aj, bj;
		cin >> aj >> bj;
		adj[aj].pb(bj);
		adj[bj].pb(aj);	
	}
	int m_deg = n_max+1;
	int m_pos = 0;
	for(int i = 1; i <= n; i++)
	{
		if(adj[i].size() < m_deg)
		{
			m_deg = adj[i].size();
			m_pos = i;
		}
	}
	int ans[n_max+1] = {0};
	for(int i = 1; i <= n; i++)
	{
		ans[i] = 1;
	}
	for(int i = 0; i < adj[m_pos].size(); i++)
		ans[adj[m_pos][i]] = 0;
	ans[m_pos] = 0;
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}
