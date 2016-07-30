  //============== Centroid Decomposition Question 2 ============//
 //=========== http://www.spoj.com/problems/QTREE5/ ============//
//=============== Coded By Priyanshu Das ======================//

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define loop(i, l, r) for(int i = l; i < r; i++)
#define max_n 100001
#define max_lg 20
#define inf_val 9999999

using namespace std;

int lvl[max_n+1], par[max_n+1];
set<int> conn[max_n+1];
int siz[max_n+1];
vector<int> Primes;
bool not_prime[max_n+2];
ll n, pairs;
int t_dist[max_lg][max_n+1];

 //---------------------- Pre Processing -------------------------

int visited[max_n+1];
ll d_root[max_n+1];
map<int, ll> distan[max_n+1];

void dist_dfs(int node, ll curr_d)
{
    visited[node] = 1;
    d_root[node] = curr_d;
    for(auto it = conn[node].begin(); it != conn[node].end(); it++)
    {
        if(!visited[*it])
            dist_dfs(*it, curr_d + distan[u].find(v)->second);
    }
}

void set_level(int n)
{
	DP[0][n] = n;
	dist_dfs(1, 0);
	loop(i,0,conn[n].size())
	{
		if(DP[1][conn[n][i]] == n)
			continue;
		lvl[conn[n][i]] = lvl[n] + 1;
		DP[1][conn[n][i]] = n;
	}
}

void pre_process()	// find 2^kth parent of all nodes for all possible int ks
{
	DP[1][1] = 0;
	lvl[1] = 0;
	set_level(1);
	loop(i, 2, max_lg+1)
		loop(j, 1, max_n+1)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}

int lca (int a, int b)			// Lowest Common Ancestor, lvl(a) < lvl(b)
{
	if(lvl[a] > lvl[b])
		swap(a, b);
	int diff = lvl[b] - lvl[a];
	for(int i = 1; i <= max_lg; i++)	//bringing b to same level as a
		if(diff&(1<<i-1))
			b = DP[i][b];
	if(a==b)
		return a;
	for(int i = max_lg; i >= 0; i--)	//If the 2^kth ancestor is same, then lca < 2^kth ancestor.
	{
		if(DP[i][a] != DP[i][b])
		{
			a = DP[i][a];
			b = DP[i][b];
		}
	}
	return DP[1][a];
}

int dist(int a, int b)
{
	return d_root[a] + d_root[b] - 2*d_root[lca(a,b)];
}


 //============================================================//
//-------------------------Decomposition----------------------//

int no_nodes;

int find_size(int node, int par)
{
	siz[node] = 1;
	no_nodes++;
	for(auto it = conn[node].begin(); it != conn[node].end(); it++)
		if(*it != par)
			siz[node] += find_size(*it, node);
	return siz[node];
}

int find_centr(int node, int par)
{
	for(auto it = conn[node].begin(); it != conn[node].end(); it++)
		if(*it != par && siz[*it] > no_nodes/2)
			return find_centr(*it, node);
	return node;
}

void decompose(int node, int depth)
{
	ll ans = 0;
	no_nodes = 0;
	find_size(node, node);
	int centr = find_centr(node, node);
	int u = centr;
	par[u] = node;
	lvl[u] = depth;
	for(auto it=conn[u].begin(); it!=conn[u].end(); it++)
	{
		conn[*it].erase(u);
		decompose(*it, depth+1);
	}
	conn[u].clear();
}

int main()
{
 //--------------------------------------------------------------//
//----------------------- Input --------------------------------//
    int T;  cin >> T;
    for(int t = 0; t < T; t++)
    {
        sf("%lld", &n);
        loop(i, 0, n-1)
        {
            int a, b, w;
            sf("%d%d%d", &a, &b, &w);
            conn[a].insert(b);
            conn[b].insert(a);
            distan[a][b] = w;
            distan[b][a] = w;
        }
        pre_process();
        decompose(1, 0);
    }
	return 0;
}
