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
		int ans = 0;
		for(int i = 0; i <= s.size()-K; i++)
			if(s[i] == '-')
			{
				ans++;
				for(int j = i; j < i+K; j++)
				{
					if(s[j] == '-')
						s[j] = '+';
					else
						s[j] = '-';
				}
			}
		int flag = 0;
		for(int i = 0; i < s.size(); i++)
			if(s[i] == '-')
				flag = 1;
		//cout << s << endl;
		if(flag == 0)
			pf("Case #%d: %d\n", t, ans);
		else
			pf("Case #%d: IMPOSSIBLE\n", t);
	}
	return 0;
}