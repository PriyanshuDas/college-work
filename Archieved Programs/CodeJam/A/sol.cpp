#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pi2 pair<int, int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main()
{
	int T;	cin >> T;
	while(T--)
	{
		int R, C;	sf("%d%d", &R, &C);
		string cake[R];
		for(int i = 0; i < R; i++)
		{
			string c;	cin >> c;
			cake[i] = c;
		}
		map<char, pair<pi2, pi2> > A;
		//(c, (begin_x, begin_y), (end_x, end_y))
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
			{
				if(cake[i][j] == '?')
					continue;
				if(A.find(cake[i][j]) == A.end())
					A[cake[i][j]] = mp(mp(999, 999), mp(0, 0));
				else
				{
					char c = cake[i][j];
					if(A[c].fi.fi <= i && A[c].fi.se <= j)
						A[c].fi = mp(i, j);
					if(A[c].se.fi >= i && A[c].se.se >= j)
						A[c].se = mp(i, j);
				}
			}
		for(auto it = A.begin(); it != A.end(); it++)
		{
			for(int i = it->se.fi.fi; i <= it->se.se.fi; i++)
			{
				for(int j = it->se.fi.se; j <= it->se.se.se; j++)
					cake[i][j] = it->fi;
			}
		}
		for(int i = 0; i < R; i++)
			cout << cake[i] << endl;
	}
	return 0;
}