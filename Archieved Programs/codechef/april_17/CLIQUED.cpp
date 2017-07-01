#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ins insert
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define n_max 100001
#define sz size
#define inf 9999999999999999

using namespace std;

/* Problem- Codechef April Long Challenge (CLIQUED)
{
	- N cities are given, connected by bi-directional roads
	- 1 to K is a complete graph, with each edge having wt X
	- M newer roads are there, each road of type
		(ai, bi, ci) - connecting ai to bi with wt ci
	- All roads are distinct, and no road connects a city to itself
	- Given a node S, find minimum distance from S to all nodes

	Algorithm-

	- Ignore the "old" edges
	- Do a dijkstra from S for the m edges
	- From 1-K select node with the least dist, let dist be d
	- Try D[1..K] = d + X, update if lower
	- ???
	- Profit!
}
*/

vector <pair<int, ll> > adj[n_max+1];
map <int, ll> dist;
set <pair<ll, int> > P_Q;
int N, K, M, S;
ll X;

void dijkstra()
{
	P_Q.ins(mp(0, S));
	dist[S] = 0;
	if(S <= K)
	{
		for(int i = 1; i <= K; i++)
		{
			dist[i] = min(X, dist[i]);
			P_Q.ins(mp(X, i));
		}
	}
	while(!P_Q.empty())
	{
		int n = P_Q.be->se;
		ll d = P_Q.be->fi;
		for(int i = 0; i < adj[n].sz(); i++)
		{
			int nxt = adj[n][i].fi;
			ll dst = adj[n][i].se;
			if(d+dst < dist[nxt])
			{
				P_Q.erase(mp(dist[nxt], nxt));
				P_Q.ins(mp(d+dst, nxt));
				dist[nxt] = d+dst;
			}
		}
		P_Q.erase(P_Q.be);
	}
	ll min_d = inf;
	for(int i = 1; i <= K; i++)
		min_d = min(min_d, dist[i]);
	for(int i = 1; i <= K; i++)
	{
		dist[i] = min(dist[i], min_d+X);
		P_Q.ins(mp(dist[i], i));
	}

	while(!P_Q.empty())
	{
		int n = P_Q.be->se;
		ll d = P_Q.be->fi;
		for(int i = 0; i < adj[n].sz(); i++)
		{
			int nxt = adj[n][i].fi;
			ll dst = adj[n][i].se;
			if(d+dst < dist[nxt])
			{
				P_Q.erase(mp(dist[nxt], nxt));
				P_Q.ins(mp(d+dst, nxt));
				dist[nxt] = d+dst;
			}
		}
		P_Q.erase(P_Q.be);
	}
}

int main()
{
	int T;	cin >> T;
	while(T--)
	{
		dist.clear();
		P_Q.clear();
		sf("%d%d%lld%d%d", &N, &K, &X, &M, &S);
		for(int i = 1; i <= N; i++)
			dist[i] = inf;
		for(int i = 0; i < M; i++)
		{
			int a, b;
			ll c;
			sf("%d%d%lld", &a, &b, &c);
			adj[a].pb(mp(b, c));
			adj[b].pb(mp(a, c));
		}
		dijkstra();
		for(int i = 1; i <= N; i++)
		{
			pf("%lld ", dist[i]);
			adj[i].clear();
		}
		pf("\n");
	}
	return 0;
}