#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair <ll, pi2 >
#define pi4 pair<pi2, pi2>
#define loop(l,r) for(int i = l; i < r; i++)
#define ull unsigned long long int
#define n_max 200001

using namespace std;

int s, t, ds, dt, c_comp = 0, f_st = 0;
int comp[n_max+1], visited[n_max+1];
vector <pair<int,int> > ans;
vector <int> adj[n_max+1];
map <int, int> s_adj, t_adj;
map <int, pair<int, int> > st_adj;	// (comp, (s_adj, t_adj))

void set_comp(int x)
{
	comp[x] = c_comp;
	visited[x] = -1;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int nxt = adj[x][i];
		if(nxt != s && nxt != t && visited[nxt] == 0)
		{
			//fin[x].pb(nxt);
			//fin[nxt].pb(x);
			ans.pb(mp(x,nxt));
			set_comp(nxt);
		}
	}
	visited[x] = 1;
}

int main()
{
	int n, m;	cin >> n >> m;
	vector<pair<int, int> > inp;
	loop(0, m)
	{
		int x, y;	sf("%d%d", &x, &y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	sf("%d%d%d%d", &s, &t, &ds, &dt);
	for(int i = 1; i <= n; i++)
	{
		if(visited[i] == 0 && i != s && i != t)
		{
			c_comp++;
			set_comp(i);
		}
	}
	comp[s] = 0;	comp[t] = 0;
	for(int i = 0; i < adj[s].size(); i++)
	{
		int nxt = adj[s][i];
		int c_c = comp[nxt];
		if(nxt == t)
			f_st = 1;
		if(c_c != 0 && s_adj.find(c_c) == s_adj.end())
		{
			s_adj[c_c] = nxt;
		}
	}
	for(int i = 0; i < adj[t].size(); i++)
	{
		int nxt = adj[t][i];
		int c_c = comp[nxt];
		if(c_c != 0 && st_adj.find(c_c) == st_adj.end() && t_adj.find(c_c) == t_adj.end())
		{
			t_adj[c_c] = nxt;
			if(s_adj.find(c_c) != s_adj.end())
			{
				int s_nxt = s_adj[c_c];
				s_adj.erase(c_c);
				t_adj.erase(c_c);
				st_adj[c_c] = mp(s_nxt, nxt);
			}
		}
	}
	//pf("(%lu, %lu)\t%u\n", s_adj.size(), t_adj.size(), st_adj.size());
	while(s_adj.size() > 0)
	{
		ds--;
		int nxt = s_adj.begin()->second;
		ans.pb(mp(s, nxt));
		s_adj.erase(s_adj.begin());
	}
	while(t_adj.size() > 0)
	{
		dt--;
		int nxt = t_adj.begin()->second;
		ans.pb(mp(t, nxt));
		t_adj.erase(t_adj.begin());
	}
	while(ds > 1 && st_adj.size() > 1)
	{
		ds--;
		int nxt = st_adj.begin()->second.first;
		ans.pb(mp(s, nxt));
		st_adj.erase(st_adj.begin());
	}
	while(dt > 1 && st_adj.size() > 1)
	{
		dt--;
		int nxt = st_adj.begin()->second.second;
		ans.pb(mp(t, nxt));
		st_adj.erase(st_adj.begin());
	}
	if(st_adj.size() == 0 && f_st == 1)
	{
		ds--;	dt--;
		ans.pb(mp(s, t));
	}
	if(st_adj.size() > 0)
	{
		ds--;	dt--;
		pair<int, int> nxt = st_adj.begin()->second;
		ans.pb(mp(s, nxt.first));
		ans.pb(mp(t, nxt.second));
		st_adj.erase(st_adj.begin());
	}
	if(ds < 0 || dt < 0 || st_adj.size() > 0)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes\n";
		for(int i = 0; i < ans.size(); i++)
		{
			pf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}
