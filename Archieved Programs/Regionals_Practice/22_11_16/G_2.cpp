//KGP14G codechef.com/KGP14ROS

//Attempting to store values in array

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define MAX_T 999999999
#define MAX_E 6
#define MAX_A 50
#define MAX_N 510

using namespace std;

int K, M;

vector < vector <int> >Node[MAX_N+1];		//[u] <s, f, t, v>

ll visited[MAX_N+1][MAX_E+1];

multimap <ll, pair<int, int> > P_Q;
// (time, (node, energy) )
//Fresh Start, try dijkstra
// Gaze towards the sky, you'll know that is where your heart will feel at home

void init_vis(int N)
{
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= 6; j++)
			visited[i][j] = MAX_T;
}

int main()
{
	int N;	sf("%d", &N);
	for(int n = 0; n < N; n++)
	{
		int K, M;	sf("%d%d", &K, &M);
		for(int i = 1; i <= MAX_N; i++)
			Node[i].clear();
			
		for(int m = 0; m < M; m++)
		{
			int u, v, s, f, t;
			sf("%d%d%d%d%d", &u, &v, &s, &f, &t);
			vector<int> tmp;	tmp.pb(v);	tmp.pb(s);	tmp.pb(f);	tmp.pb(t);
			Node[u].pb(tmp);
		}
		P_Q.insert(mp(0, mp(1, 6)));
		
		init_vis(MAX_N);
		
		ll fn_ans = MAX_T;
		while(!P_Q.empty())
		{
			auto it = P_Q.begin();
			ll c_t = it->first;
			int u = it->second.first;
			int c_e = it->second.second;
			P_Q.erase(it);
			if(visited[u][c_e] < c_t)
				continue;
			//pf("@(%d\t%d\t%lld)\n", u, c_e, c_t);
			/*if(u == K)
			{
				fn_ans = min(fn_ans, c_t);			//This part is wrong. Why?
				break;								// Only explanation : Multimap is not sorting properly
			}*/
			//pf("Size : %lu\n", Node[u].size());
			for(int i = 0; i < Node[u].size(); i++)
			{
				//[u] <v, s, f, t>
				int v = Node[u][i][0];
				ll s = Node[u][i][1];
				ll f = Node[u][i][2];
				ll t = Node[u][i][3];
				if(f < s)
				{
					f += 24;
				}
				//pf("@(%d\t%d\t%d\t%d\t%d)\n", u, v, s, f, t);
				int diff = c_t - f;
				if(f < c_t)
				{
					s += (diff/24)*24;
					f += (diff/24)*24;
					if(f <  c_t)
					{
						s += 24;
						f += 24;
					}
				}
				//pf("@(%d\t%d\t%d\t%d\t%d)\n", u, v, s, f, t);
				for(ll st = max(s, c_t); st <= f; st++)
				{
					int c_en = c_e + (st - c_t);
					if(c_en > 6)
						c_en = 6;
					//pf("%d >= %d\t&&\t %d\n", c_en, t, visited[v][c_en]);
					if(c_en >= t && visited[v][c_en-t] > st+t)
					{
						visited[v][c_en-t] = st+t;
						if(v == K)
							fn_ans = min(fn_ans, st+t);
						//cout <<"Boo!\n";
						P_Q.insert(mp(st+t, mp(v, c_en - t)));
					}
					if(c_en >= 6)
						break;
				}
			}
		}
		//for(int i = 0; i <= 6; i++)						//This part is needed, why?
			//fn_ans = min(fn_ans, visited[K][i]);
		pf("Case %d: %lld\n", n+1, fn_ans);
	}
	return 0;
}
