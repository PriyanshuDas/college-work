//================================= CodeForces 659F ====================================//
//================================= Union and Find ====================================//

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define sp(z, x) z[x.first][x.second]
#define fir first
#define sec second
#define max_n 1001

using namespace std;

int n, m;
ll arr[max_n+1][max_n+1], size[max_n+1][max_n+1], ans[max_n+1][max_n+1];
int visited[max_n+1][max_n+1];
vector<pair<int, int> > adj_l[max_n+1][max_n+1];
vector<pair<ll, pair<int, int> > > hay_s;
pair <int, int> parent[max_n+1][max_n+1];
set <pair<int, int> > curr_set;
ll k;

ll max_s;
pair<int, int> max_s_p;

pair<int, int> Find(pair<int, int> node)
{
	if (parent[node.fir][node.sec] == node)
		return node;
	parent[node.fir][node.sec] = Find(parent[node.fir][node.sec]);
	return parent[node.fir][node.sec];
}

int required = 0;
ll max_val = 0;

void DFS(pair<int, int> node)
{
	required--;
	int x = node.fir, y = node.sec;
	ans[x][y] = max_val;
	visited[x][y] = 1;
	if(required <= 0)
		return;
		
	for(int i = 0; i < adj_l[x][y].size() && required > 0; i++)
	{
		int xi = adj_l[x][y][i].fir, yi = adj_l[x][y][i].sec;
		if(arr[xi][yi] >= max_val && visited[xi][yi] == 0)
		{
			DFS(mp(xi, yi));
		}
	}
	return;
}

void Union(set< pair<int, int> > *S)
{
	//cout << "Union Call!\n";
//--------------------       Union of Set S			----------------------------------//
	for(auto it = S->begin(); it != S->end(); it++)
	{
		pair <int, int> curr = *it;
		int x = curr.first, y = curr.second;
		for(int i = 0; i < adj_l[x][y].size(); i++)
		{
			pair<int, int> a_c = adj_l[x][y][i];
			int xi = a_c.first, yi = a_c.second;
			if(arr[xi][yi] >= arr[x][y])
			{
				pair<int, int> par_x = Find(curr);
				pair<int, int> par_y = Find(a_c);
				if(par_x == par_y)
					continue;
				auto s_p_x = &(size[par_x.fir][par_x.sec]);
				auto s_p_y = &(size[par_y.fir][par_y.sec]);
				if(*s_p_x >= *s_p_y)
				{
					*s_p_x += *s_p_y;
					parent[par_y.fir][par_y.sec] = par_x;
					parent[xi][yi] = par_x;
					curr_set.erase(par_y);
				}
				else if(*s_p_x < *s_p_y)
				{
					*s_p_y += *s_p_x;
					parent[par_x.fir][par_x.sec] = par_y;
					parent[x][y] = par_y;
					curr_set.erase(par_x);
				}
				if(*s_p_x >= *s_p_y && *s_p_x > max_s)
				{
					max_s = *s_p_x;
					max_s_p = par_x;
				}
				else if(*s_p_y >= *s_p_x && *s_p_y > max_s)
				{
					max_s = *s_p_y;
					max_s_p = par_y;
				}
			}
		}
	}
//----------------------------------------------------------------------------------//
//-------------			Union of Set S with curr_set		-----------------------//

}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			sf("%lld", &arr[i][j]);
			hay_s.pb(mp(arr[i][j], mp(i, j)));
			parent[i][j] = mp(i, j);
			size[i][j] = 1;
		}
	}
			
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i > 0)
				adj_l[i][j].pb(mp(i-1,j));
			if(j > 0)
				adj_l[i][j].pb(mp(i, j-1));
			if(i < n-1)
				adj_l[i][j].pb(mp(i+1,j));
			if(j < m-1)
				adj_l[i][j].pb(mp(i,j+1));
		}
	}
	sort(hay_s.rbegin(), hay_s.rend());
	
	for(int pos = 0; pos < hay_s.size(); pos++)
	{
		int curr_v = hay_s[pos].first;
		if(curr_v == 0)
		{
			cout << "no";
			return 0;
		}
		set <pair<int, int> > new_set;
		int i = pos;
		for(i; i < hay_s.size() && hay_s[i].first == curr_v; i++)
		{
			new_set.insert(hay_s[i].second);
			curr_set.insert(hay_s[i].second);
		}
		pos = i-1;
		max_s = 0;
		Union(&new_set);
		if(k%curr_v != 0)
			continue;
		else if( k/curr_v <= max_s)
		{
			max_val = curr_v;
			required = k/curr_v;
			memset(ans, 0, sizeof(ans));
			DFS(max_s_p);
			cout << "YES\n";
			//pf("max_s == %d\tcurr == %d\trequired == %d\n", max_s, curr_v, required);
			for(int ii = 0; ii < n; ii++)
			{
				for(int jj = 0; jj < m; jj++)
				{
					pf("%d ", ans[ii][jj]);
				}
				pf("\n");
			}
			return 0;
		}
	}
	/*for(auto it = curr_set.begin(); it != curr_set.end(); it++)
	{
		pf("======== Root is (%d, %d) ===========\n", it->fir, it->sec);
		pf("Size of tree is == %d\n", size[it->fir][it->sec]);
	}*/
	cout << "NO\n";
	return 0;
}
