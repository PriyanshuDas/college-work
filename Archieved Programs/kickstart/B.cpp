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
int N;
vector <string> S;

bool confirm (int x1 , int y1)
{
	int x2 = -1, y2 = -1;
	for(int y = 0; y < N; y++)
	{
		if(S[x1][y] == 'X' && y != y1)
			y2 = y;
	}
	for(int x = 0; x < N; x++)
	{
		if(S[x][y1] == 'X' && x != x1)
			x2 = x;
	}
	//pf("(%d, %d)\t(%d, %d)\n", x1, y1, x2, y2);
	if((x2 == -1 && y2 != -1) || (x2 != -1 && y2 == -1))
		return false;
	if((x2 == -1 && y2 == -1) || (S[x1][y1] == 'X' && S[x1][y2] == 'X' && S[x2][y1] == 'X' && S[x2][y2] == 'X'))
		return true;
	return false;
}

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> N;
		S.clear();
		for(int i = 0; i < N; i++)
		{
			string s;	cin >> s;
			//cout << s << endl;
			S.pb(s);
		}
		int flag_r[4] = {0};
		int flag_c[4] = {0};
		for(int i = 0; i < N; i++)
		{
			int ct = 0;
			for(int j = 0; j < N; j++)
			{
				if(S[i][j] == 'X')
					ct++;
			}
			//pf("%d\t%d\n", i, ct);
			flag_r[min(ct, 3)]++;
			
			ct = 0;
			for(int j = 0; j < N; j++)
			{
				if(S[j][i] == 'X')
					ct++;
			}
			//pf("%d\t%d\n", i, ct);
			flag_c[min(ct, 3)]++;
		}

		if(flag_r[0] == 0 && flag_c[0] == 0 && flag_r[1] == 1 && flag_c[1] == 1 && flag_r[3] == 0 && flag_c[3] == 0)
		{
			int flag = 0;
			for(int i = 0; i < N && flag == 0; i++)
			{
				for(int j = 0; j < N; j++)
					if(S[i][j] == 'X' && !confirm(i, j))
					{
						pf("Case #%d: IMPOSSIBLE\n", t);
						flag = 1;
						break;
					}
			}
			if(flag == 0)
				pf("Case #%d: POSSIBLE\n", t);
		}

		else
			pf("Case #%d: IMPOSSIBLE\n", t);
	}
	return 0;
}