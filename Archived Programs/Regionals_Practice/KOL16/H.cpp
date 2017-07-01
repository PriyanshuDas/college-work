#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define ull unsigned ll
#define MOD 1000000007
using namespace std;

ll pow_2[64];
//********** Careful when mod > 10^9, Might Overflow*************

void precomp()
{
	ll p = 1;
	for(int i = 0; i < 64; i++)
	{
		pow_2[i] = p;
		p = p*2;
	}
}

ll st_to_in(string s)
{
	ll c = 0;
	for(int i = 0; i < s.size(); i++)
	{
		c *= 10;
		c += (s[i] - '0');
	}
	return c;
}

int main()
{
	int T;	cin >> T;
	precomp();
	/*for(int i = 0; i < 35; i++)
	{
		pf("2^%d\t == %lld\n", i, pow_2[i]);
	}*/
	for(int t = 0; t < T; t++)
	{
		string s;	cin >> s;
		pf("Case %d:", t+1);
		if(s.size() <= 2)
		{
			ll cur = st_to_in(s);
			//cout << cur << endl;
			if(cur < 33)
			{
				pf("%lld\n", pow_2[cur]-1);
			}
			else
			{
				pf("%lld\n", pow_2[33]-1);
			}
		}
		else
			pf("%lld\n", pow_2[33]-1);
	}
	return 0;
}
