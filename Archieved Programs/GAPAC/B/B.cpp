#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2,pi2>

using namespace std;
int mat[3001][3001];
set<int> col[3001], row[3001];
int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		for(int i = 0; i < 3001; i++)
		{
			col[i].clear();
			row[i].clear();
		}
		memset(mat, 0, sizeof(mat));
		int R, C, K;	cin >> R>> C >> K;
		for(int i = 0; i < K; i++)
		{
			int x, y;	sf("%d%d", &x, &y);
			mat[x][y] = 1;
			row[x].ins(y);
			col[y].ins(x);
		}
		ll ct = 0;
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				int s = 0;
				for(int k = 0; k < R-i && k < C-j; k++)
				{
					s++;
					set<int>::iterator r_it = row[i+k].lower_bound(j);
					set<int>::iterator c_it = col[j+k].lower_bound(i);
					if((r_it == row[i+k].end() || *r_it > j+k) && (c_it == col[j+k].end() || *c_it > i+k))
					{
						continue;
					}
					else
					{
						s--;
						break;
					}
				}
				ct += s;
			}
		}
		pf("Case #%d: %lld\n", t, ct);
	}
	return 0;
}
