#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int K, C, S;
		sf("%d%d%d", &K, &C, &S);
		pf("Case #%d: ", t+1);
		if(C == 1 && S < K || (C > 1 && 2*S < K) )
			cout << "IMPOSSIBLE\n";
		else if (C == 1 && S >= K)
		{
			for(int i = 1; i <= K; i++)
				pf("%d ", i);
			pf("\n");
		}
		else
		{
			vector <int> ans;
			for(int i = 1; 2*i <= K; i++)
			{
				ans.pb(2*K*(i-1) + 2*i);
			}
			if(K%2 == 1)
			{
				int i = K/2 + 1;
				ans.pb(2*K*(i-1) + 2*i-1);
			}
			for(int i = 0; i < ans.size(); i++)
				pf("%d ", ans[i]);
			pf("\n");
		}
	}
	return 0;
}
