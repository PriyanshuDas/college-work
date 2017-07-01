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

vector <int> edge[10001];
int e_c[10001];
map <string, int> M;
vector <string> inp;
int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		for(int i = 0; i < 10001; i++)
		{
			edge[i].clear();
		}
		memset(e_c, 0, sizeof(e_c));
		M.clear();
		inp.clear();
		int N;	cin >> N;
		int ct = 1;
		for(int i = 0; i < N; i++)
		{
			string s;	cin >> s;
			string l;
			vector <string> r;
			int lpos = 0;
			for(int j = 0; j < s.size(); j++)
			{
				if(s[j] == '=')
				{
					l = s.substr(0, j);
				}
				if(s[j] == '(')
					lpos = j+1;
				if(s[j] == ',')
				{
					string tmp = s.substr(lpos, j-lpos);
					r.pb(tmp);
					lpos = j+1;
				}
				if(s[j] == ')')
				{
					string tmp = s.substr(lpos, j-lpos);
					if(tmp.size() > 0)
						r.pb(tmp);
					lpos = j+1;
				}
			}
			//cout << l <<endl;
			if(M[l] == 0)
			{
				M[l] = ct;
				ct++;
			}
			for(int j = 0; j < r.size(); j++)
			{
				//cout << '\t' << r[j] << endl;
				if(M[r[j]] == 0)
				{
					M[r[j]] = ct;
					ct++;
				}
				edge[M[r[j]]].pb(M[l]);
				e_c[M[l]]++;
			}
			inp.pb(l);
		}
		int flag = 1;
		int visited[10001];
		memset(visited, 0, sizeof(visited));
		while(flag == 1)
		{
			flag = 0;
			for(int i = 0; i < inp.size(); i++)
			{
				int n = M[inp[i]];
				if(e_c[n] == 0 && !visited[n])
				{
					visited[n] = 1;
					for(int j = 0; j < edge[n].size(); j++)
					{
						e_c[edge[n][j]]--;
					}
					edge[n].clear();
					flag = 1;
				}
			}
		}
		flag = 0;
		for(int i = 0; i < inp.size(); i++)
		{
			//cout << M[inp[i]] << ' ' << e_c[M[inp[i]]]<<endl;
			if(e_c[M[inp[i]]] != 0)
				flag = 1;
		}
		if(flag == 0)
		{
			pf("Case #%d: GOOD\n", t);
		}
		else
			pf("Case #%d: BAD\n", t);
	}
	return 0;
}
