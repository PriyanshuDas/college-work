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

int R, C, R_s, C_s, S;
double P, Q;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char mat[21][21];
int ct[21][21];
double max_ans = 0;

double pow(double x, int *n)
{
	double ans = 1;
	while(n > 0)
	{
		ans *= x;
		n--;
	}
	return ans;
}
double dfs(int x, int y, int left)
{
	if(left < 0)
	{
		double ans = 0;
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				if(mat[i][j] == 'A' && ct[i][j] > 0)
				{
					ans += (1 - pow(1-P, ct[i][j]));
				}
				else if(mat[i][j] == '.' && ct[i][j] > 0)
				{
					ans += (1 - pow(1-Q, ct[i][j]));
				}
			}
		}
		//cout << max_ans << endl;
		max_ans = max(ans, max_ans);
		return 0;
	}
	double best = 0;
	ct[x][y]++;
	for(int i = 0; i < 4; i++)
	{
		if(x+dx[i] >= 0 && x+dx[i] < R && y+dy[i] >= 0 && y+dy[i] < C)
		{
			best = max(best, dfs(x+dx[i], y+dy[i], left-1));
		}
	}
	ct[x][y]--;
	return best;
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t< T; t++)
	{
		cin >> R >> C >> R_s >> C_s >> S;
		memset(ct, 0, sizeof(ct));
		max_ans = 0;
		cin >> P >> Q;
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
				cin >> mat[i][j];
		}
		for(int i = 0; i < 4; i++)
		{
			if(R_s+dx[i] >= 0 && R_s+dx[i] < R && C_s+dy[i] >= 0 && C_s+dy[i] < C)
			{
				dfs(R_s+dx[i], C_s+dy[i], S-1);
			}
		}
		pf("Case #%d: %0.9lf\n", t+1, max_ans);
	}
	return 0;
}
