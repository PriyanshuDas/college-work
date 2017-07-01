#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair <ll, pi2 >
#define pi4 pair<pi2, pi2>
#define loop(l,r) for(int i = l; i < r; i++)
#define ull unsigned long long int

using namespace std;
map <int, set <pair<int, int> > > L;
int n, m, k;
string M[51];
int visited[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool valid (int x, int y)
{
	if(x < n && x >= 0 && y < m && y >= 0)
		return true;
	return false;
}

int dfs(int x, int y)	//returns size of lake
{
	visited[x][y] = -1;
	int ret = 1, flag = 0;
	for(int i = 0; i < 4; i++)
	{
		int xx = x+dx[i], yy = y+dy[i];
		if(valid(xx, yy) && M[xx][yy] == '.' && visited[xx][yy] == 0)
		{
			int tmp = dfs(x+dx[i], y+dy[i]);
			if(tmp == -1)
			{
				flag = -1;
			}
			ret += tmp;
		}
	}
	visited[x][y] = 1;
	if(flag == -1)
		return -1;
	return ret;
}
//
void l_erase(int x, int y)
{
	visited[x][y] = -1;
	M[x][y] = '*';
	for(int i = 0; i < 4; i++)
	{
		if(M[x+dx[i]][y+dy[i]] == '.' && visited[x+dx[i]][y+dy[i]] == 0)
		{
			l_erase(x+dx[i], y+dy[i]);
		}
	}
	visited[x][y] = 1;
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> M[i];
	}
	int l_ct = 0;
	for(int i = 0; i < n; i++)
	{
		if(visited[i][0] == 0 && M[i][0] == '.')
			dfs(i, 0);
		if(visited[i][m-1] == 0 && M[i][m-1] == '.')
			dfs(i, m-1);
	}
	for(int j = 0; j < m; j++)
	{
		if(visited[0][j] == 0 && M[0][j] == '.')
			dfs(0, j);
		if(visited[n-1][j] == 0 && M[n-1][j] == '.')
			dfs(n-1, j);
	}
	for(int i = 1; i < n-1; i++)
	{
		for(int j = 1; j < m-1; j++)
		{
			if(visited[i][j] == 0 && M[i][j] == '.')
			{
				int ct = dfs(i, j);
				if(ct == -1)
					continue;
				L[ct].ins(mp(i, j));
				l_ct++;
				//cout << i << ' ' << j << '\t' << l_ct << ' ' << ct << endl;
			}
		}
	}
	int ans = 0;
	memset(visited, 0, sizeof(visited));
	while(l_ct > k)
	{
		int sz = (L.begin())->first;
		//cout << sz << endl;
		ans += sz;
		l_ct--;
		pair<int, int> c_pos = *(L.begin()->second).begin();
		int x = c_pos.first, y = c_pos.second;
		(L.begin()->second).erase(L.begin()->second.begin());
		if(L.begin()->second.size() == 0)
			L.erase(L.begin());
		l_erase(x, y);
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++)
	{
		cout << M[i] << endl;
	}
	return 0;
}
