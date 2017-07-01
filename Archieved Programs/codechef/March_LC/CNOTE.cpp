#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int X, Y, K, N;
		bool flag = 0;
		sf("%d%d%d%d", &X, &Y, &K, &N);
		X -= Y;
		for (int j = 0; j < N; j++)
		{
			int Pi, Ci;
			scanf("%d%d",&Pi, &Ci);
			if (Pi >= X && Ci <= K)
			{
				flag = 1;
			}
		}
		if(!flag)
			pf("UnluckyChef\n");
		else
			pf("LuckyChef\n");
	}
	return 0;
}