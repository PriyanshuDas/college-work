#include <bits/stdc++.h>

#define pf printf
#define sf scanf

int ct[10000001];
int ct_n[10000001][11];
bool prim[1001];

using namespace std;

int main()
{
	ct_n[0][0] = 1;
	ct_n[1][0] = 2;
	for(int i = 2; i < 10000001; i++)
	{
		if( i < 1000 && !prim[i])
		{
			for(int j = i; j <= 10000001; j+= i)
			{
				if(j <= 1000)
					prim[j]++;
				ct[j]++;
			}
		}
		for(int j = 0; j < 11; j++)
		{
			ct_n[i][j] = ct_n[i-1][j];
			if(ct[i] == j)
				ct_n[i][j]++;
		}
	}
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int a, b, n;
		sf("%d%d%d", &a, &b, &n);
		int ans = ct_n[b][n] - ct_n[a-1][n];
		pf("%d\n", ans);
	}
	return 0;
}
