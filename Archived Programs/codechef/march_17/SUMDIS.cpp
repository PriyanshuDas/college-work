#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define fi first
#define se second
#define n_max 100001

using namespace std;

int T, N;
ll inf = 900000000000001;
vector <ll> a[3];

ll total[n_max+1];
pair<ll, int> dist[n_max+5][3];

/* 	dist[p[0]][0] stores dist to node closest to 0
		dist[p[0]][1] stores dist to node closest to 1, if we stop at 0
		dist[p[0]][1] stores dist to node closest to 2, if we stop at 0
	dist[p[1]][1] stores dist to node closest to 1
	dist[p[2]][2] stores dist to node closest to 2
	
	c_dist[0] stores min dist to nodes under 0 if we stop at pos
	c_dist[1] stores min_dist to nodes under 1, if we stop at pos
	c_dist[1] stores min_dist to nodes under 1, if we stop at pos
*/

void solve(int pos)
{
	int p[3] = {pos+1, pos+2, pos+3};
	for(int i = 0; i < 3; i++)
	{
		pair<ll, int> c_min = mp(inf, 0);
		for(int j = 0; j < 3; j++)
		{
			int nodes = dist[p[j]][i].se;
			ll d = dist[p[j]][i].fi;
			d = a[j][pos]*(nodes) + d;
			if(c_min.fi > d)
				c_min = mp(d, nodes);
		}
		dist[pos][i] = c_min;
	}
	pair<ll, int> new_list[3][3] = {mp(0, 0)};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			new_list[i][j] = mp(0, 0);
		}
	}
	int new_3 = 0;
	ll m_d = (inf);
	for(int i = pos; i < pos+3; i++)
	{
		if(a[pos+2 - i][i] < m_d)
		{
			m_d = a[pos+2-i][i];
			new_3 = i-pos;
		}
	}
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			new_list[i][j+1].fi += dist[i][j].fi;
			new_list[i][j+1].se += dist[i][j].se;
		}
	}

	// adding the now gone node
	pf("Adding new node!\t%lld\n", m_d);
	for(int i = pos; i < pos+3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			ll c_d = a[pos+2-i][i];
			if(c_d == m_d)
			{
				new_list[i-pos][j].fi += (c_d*((ll)dist[pos+3][2].se+1) + dist[pos+3][2].fi);
				new_list[i-pos][j].se += dist[pos+3][2].se + 1;
			}
		}
	}
	
	pf("@%d:\n", pos);

	for(int i = 0; i < 3; i++)
	{
		pf("\t%d\t:\t",i);
		for(int j = 0; j < 3; j++)
		{
			pf("(%lld, %d)\t", new_list[i][j].fi, new_list[i][j].se);
		}
		pf("\n");
	}
	pf("\n");
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			dist[pos+i][j] = new_list[i][j];
	}
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> N;
		a[0].pb(0);
		a[1].pb(0);
		a[2].pb(0);
		a[0].pb(0);
		a[1].pb(0);
		a[2].pb(0);
		a[0].pb(0);
		a[1].pb(0);
		a[2].pb(0);
		for(int i = 0; i < N-1; i++)
		{
			int ai;	sf("%d", &ai);
			a[0].pb(ai);
		}
		for(int i = 0; i < N-2; i++)
		{
			int bi;	sf("%d", &bi);
			a[1].pb(bi);
		}
		for(int i = 0; i < N-3; i++)
		{
			int ci;	sf("%d", &ci);
			a[2].pb(ci);
		}
		N += 3;
		for(int i = N-3; i >= 0; i--)
		{
			a[1][i] = min(a[1][i], a[0][i]+a[0][i+1]);
			if(i < N-3)
				a[2][i] = min(a[2][i], min(a[0][i] + a[1][i+1], a[0][i+2] + a[1][i]));
		}
		dist[N-1][0] = mp(0, 0);
		dist[N-1][1] = mp(0, 0);
		dist[N-1][2] = mp(0, 0);
		dist[N-2][0] = mp(0, 0);
		dist[N-2][1] = mp(0, 0);
		dist[N-2][2] = mp(0, 0);
		dist[N-3][0] = mp(0, 0);
		dist[N-3][1] = mp(0, 0);
		dist[N-3][2] = mp(0, 0);
		for(int i = N-1; i >= 0; i--)
			pf("%d\t%lld %lld %lld\n", i, a[0][i], a[1][i], a[2][i]);
		for(int i = N-4; i >= 0; i--)
		{
			solve(i);
		}
		ll ans = 0;
		for(int i = 3; i < N; i++)
		{
			pair <ll, int> cur = mp(dist[i][0].fi + dist[i][1].fi + dist[i][2].fi, dist[i][0].se + dist[i][1].se + dist[i][2].se);
			//pf("@%d\t(%lld, %d)\n", i, cur.fi, cur.se);
			ans += (dist[i][0].fi + dist[i][1].fi + dist[i][2].fi);
		}
		pf("%lld\n", ans);
	}
	return 0;
}