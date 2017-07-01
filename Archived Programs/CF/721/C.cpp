#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert

using namespace std;

typedef struct node
{
	node *par;
	int pos;
} node;

int n, m, T;
vector <int> road[5001];
ll dist[5001][5001];
int main()
{
	cin >> n >> m >> T;
	for(int i = 0; i < m; i++)
	{
		int xi, yi, ti;	sf("%d%d%d", &xi, &yi, &ti);
		road[xi].pb(yi);
		dist[xi][yi] = ti;
	}
	queue<pair<int, node > > q;
	node tmp;
	tmp.par = NULL;
	tmp.pos = 1;
	q.push(mp(0, tmp));
	node ans;
	while(!q.empty())
	{
		node rt = q.front().second;
		int pos = rt.pos;
		int tim = q.front().first;
		//cout << pos << endl;
		q.pop();
		if(tim > T)
			continue;
		if(pos == n)
		{
			ans = rt;
			continue;
		}
		for(int i = 0; i < road[pos].size(); i++)
		{
			node *rt2 = new node;
			rt2->par = &rt;
			rt2->pos = road[pos][i];
			q.push(mp(tim+ dist[pos][road[pos][i]], *rt2));
		}
	}
	vector <int> A;
	while(ans.par != NULL)
	{
		cout << ans.pos << endl;
		A.pb(ans.pos);
		ans = *(ans.par);
	}
	A.pb(1);
	cout << A.size() << endl;
	for(int i = 0; i < A.size(); i++)
	{
		pf("%d ", A[i]);
	}
	return 0;
}
