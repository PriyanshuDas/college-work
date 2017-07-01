#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back
#define ins insert
#define loop(i,l,r) for(int i = l; i < r; i++)
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll>
#define pi4 pair<pi2, pi2>
#define fi first
#define se second

using namespace std;

int n, m, L, s, t;


//input-
ll dist[1001][1001];
int sp[1001][1001];
int visited[1001];
vector<int> v[100002];
vector<pair<int,int> > inp;

int main()
{
	cin >> n >> m >> L >> s >> t;
	 for(int i = 0; i < m; i++)
	 {
	 	int x, y;
	 	ll d;
		scanf("%d%d%lld",&x,&y,&d);
		v[x].pb(y);
		v[y].pb(x);
		inp.pb(mp(x,y));
		if(d == 0)
		{
		  	sp[x][y] = 1;
			sp[y][x] = 1;
			d++;
		}
		dist[x][y] = d;
		dist[y][x] = d;
	}


// info - pair<pair< dist, pair<x, y> (special) >, node >
	set<pair<pair<ll, vector < pair<int, int> > >, int> > p;
	vector<pair<int, int> > V;
	p.ins(mp(mp(0, V), s));
	int flag = 0;
	while(!p.empty() && flag == 0)
	{
		ll d  = (*p.begin()).fi.fi;
		vector < pair<int, int> > q = ((*p.begin()).first).second;
		int n = (*p.begin()).se;
		p.erase(p.begin());
		if(visited[n])
			continue;
		visited[n] = 1;
		if(d > L)
			break;
		if(n == t)
		{
			if(d == L)
			{
				for(int i = 0; i < q.size(); i++)
				{
					sp[q[i].fi][q[i].se] = 0;
					sp[q[i].se][q[i].fi] = 0;
				}
				flag = 1;
				break;
			}
			else if(d < L && q.size() > 0)
			{
				dist[q[0].fi][q[0].se] += (L-d);
				for(int i = 0; i < q.size(); i++)
				{
					sp[q[i].fi][q[i].se] = 0;
					sp[q[i].se][q[i].fi] = 0;
				}
				flag = 1;
				break;
			}
			else
				break;
		}
		for(int i = 0; i < v[n].size(); i++)
		{
			ll t_d = dist[n][v[n][i]];
			vector<pair<int, int> > new_q = q;
			if(sp[n][v[n][i]] == 1 && !visited[v[n][i]])
			{
				new_q.pb(mp(n, v[n][i]));
			}
			p.ins(mp(mp(d+t_d, new_q), v[n][i])); 
		}
	}
	if(flag == 0)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		for(int i = 0; i < inp.size(); i++)
		{
			if(sp[inp[i].fi][inp[i].se] == 1)
			{
				pf("%d %d 999999999999999999\n", inp[i].fi, inp[i].se);
			}
			else
			{
				pf("%d %d %lld\n", inp[i].fi, inp[i].se, dist[inp[i].fi][inp[i].se]);
			}
		}
	}
	return 0;
}
