#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back

using namespace std;

int visited[502];
vector <int> adj[502];

void dfs(int pos, int col)
{
	visited[pos] = col;
	for(int i = 0; i < adj[pos].size(); i++)
	{
		if(visited[adj[pos][i]] == -1)
			dfs(adj[pos][i], (col+1)%2);
	}
}

int main()
{
	int N;	cin >> N;
	for(int n = 0; n < N; n++)
	{
		int K;	sf("%d", &K);
		for(int k = 1; k <= K; k++)
		{
			adj[k].clear();
			int p;	sf("%d", &p);
			for(int i = 0; i < p; i++)
			{
				int tmp;	sf("%d", &tmp);
				adj[k].pb(tmp);
			}
		}
		
		memset(visited, -1, sizeof(visited));
		for(int i = 1; i <= K; i++)
		{
			if(visited[i] == -1)
				dfs(i, 0);
		}
		
		int t[2] = {0}, flag = 1;
		
		for(int i = 1; i <= K; i++)
		{
			t[visited[i]]++;
			for(int j = 0; j < adj[i].size(); j++)
			{
				if(visited[i] == visited[adj[i][j]])
					flag = 0;
			}
		}
		if(t[0] > t[1])
			swap(t[0], t[1]);
		
		if(flag == 0)
			pf("Case %d: 0 0 0\n", n+1);
		else
			pf("Case %d: 1 %d %d\n", n+1, t[0], t[1]);
	}
	return 0;
}
