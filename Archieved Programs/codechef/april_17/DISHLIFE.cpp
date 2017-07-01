#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define mp make_pair

using namespace std;

int main()
{
	int T;	cin >> T;
	while(T--)
	{
		int N, K;	sf("%d%d", &N, &K);
		map<int, int> M;
		vector <int> V[N+1];
		for(int n = 0; n < N; n++)
		{
			int ct;	sf("%d", &ct);
			while(ct--)
			{
				int ing;	sf("%d", &ing);
				M[ing]++;
				V[n].pb(ing);
			}
		}
		int flag = 0;
		for(int i = 1; i <= K; i++)
			if(M[i] == 0)
			{
				pf("sad\n");
				flag = -1;
				break;
			}

		for(int n = 0; n < N && flag == 0; n++)
		{
			int f = 0;
			for(int i = 0; i < V[n].size(); i++)
			{
				if(M[V[n][i]] > 1)
					f++;
			}
			if(f == V[n].size())
				flag = 1;
		}
		if(flag == 0)
			pf("all\n");
		else if(flag == 1)
			pf("some\n");
	}
}