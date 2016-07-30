/*-------- Finding Articulation Points, Bridges and Bi-connected Components -----------------
								By - Priyanshu Das
-------------------------------------------------------------------------------------------*/


#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define max_n 100001

using namespace std;

vector <int> art_p;
set <int> a_p;
vector<pair<int, int> > bridge;
vector <vector <int> > bccs;
vector <int> conn[max_n];
vector <int> child_tree[max_n];
int par_tree[max_n];
int lvl_tree[max_n];
int low_lvl[max_n];
int visited[max_n];
int root = 0;
vector <int> curr_comp;

void dfs (int node, int par, int lvl)
{
	lvl_tree[node] = lvl;
	par_tree[node] = par;
	visited[node] = 1;
	for(int i = 0; i < conn[node].size(); i++)
		if(visited[conn[node][i]] != 1)
		{
			dfs(conn[node][i], node, lvl+1);
			child_tree[node].pb(conn[node][i]);
		}
}

void find_AP(int node)
{
	int l_lvl = max_n, ap = 0;
	for(int i = 0; i < child_tree[node].size(); i++)
	{
		find_AP(child_tree[node][i]);
		int curr_lvl = low_lvl[child_tree[node][i]];
		if(curr_lvl >= lvl_tree[node])
			ap = 1;
		l_lvl = min(l_lvl, curr_lvl);
	}
	int flag = 1;
	for(int i = 0; i < conn[node].size(); i++)
	{
		int c_lv = lvl_tree[conn[node][i]];
		if(conn[node][i] == par_tree[node] && flag)
		{
			//flag--;
			continue;
		}
		l_lvl = min(l_lvl, c_lv);
	}
	low_lvl[node] = l_lvl;
	if(ap && node != root)
		art_p.pb(node);
	if(node == root && child_tree[node].size() > 1)
		art_p.pb(node);
}

void find_bridge(int node)
{
	for(int i = 0; i < child_tree[node].size(); i++)
	{
		int c_ch = child_tree[node][i];
		find_bridge(c_ch);
		if(low_lvl[c_ch] > lvl_tree[node])
			bridge.pb(mp(node, c_ch));
	}
}

int main()
{
	int n;
	memset(visited, 0, sizeof(visited));
	while(cin >> n)
	{
		art_p.clear();
		a_p.clear();
		bridge.clear();
		curr_comp.clear();
		for(int i = 0; i < max_n; i++)
		{
			conn[i].clear();
			child_tree[i].clear();
			par_tree[i] = 0;
			lvl_tree[i] = 0;
			low_lvl[i] = 0;
			visited[i] = 0;
		}
		root = 0;
		for(int i = 0; i < n; i++)
		{
			int node;
			cin >> node;
			string s;
			cin >> s;
			s = s.substr(1, s.size() - 2);
			int n_nodes = 0;
			for(int j = 0; j < s.size(); j++)
			{
				n_nodes = n_nodes*10 + (s[j] - '0');
			}
			for(int n_nod = 0; n_nod < n_nodes; n_nod++)
			{
				int curr;	cin >> curr;
				conn[node].pb(curr);
			}
		}
		for(int d = 0; d < n; d++)
		{
			if(!visited[d])
			{
				dfs(d, d, 0);
				root = d;
				for(int i = 0; i < max_n; i++)
				{
					low_lvl[i] = max_n;
				}
				find_AP(root);
				/*pf("The Articulation Points in the graph are : \n");
				for(int i = 0; i < art_p.size(); i++)
				{
					a_p.insert(art_p[i]);
					pf("%d\n", art_p[i]);
				}*/
				find_bridge(root);
			}
		}
		for(int i = 0; i < bridge.size(); i++)
		{
			if(bridge[i].first > bridge[i].second)
				swap(bridge[i].first, bridge[i].second);
		}
		sort(bridge.begin(), bridge.end());
		pf("%lu critical links\n", bridge.size());
		for(int i = 0; i < bridge.size(); i++)
			pf("%d - %d\n", bridge[i].first, bridge[i].second);
		cout << endl;
	}
	return 0;
}
