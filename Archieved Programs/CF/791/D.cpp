//CodeForces GYM :- http://codeforces.com/gym/100570/problem/F

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define loop(i, l, r) for(lli = l; i < r; i++)
#define max_n 200001
#define max_lg 18
#define inf_val 9999999

using namespace std;

ll par[max_n+5], level[max_n+5];	//par in c_d, level in original
ll D_root[max_n+5];					//in original
map<ll, ll > conn[max_n+5];		//conn[u] = (v, w) -> (u) --w--> (v) is an edge
ll siz[max_n+5];
ll n;
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

ll decompose(ll node, ll p)
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

/* At every node, store :
 1) total jumps required to cover every node under this node, if at k steps covered to get here
 2) total jumps required to cover every node under a spec child of this node, if at k to get here
*/

ll dist_st[max_n+1];
map<ll, ll> child[max_n+1];
ll ct_n_st[max_n+1];
map<ll, ll> ct_n_c[max_n+1];

ll tot_jmps[6][max_n+1];
map<ll, ll> tot_jmp_c[6][max_n+1];
int k;
ll dist_ancest[max_lg][max_n+1];

ll calc(int s)
{
	int p = s;
	ll J = tot_jmps[0][s];
	//pf("\n@%d\t%lld\n", s, J);
	int c = 0;
	while(p != par[p])
	{
		ll dist_par = dist_ancest[c][s];	//reduce complexity
		c++;
		ll j1 = dist_par/k;
		ll md = (k-dist_par%k)%k;
		if(md > 0)
			j1++;
		ll j0 = j1;
		J += j1;
		ll j2 = tot_jmps[md][par[p]] - tot_jmp_c[md][par[p]][p];
		j1 = j1*(ct_n_st[par[p]]-ct_n_c[par[p]][p]);
		J += j1;
		J += j2;
		p = par[p];
		//pf("\t-\t%d\t%lld\t%lld\t%lld\t\n", p, j0, j1, j2);
	}
	return J;
}


int main()
{
	sf("%lld%d", &n, &k);
	for(ll i = 0; i < n-1; i++)
	{
		ll u, v;
		ll w;
		sf("%lld%lld", &u, &v);
		conn[u][v] = 1;
		conn[v][u] = 1;
	}
	pre_process();
	decompose(1, 0);	//1-index
	for(int i = 1; i <= n; i++)
		child[par[i]][i] = 0;

	for(int i = 1; i <= n; i++)
	{
		int c_p = i;
		//pf("@%d\tpar == %lld\n", i, par[i]);
		int c = 0;
		while(c_p != par[c_p])
		{
			dist_ancest[c][i] = distance(i, par[c_p]);
			c++;
			ll c_d = dist_ancest[c][i];
			child[par[c_p]][c_p] += c_d;
			ct_n_c[par[c_p]][c_p]++;
			dist_st[par[c_p]] += c_d;
			ct_n_st[par[c_p]]++;
			for(int j = 0; j < k; j++)
			{
				tot_jmp_c[j][par[c_p]][c_p] += (c_d-j)/k;
				tot_jmps[j][par[c_p]] += (c_d-j)/k;
				if((c_d-j)%k > 0)
				{
					tot_jmp_c[j][par[c_p]][c_p]++;
					tot_jmps[j][par[c_p]] ++;
				}
			}
			c_p = par[c_p];
		}
	}
	ll ans = 0;
	/*for(int i = 1; i <= n; i++)
	{
		pf("\n@%d\n", i);
		for(int j = 0; j < k; j++)
		{
			pf("\t[%d] == %lld\n", j, tot_jmps[j][i]);
		}
	}*/
	for(int i = 1; i <= n; i++)
		ans += calc(i);
	pf("%lld", ans/2);
	return 0;
}

/*

for a given edge, contribution : number of paths it is part of (F)

for a given edge e, find F(e)-> Number of paths that it belongs to

Ans = (Sum(F(e)) + Extra(for all paths))/k..


*/