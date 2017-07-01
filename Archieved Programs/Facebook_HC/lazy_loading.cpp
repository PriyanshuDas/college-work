#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ull unsigned ll
#define ins insert

using namespace std;

int main()
{
	int T;	sf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		int N;	sf("%d", &N);
		vector<int> V;
		for(int n = 0; n < N; n++)
		{
			int tmp;	sf("%d", &tmp);
			V.pb(tmp);
		}
		sort(V.begin(), V.end());
		int p1 = 0, p2 = V.size()-1;
		int c_sum = 0;
		int ans = 0;
		while(p1 < p2)
		{
			c_sum = V[p2];
			while(c_sum < 50 && p1 < p2)
			{
				c_sum += V[p2];
				p1++;
			}
			if(c_sum >= 50)
			{
				ans++;
				p2--;
			}
		}
		pf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}