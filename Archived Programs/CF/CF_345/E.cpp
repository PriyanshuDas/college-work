#include <bits/stdc++.h>

#define ll long long int
#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define loop(i, l, r) for(auto i = l; i != r; i++)
#define ins insert

using namespace std;

int n, m;
vector<vector <int> > orig;
vector<vector <int> > comp;
vector< pair<int, pair<int, int> > > sorted;

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		vector <int> t_vec;
		vector <int> z_vec;
		for(int j = 0; j < m; j++)
		{
			int tmp;	sf("%d", &tmp);
			t_vec.pb(tmp);
			z_vec.pb(0);
			sorted.pb(mp(tmp, mp(i, j) ) );
		}
		orig.pb(t_vec);
		comp.pb(z_vec);
	}
	sort(sorted.begin(), sorted.end());
	map<int, int> ct_mr, ct_mc;
	map<int, int> max_row, max_col;
	//int ct_mr[1000001] = {0}, ct_mc[1000001] = {0};
	for(int i = 0; i < sorted.size(); i++)
	{
		pair <int, int> p = sorted[i].second;
		int r = p.first, c = p.second;
		int val = sorted[i].first;
		int max_v = max(max_row[r], max_col[c]);
		max_row[r] = val;	max_col[c] = val;
		if(max_v == 0)
		{
			comp[r][c] = 1;
			ct_mr[r]= 1;	ct_mc[c] = 1;
		}
		else
		{
			int take_ct = 1;
			if(val == max_row[r])
				take_ct = max(take_ct, ct_mr[r]);
			else if( val > max_row[r])
				
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			pf("%d ", comp[i][j]);
		pf("\n");
	}
	return 0;
}
