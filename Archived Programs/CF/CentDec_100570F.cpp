//CodeForces GYM :- http://codeforces.com/gym/100570/problem/F

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define loop(i, l, r) for(lli = l; i < r; i++)
#define max_n 100001
#define max_lg 20
#define inf_val 9999999

using namespace std;

ll par[max_n+5], level[max_n+5];
ll D_root[max_n+5];
map<ll, ll > conn[max_n+5];	//conn[u] = (v, w) -> (u) --w--> (v) is an edge
ll siz[max_n+5];
ll n;
ll t_dist[max_lg+5][max_n+5];
ll DP[max_lg+5][max_n+5];

  //---------------------------------------------------------//
 //--------------_Pre_Process_------------------------------//
//dfs_pre(lln), finds and sets dist of each node from root in original graph and DP[1][n's child] (2^(i-1)th parent of j for DP[i][j])
//pre_process(), sets DP[logN][N]
//lca() finds lca for two nodes in log(N) time

void dfs_pre(ll n)	//modified
{
	//pf("(%d, %lld)\n", n, dist);
	for(auto it = conn[n].begin(); it != conn[n].end(); it++)
	{//, it->second);
		if(it->first != DP[1][n])
		{
			//pf("(%d)\n", it->first);
			DP[1][it->first] = n;
			D_root[it->first] = D_root[n] + it->second;
			level[it->first] = level[n]+1;
			dfs_pre(it->first);
		}
	}
}
//Modified
void pre_process()
{
	DP[1][1] = 1;
	D_root[1] = 0;
	level[1] = 0;
	dfs_pre(1);
	//cout << "BUBBA BAI\n";
	for(ll i = 2; i <= max_lg; i++)
		for(ll j = 1; j <= max_n; j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}

ll lca(ll a, ll b)		//a is lower level
{
	if(level[a] > level[b])	swap(a, b);
	ll diff = level[b] - level[a];
	for(ll i = 1; i <= max_lg; i++)
		if(diff&(1<<(i-1)))
			b = DP[i][b];
	if(a==b)
		return a;
	for(ll i = max_lg; i > 0; i--)
		if(DP[i][a] != DP[i][b])
		{
			a = DP[i][a];
			b = DP[i][b];
		}
	return DP[1][a];
}

 //Distance of Source from root + Distance of Destination from root
// - Distance of LCA(Source, Destination) from root
// Root is 1 (all nodes are 1-indexed

ll distance(ll u, ll v)
{
	ll ans = D_root[u] + D_root[v] - 2*D_root[lca(u, v)];
	return ans;
}

 //============================================================//
//-------------------------Decomposition----------------------//

ll no_nodes;

ll find_size(ll node, ll par)
{
	siz[node] = 1;
	no_nodes++;
	for(auto it = conn[node].begin(); it != conn[node].end(); it++)
		if(it->first != par)
			siz[node] += find_size(it->first, node);
	return siz[node];
}

ll find_centr(ll node, ll par)
{
	for(auto it = conn[node].begin(); it != conn[node].end(); it++)
		if(it->first != par && siz[it->first] > no_nodes/2)
			return find_centr(it->first, node);
	return node;
}

void decompose(ll node, ll p)
{
	//ll ans = 0;
	no_nodes = 0;
	find_size(node, node);
	ll centr = find_centr(node, node);
	//lvl[u] = depth;
	if(p == 0)
		par[centr] = centr;
	else
		par[centr] = p;
	for(auto it=conn[centr].begin(); it!=conn[centr].end(); it++)
	{
		conn[it->first].erase(centr);
		//par[it->first] = u;
		decompose(it->first, centr);
	}
	conn[centr].clear();
}

  //-------------------------------------------------------------//
 //---------------------- Question Specific --------------------//
 
vector<pair<ll, int> > dist[max_n+5];	// dist of every node to each parent and which child tree it comes from
map<ll, int> d_ct[max_n+5];	// ct of nodes with dist <= ll from i in ct[i]
map<ll, map<ll, int> > d_in_ct[max_n+5];	// ct of nodes with dist < ll from child x
											//	map<x, map<dist, count> > d_in_ct[n]
map<ll, int> Count;
map<ll, int> Count_in[max_n+5];
void set_dist()
{
	for(ll i = 1; i <= n; i++)
	{
		ll c = i;
		//dist[c].pb(0, -1);
		while(par[c] != c)
		{
			ll p = c;
			c = par[c];
			dist[c].pb(mp(distance(i, c),p));
		}
	}
	for(ll i = 1; i <= n; i++)
	{
		sort(dist[i].begin(), dist[i].end());
		ll ct = 0;
		for(ll j = 0; j < dist[i].size(); j++)
		{
			ct++;
			ll dst = dist[i][j].first;	//distance
			ll c = dist[i][j].second;	//which child it came from
			d_ct[i][dst] = ct;	//count of <= dst
			d_in_ct[i][c][dst] = ++Count_in[i][c];	//count of <= dst
		}
		Count[i] = ct;
	}
}

ll query(ll q_n, ll c_n, ll p_n, ll d_req)
{
	ll ans = 0;
	ll req = d_req - distance(q_n, c_n);
	int flag = 0;
	if(req >= 0)
		ans++;
	else
		flag = 1;
	//pf("(%d, %d, %d, %lld)\n", q_n, c_n, p_n, req);
	auto it = d_ct[c_n].upper_bound(req);
	
	ll val = 0;
	if(d_ct[c_n].size() == 0)
		val = 0;
	else if(it == d_ct[c_n].begin())
		val = 0;
	else if(it != d_ct[c_n].end())
	{
		it--;
		val = it->second;
	}
	else
		val = Count[c_n];
	
	ll val2 = 0;
	if(p_n != -1)
	{
		auto it2 = d_in_ct[c_n][p_n].upper_bound(req);
		if(d_in_ct[c_n][p_n].size() == 0)
		{
			val2 = 0;
		}
		else if(it2 == d_in_ct[c_n][p_n].begin())
		{
			val2 = 0;
		}
		else if(it2 != d_in_ct[c_n][p_n].end())
		{
			it2--;
			val2 = it2->second;
		}
		else
		{
			val2 = Count_in[c_n][p_n];
		}
	}
	//pf("+ %d - %d\n", val, val2);
	ans = ans + (val-val2);
	if(par[c_n] != c_n)
	{
		ans += query(q_n, par[c_n], c_n, d_req);
	}
	return ans;
}

//-----------------------------------------------------------//
int main()
{
	ll Q;
	sf("%lld%lld", &n, &Q);
	for(ll i = 0; i < n-1; i++)
	{
		ll u, v;
		ll w;
		sf("%lld%lld%lld", &u, &v, &w);
		conn[u][v] = w;
		conn[v][u] = w;
	}
	pre_process();
	decompose(1, 0);
	set_dist();
	for(ll q = 0; q < Q; q++)
	{
		ll u;	ll x;
		sf("%lld%lld", &u, &x);
		ll ans = query(u, u, -1, x);
		pf("%lld\n", ans);
	}
	return 0;
}
