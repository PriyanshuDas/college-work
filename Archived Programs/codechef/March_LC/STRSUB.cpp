#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N, K, Q;
		sf("%d%d%d", &N, &K, &Q);
		string St;
		cin >> St;
		int S[N+1];
		S[0] = 0;
		for (int j = 0; j < N; j++)
		{
			S[j+1] = St[j] - '0';
		}
		int arr[N+1][2];
		arr[0][0] = 0;
		arr[0][1] = 0;
		map< pair<int, int>, long long int> ct;
		for (int j = 1; j <= N; j++)
		{
			arr[j][0] = arr[j-1][0];
			arr[j][1] = arr[j-1][1];
			arr[j][S[j]]++;
		}
		for (int j = 1; j <= N; j++)
		{
			for(int k = j; k <= N; k++)
			{
				if(arr[k][0] - arr[j-1][0] <= K && arr[k][1] - arr[j-1][1] <= K)
				{
					for(int l = 1; l<=j; l++)
					{
						for(int m = N; m>= k; m--)
						{
							ct[mp(l, m)]+= 1;					
						}
					}
				}
			}
		}
		for (int j = 0; j < Q; j++)
		{
			int L, R, ans;
			scanf("%d%d", &L, &R);
			ans = ct[mp(L,R)];
			pf("%d\n",ans);

		}
	}
	return 0;
}