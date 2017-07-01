#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

double memo[10][401][21];
int vis[10][401][21];
vector <int> spell[11];	//(X, Y, req)	(x times, y sided die)

vector <int> reduce(string s)
{
	int X = 0, Y = 0, req = 0;
	int i = 0;
	for(i;i < s.size() && s[i] != 'd'; i++)
	{
		X *= 10;
		X += (s[i]-'0');
	}
	i++;
	for(i; i < s.size() && s[i] != '-' && s[i] != '+'; i++)
	{
		Y *= 10;
		Y += (s[i]-'0');
	}
	int fl = +1;
	if(i < s.size()-1)
	{
		if(s[i] == '+')
			fl = -1;
		i++;
	}
	for(i; i < s.size(); i++)
	{
		req *= 10;
		req += (s[i]-'0');
	}
	req = req*fl;
	vector<int> v;
	v.pb(X);	v.pb(Y);	v.pb(req);
	return v;
}

double dp(int s, int c_val, int pos)
{
	if(pos == spell[s][0] && c_val >= spell[s][2])
		return 1;
	if(pos == spell[s][0])
		return 0;
	if(vis[s][c_val][pos] != -1)
		return memo[s][c_val][pos];

	double c_ans = 0;
	for(int i = 1; i <= spell[s][1]; i++)
	{
		c_ans += dp(s, c_val+i, pos+1);
	}
	c_ans = (c_ans)/(spell[s][1]);
	memo[s][c_val][pos] = c_ans;
	vis[s][c_val][pos] = 1;
	return c_ans;
}

int main()
{
	int T;	sf("%d", &T);
	for(int i = 0; i < 11; i++)
	{
		spell[i].pb(0);	spell[i].pb(0);
		spell[i].pb(0);
	}
	for(int t = 0; t < T; t++)
	{
		memset(vis, -1, sizeof(vis));
		int H, S;	sf("%d%d", &H, &S);
		double ans = 0;
		for(int i = 0; i <= S; i++)
			for(int j = 0; j < 401; j++)
				for(int k = 0; k < 21; k++)
					memo[i][j][k] = 0;

		for(int s = 0; s < S; s++)
		{
			string sp;
			cin >> sp;
			spell[s] = reduce(sp);
			spell[s][2] += H;
			//pf("Question = (%d, %d, %d)\n", spell[s][0],spell[s][1],spell[s][2]);
			double c_p = dp(s, 0, 0);
			if(c_p > ans)
				ans = c_p;
		}
		pf("Case #%d: %0.6lf\n", t+1, ans);
	}
}