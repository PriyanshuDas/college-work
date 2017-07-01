//KGP14G codechef.com/KGP14ROS

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define MAX_T 999999
#define MAX_E 6
#define MAX_A 12000
#define MAX_N 510

using namespace std;

int K, M;

vector<pair<pair<int, int>, pair<int, int> > > Node[501];

int dp[MAX_A+1][MAX_E+1][MAX_N+1];
ll f_ans = MAX_T;

int find(int a_t, int t_t, int en, int pos)
{
	if(pos == K)
	{
		return a_t;
	}
	if(a_t > MAX_A)
	{
		return MAX_T;
	}
	if(dp[a_t][en][pos] != -1)
		return dp[a_t][en][pos];
	//if(pos == 3)
		//pf("@(%d\t%d\t%d)\n", a_t, en, pos);
	
	//have to sort and take by end_time after a_t
	
	dp[a_t][en][pos] = MAX_T;
	for(int i = 0; i < Node[pos].size(); i++)	//ending time after a_t
	{
		int s = Node[pos][i].first.first, f = Node[pos][i].first.second;
		int v = Node[pos][i].second.first, t = Node[pos][i].second.second;
		
		int diff = a_t - f;
		if(diff > 0)
		{
			s += (diff/24)*24;
			f += (diff/24)*24;
			if(f <  a_t)
			{
				s += 24;
				f += 24;
			}
		}
		
		for(int st = max(s, a_t); st <= f; st++)
		{
			int c_en = en + (st - a_t);
			if(c_en > 6)
				c_en = 6;
			if(c_en >= t)
				dp[a_t][en][pos] = min(dp[a_t][en][pos], find(st+t, t_t+t,  c_en-t, v));
			if(c_en == 6)
				break;
		}
		
	}
	return dp[a_t][en][pos];
	
}

int main()
{
	int N;	sf("%d", &N);
	for(int n = 0; n < N; n++)
	{
		sf("%d%d", &K, &M);
		memset(dp, -1, sizeof(dp));
		f_ans = MAX_T;
		for(int i = 1; i <= K; i++)
		{
			Node[i].clear();
		}
		for(int m = 0; m < M; m++)
		{
			int u, v, s, f, t;
			sf("%d%d%d%d%d", &u, &v, &s, &f, &t);
			Node[u].pb(mp(mp(s, f), mp(v, t)));
		}
		f_ans = 999999999;
		int ans = find(0, 0, 6, 1);
		pf("Case %d: %d\n", n+1, ans);
	}
	return 0;
}
