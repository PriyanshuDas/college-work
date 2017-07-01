#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define loop(i, l, r) for(int i = l; i < r; i++)
#define max_n 100000

using namespace std;
set <int> conn[max_n+1];
int degree[max_n+1];
set<pair<int, int> > d_set;

int main()
{
	int n, m;	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int xi, yi;
		sf("%d%d", &xi, &yi);
		conn[xi].ins(yi);	conn[yi].ins(xi);
		degree[xi]++;		degree[yi]++;
	}
	for(int i = 1; i <= n; i++)
	{
		int d = degree[i];
		d_set.insert(mp(d, i));
	}
	int low_deg = (d_set.begin())->first;
	int node = (d_set.begin())->second;
	int ct = 0;
	while(low_deg < 2 && d_set.size() > 0)
	{
		d_set.erase(d_set.begin());
		//cout << "At node #" << node << endl;
		if(degree[node] == 0)
		{
			ct++;
		}
		else
		{
			degree[node]--;
			int n_node = *(conn[node].begin());
			int d = degree[n_node];
			auto it = d_set.find(mp(d, n_node));
			d_set.erase(it);
			d--;
			d_set.ins(mp(d, n_node) );
			degree[n_node]--;
			conn[n_node].erase(node);
		}
		low_deg = d_set.begin()->first;
		node = d_set.begin()->second;
	}
	cout << ct;
	return 0;
}
