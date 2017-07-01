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
		string s; cin >> s;
		vector<int> zero_ct, gap_ct;
		int n = s.size();
		for (int i = 0; i < n; ++i)
		{
			zero_ct.pb(0);
			gap_ct.pb(0);
		}
		int c_ct = 0;
		for(int i = n-1; i >= 0; i--)
		{
			if(i < n-1)
			{
				zero_ct[i] = zero_ct[i+1];
				gap_ct[i] = gap_ct[i+1];
			}
			if(s[i] == '0')
			{
				c_ct++;
				zero_ct[i]++;
			}
			else
			{
				if(c_ct > 0)
                    gap_ct[i]++;
				c_ct = 0;
			}
		}
		ll ans = 0;
		for(int i = 0; i < n; i++)
            if(s[i] == '1')
                ans += (gap_ct[i]+zero_ct[i]);

		pf("%lld\n", ans);
	}
	return 0;
}
