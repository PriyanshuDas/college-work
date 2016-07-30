//---------------------------- Centroid Decomposition -----------------------------//
 //---------------- https://www.hackerrank.com/challenges/bst-maintenance ----------//
//----------------------------------- Priyanshu Das -------------------------------//


#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define ins insert
#define pii pair <ll, ll>
#define loop(i, l, r) for(ll i = l; i < r; i++)
#define n_max 300001
#define max_lg 20

using namespace std;
int root = 1;
int par[n_max+1];
int sz[n_max+1];
int centr[n_max+1];
int level[n_max+1];
int DP[max_lg][n_max];
vector<int> conn[n_max+1];
int n, q;

//---------PreProcess

void dfs_p(ll node)
{

	for(int i = 0; i < conn[node].size(); i++)
	{
	    int c = conn[node][i];
		if(c == DP[0][node])
			continue;
		DP[0][c] = node;
		level[c] = level[node]+1;
		dfs_p(c);
	}
}

void pre_process()
{
	level[1] = 0;
	DP[0][1] = 1;
	dfs_p(1);
	for(ll i = 1 ;i < max_lg ;i++)
		for(ll j=1;j<=n;j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}

ll lca (ll a, ll b)
{
	if(level[a] > level[b])	swap(a, b);		// level[a] <= level[b]
	ll diff = level[b] - level[a];
	for(ll i = 0; i < max_lg; i++)
		if(diff&(1<<i))
			b = DP[i][b];
	if(a == b)
		return a;
	for(ll i = max_lg-1; i >= 0; i--)
	{
		if(DP[i][a] != DP[i][b])
			a = DP[i][a];
			b = DP[i][b];
	}
	return DP[0][a];
}

//---------DEBUG

void disp_sz()
{
    for(int i = 1; i <= n; i++)
        cout << sz[i] << ' ';
}

void dfs_sz(int node)
{
    //printf("@%d\n", node);
    int ans = 1;
    for(int i = 0; i < conn[node].size(); i++)
    {
        dfs_sz(conn[node][i]);
        ans += sz[conn[node][i]];
    }
    sz[node] = ans;
}

void dfs_centr(int node)
{
    int c_sz = sz[node];
    int c_n = centr[node];
    if(lca(centr[par[node]], c_n) == c_n)
        c_n = centr[par[node]];
    int centroid = c_n;
    vector<int> path;
    while(1)
    {
        int m_sz = 0;
        int n_node = 1;
        for(int i = 0; i < conn[c_n].size(); i++)
        {
            if(sz[conn[c_n][i]] > m_sz)
            {
                n_node = conn[c_n][i];
                m_sz = sz[conn[c_n][i]];
            }
        }
        if(m_sz*2 <= c_sz && 2*(c_sz - sz[c_n]) <= c_sz)
        {
            centroid = c_n;
            break;
        }
        c_n = n_node;
    }
    centr[node] = centroid;
    for(int i = 0; i < conn[node].size(); i++)
    {
        dfs_centr(conn[node][i]);
    }
}

int main()
{
    cin >> n >> q;
    for(int i = 2; i <= n; i++)
    {
        int tmp;    sf("%d", &tmp);
        par[i] = tmp;
        conn[par[i]].pb(i);
        centr[i] = i;
    }
    par[1] = 1;
    dfs_sz(root);
    pre_process();
    //disp_sz();
    dfs_centr(root);
    for(int i = 0; i < q; i++)
    {
        int x;  sf("%d", &x);
        printf("%d\n", centr[x]);
    }
	return 0;
}
