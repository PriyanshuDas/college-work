/*

Need 2 segment trees : 	1 for priority queue
						2 for adjacent edges

	1 has :- 	[l,r]
				unvisited node in [l,r] with lowest wt
				lazy_min = init(0), lowest value needed to get to this range
				lazy_flag = init(0)
				lp
				rp

	2 has :-	[l,r]
				(d,w)-> all nodes under this can go to d with wt w
				lazy<pair<int, int> > lazy_set
				lazy_flag = init(0)
				lp
				rp

*/
#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define fi first
#define se second
#define be begin()
#define ull unsigned ll
#define pi2 pair<int, int>
#define n_max 100001
#define MOD 1000000007
#define inf 100000000007

using namespace std;

typedef struct node
{
	int l, r;
	node *lp, *rp;
	vector <pair <int, ll> > adj;	// nodes adj to this range
	vector <pair <int, ll> > lazy_adj;	// nodes adj to this range, not updated in children
	int lazy;
	ll lazy_min;		// minimum dist to get to this range, un-updated
	ll min_d;			// minimum dist to get to this range total
	int low_wt_node;	// unvisited node which takes min time in this range
	ll node_md;
} node;

void init_node(node *n)
{
	n->l = 0,		n->r = 0;
	n->lp = NULL,	n->rp = NULL;
	n->adj.clear();
	n->lazy_adj.clear();
	n->lazy = 0;
	n->lazy_min = inf;
	n->min_d = inf;
	n->low_wt_node = -1;
	n->node_md = inf;
}

void erase_node(node *n)
{
	if(n->lp != NULL)	erase_node(n->lp);
	if(n->rp != NULL)	erase_node(n->rp);
	delete n;
}
void create_node(node *n, int l, int r)
{
	n->l = l;	n->r = r;
	if(l == r)
	{
		return;
	}
	if(n->lp == NULL)
	{
		n->lp = new node;
		init_node(n->lp);
	}
	if(n->rp == NULL)
	{
		n->rp = new node;
		init_node(n->rp);
	}
	int mid = (l+r)/2;
	create_node(n->lp, l, mid);
	create_node(n->rp, mid+1, r);
}
ull point_update(node *n, int typ, int src, int dest, ull wt)
{
	if(typ == 1)		// ie adj
	{
		if(n->lazy)
		{
			if(n->lp != NULL)
			{
				n->lp->lazy = 1;
				for(int i = 0; i < n->lazy_adj.size(); i++)
					n->lp->lazy_adj.pb(n->lazy_adj[i]);
			}
			if(n->rp != NULL)
			{
				n->rp->lazy = 1;
				for(int i = 0; i < n->lazy_adj.size(); i++)
					n->rp->lazy_adj.pb(n->lazy_adj[i]);
			}
			for(int i = 0; i < n->lazy_adj.size(); i++)
				n->adj.pb(n->lazy_adj[i]);
			n->lazy = 0;
			n->lazy_adj.clear();
		}
		//pf("Update node @(%d, %d) for %d to %d with %lld\n", n->l, n->r, src, dest, wt);
		if(src == n->l && n->l == n->r)
			n->adj.pb(mp(dest, wt));
		else if(n->lp != NULL && n->lp->l <= src && n->lp->r >= src)
			point_update(n->lp, typ, src, dest, wt);
		else if(n->rp != NULL)
			point_update(n->rp, typ, src, dest, wt);

	}
	/*	Actual Query		*/
}

void range_update_adj(node *n, int l, int r, int dst, ll w)
{
	if(n->lazy)
	{
		if(n->lp != NULL)
		{
			n->lp->lazy = 1;
			for(int i = 0; i < n->lazy_adj.size(); i++)
				n->lp->lazy_adj.pb(n->lazy_adj[i]);
		}
		if(n->rp != NULL)
		{
			n->rp->lazy = 1;
			for(int i = 0; i < n->lazy_adj.size(); i++)
				n->rp->lazy_adj.pb(n->lazy_adj[i]);
		}
		n->lazy = 0;
		for(int i = 0; i < n->lazy_adj.size(); i++)
			n->adj.pb(n->lazy_adj[i]);
		n->lazy_adj.clear();
	}
	if(r < n->l || l > n->r)
		return;

	if(l == n->l && r == n->r)
	{
		n->lazy_adj.pb(mp(dst, w));
		n->lazy = 1;
		return;
	}
	//pf("Update range @(%d, %d) for (%d, %d) to %d with %lld\n", n->l, n->r, l, r, dst, w);
	range_update_adj(n->lp, max(l, n->lp->l), min(r, n->lp->r), dst, w);
	range_update_adj(n->rp, max(l, n->rp->l), min(r, n->rp->r), dst, w);
}
vector<pair<int, ll> > point_query_adj(node *n, int src)
{
	if(n->lazy)
	{
		if(n->lp != NULL)
		{
			n->lp->lazy = 1;
			for(int i = 0; i < n->lazy_adj.size(); i++)
				n->lp->lazy_adj.pb(n->lazy_adj[i]);
		}
		if(n->rp != NULL)
		{
			n->rp->lazy = 1;
			for(int i = 0; i < n->lazy_adj.size(); i++)
				n->rp->lazy_adj.pb(n->lazy_adj[i]);
		}
		for(int i = 0; i < n->lazy_adj.size(); i++)
			n->adj.pb(n->lazy_adj[i]);
		n->lazy = 0;
		n->lazy_adj.clear();
	}
	//pf("Update node @(%d, %d) for %d to %d with %lld\n", n->l, n->r, src, dest, wt);
	if(src == n->l && n->l == n->r)
		return n->adj;
	else if(n->lp != NULL && n->lp->l <= src && n->lp->r >= src)
		return point_query_adj(n->lp, src);
	else if(n->rp != NULL)
		return point_query_adj(n->rp, src);
	/*	Actual Query		*/
}

/* Priority Queue

	int l, r;
	node *lp, *rp;
	int lazy;
	ll lazy_min;		// minimum dist to get to this range, un-updated
	ll min_d;			// minimum dist to get to this range total
	int low_wt_node;	// unvisited node which takes min time in this range
	ll node_md;
} node;*/
pair<int, ll> point_update_pq(node *n, int src, ull wt)
{
	if(n->node_md > n->min_d)
		n->node_md = n->min_d;
	if(n->lazy)
	{
		if(n->lp != NULL)
		{
			if(n->lp->lazy_min > n->lazy_min)
			{
				n->lp->lazy = 1;
				n->lp->lazy_min = n->lazy_min;
			}
		}
		if(n->rp != NULL)
		{
			if(n->rp->lazy_min > n->lazy_min)
			{
				n->rp->lazy = 1;
				n->rp->lazy_min = n->lazy_min;
			}
		}
		n->min_d = min(n->min_d, n->lazy_min);
		if(n->node_md > n->min_d)
			n->node_md = n->min_d;
		n->lazy = 0;
		n->lazy_min = inf;
	}
	//pf("Update node @(%d, %d) for %d to %d with %lld\n", n->l, n->r, src, dest, wt);
	if(src == n->l && n->l == n->r)
	{
		if(n->node_md > wt)
			n->node_md = wt;
		n->min_d = n->node_md;
		n->low_wt_node = src;
		return mp(src, n->node_md);
	}
	else if(n->lp != NULL && n->lp->l <= src && n->lp->r >= src)
	{
		pair<int, ll> ans = point_update_pq(n->lp, src, wt);
		if(ans.se < n->node_md)
		{
			n->node_md = ans.se;
			n->low_wt_node = ans.fi;
		}
		return mp(n->low_wt_node, n->node_md);
	}
	else if(n->rp != NULL)
	{
		pair<int, ll> ans = point_update_pq(n->rp, src, wt);
		if(ans.se < n->node_md)
		{
			n->node_md = ans.se;
			n->low_wt_node = ans.fi;
		}
		return mp(n->low_wt_node, n->node_md);
	}
}

pair<int, ll> range_update_pq(node *n, int l, int r, ll w)
{
	if(n->node_md > n->min_d)
		n->node_md = n->min_d;
	if(n->lazy)
	{
		if(n->lp != NULL)
		{
			if(n->lp->lazy_min > n->lazy_min)
			{
				n->lp->lazy = 1;
				n->lp->lazy_min = n->lazy_min;
			}
		}
		if(n->rp != NULL)
		{
			if(n->rp->lazy_min > n->lazy_min)
			{
				n->rp->lazy = 1;
				n->rp->lazy_min = n->lazy_min;
			}
		}
		n->min_d = min(n->min_d, n->lazy_min);
		if(n->node_md > n->min_d)
			n->node_md = n->min_d;
		n->lazy = 0;
		n->lazy_min = inf;
	}
	if(r < n->l || l > n->r)
		return mp (-1, inf);

	if(l == n->l && r == n->r)
	{
		n->lazy = 1;
		n->lazy_min = min(n->lazy_min, w);
		n->node_md = min(n->node_md, n->lazy_min);
		return(mp(n->low_wt_node, n->node_md));
	}
	//pf("Update range @(%d, %d) for (%d, %d) to %d with %lld\n", n->l, n->r, l, r, dst, w);
	
	pair<int, ll> ans1 = range_update_pq(n->lp, max(l, n->lp->l), min(r, n->lp->r), w);
	pair<int, ll> ans2 = range_update_pq(n->rp, max(l, n->rp->l), min(r, n->rp->r), w);
	if(ans1.se < n->node_md)
	{
		n->node_md = ans1.se;
		n->low_wt_node = ans1.fi;
	}
	if(ans2.se < n->node_md)
	{
		n->node_md = ans2.se;
		n->low_wt_node = ans2.fi;
	}
	return mp(n->low_wt_node, n->node_md);
}
pair<int, ll> point_query_pq(node *n, int src)
{
	if(n->node_md > n->min_d)
		n->node_md = n->min_d;
	if(n->lazy)
	{
		if(n->lp != NULL)
		{
			if(n->lp->lazy_min > n->lazy_min)
			{
				n->lp->lazy = 1;
				n->lp->lazy_min = n->lazy_min;
			}
		}
		if(n->rp != NULL)
		{
			if(n->rp->lazy_min > n->lazy_min)
			{
				n->rp->lazy = 1;
				n->rp->lazy_min = n->lazy_min;
			}
		}
		n->min_d = min(n->min_d, n->lazy_min);
		if(n->node_md > n->min_d)
			n->node_md = n->min_d;
		n->lazy = 0;
		n->lazy_min = inf;
	}
	if(src == n->l && n->l == n->r)
		return mp(n->low_wt_node, n->node_md);
	else if(n->lp != NULL && n->lp->l <= src && n->lp->r >= src)
		return point_query_pq(n->lp, src);
	else if(n->rp != NULL)
		return point_query_pq(n->rp, src);
	/*	Actual Query		*/
}


node *root_adj, *root_pq;

vector <pair<pair<int, int>, ll> > Adj[n_max+1];

ll Ans[n_max+1];
int visited[n_max+1];

void dijkstra(int node)
{
	point_update_pq(root_pq, node, inf);
	vector <pair<int, ll> > adj = point_query_adj(root_adj, node);
	for(int i = 0; i < adj.size(); i++)
	{
		pair<int, ll> D = point_query_pq(root_pq, adj[i].fi);
		ll d = D.se;
		if(d < Ans[node] + adj[i].se)
			point_update_pq(root_pq, adj[i].fi, Ans[node] + adj[i].se);
	}
	for(int i = 0; i < Adj[node].size(); i++)
	{
		int l = Adj[node][i].fi.fi, r = Adj[node][i].fi.se;
		ll w = Adj[node][i].se;
		range_update_pq(root_pq, l, r, w);
	}
	Ans[root_pq->low_wt_node] = point_query_pq(root_pq, root_pq->low_wt_node).se;
	dijkstra(root_pq->low_wt_node);
}

int main()
{
	int n, q, s;
	sf("%d%d%d", &n, &q, &s);
	root_adj = new node;
	root_pq = new node;
	create_node(root_adj, 1, n);
	create_node(root_pq, 1, n);
	for(int i = 1; i <= n; i++)
		Ans[i] = inf;
	for(int Q = 0; Q < q; Q++)
	{
		int typ;	sf("%d", &typ);
		if(typ == 1)
		{
			int u, v, w;
			sf("%d%d%d", &u, &v, &w);
			point_update(root_adj, 1, u, v, w);
		}
		else if(typ == 2)
		{
			int v, l, r, w;
			sf("%d%d%d%d", &v, &l, &r, &w);
			Adj[v].pb(mp(mp(l, r), w));
		}
		else
		{
			int v, l, r, w;
			sf("%d%d%d%d", &v, &l, &r, &w);
			range_update_adj(root_adj, l, r, v, w);
		}
	}
	Ans[s] = 0;
	dijkstra(s);
	for(int i = 1; i <= n; i++)
	{
		pf("%lld ", Ans[i]);
	}
	pf("\n");
	return 0;
}