#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)
#define n_max 200001

using namespace std;
vector <int> col;
vector <int> edg[n_max+2];
int N, M, K;
map<int, int> Col;
int visited[n_max+2];

int dfs(int n)
{
	Col[col[n-1]]++;
	visited[n] = -1;
	int ans = 1;
	for(int i = 0; i < edg[n].size(); i++)
	{
		if(visited[edg[n][i]] == 0)
		{
			ans += dfs(edg[n][i]);
		}
	}
	visited[n] = 1;
	return ans;
}

int main()
{
	cin >> N >> M >> K;
	for(int n = 0; n < N; n++)
	{
		int c;	sf("%d", &c);
		col.pb(c);
	}
	for(int m = 0; m < M; m++)
	{
		int x, y;	sf("%d%d", &x, &y);
		edg[x].pb(y);
		edg[y].pb(x);
	}
	ll ans = 0;
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 0)
		{
			Col.clear();
			int tot = dfs(i);
			int m_c = 0;
			map<int, int>::iterator it;
			for(it = Col.begin(); it != Col.end(); it++)
			{
				m_c = max(it->second, m_c);
			}
			ans += tot-m_c;
		}
	}
	cout << ans << endl;
	return 0;
}
