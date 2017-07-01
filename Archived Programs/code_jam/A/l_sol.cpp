#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define ull unsigned ll
#define inf 9999999999999
using namespace std;

int main()
{
	int T, t = 0;	cin >> T;
	while(T--)
	{
		t++;
		string s;	cin >> s;
		ll K;	cin >> K;
		ll ans = inf;
		int pos = s.size()-K;
		for(int i = 0; i < (1<<(pos+1)); i++)
		{
			string c = s;
			ll flips = 0;
			for(int j = 0; j <= pos; j++)
			{
				if((i&(1<<j)) != 0)
				{
					flips++;
					for(int k = j; k < j+K; k++)
					{
						if(c[k] == '-')
							c[k] = '+';
						else
							c[k] = '-';
					}
				}
			}
			int flag = 0;
			for(int j = 0; j < c.size(); j++)
			{
				if(c[j] == '-')
					flag = 1;
			}
			if(flag == 0)
			{
				//cout << c << "\t" << flips << endl;
				ans = min(ans, flips);
			}
		}
		if(ans < inf)
			pf("Case #%d: %lld\n", t, ans);
		else
			pf("Case #%d: IMPOSSIBLE\n", t);
	}
}