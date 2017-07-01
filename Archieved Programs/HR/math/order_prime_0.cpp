#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define max_l 1000*1000*1000*1000

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		ll L, p;	cin >> p >> L;
		ll ct = (p-1);
		ll ans = 0;
		ll c = 0;
		pf("0\t-\t0**\n");
		while( c < L)
		{
			c += p;
			ll c2 = c;
			ll po = p;
			int fl = -1;
			while(c2%po == 0)
			{
				ans++;
				c2 /= po;
				fl++;
			}
			pf("%lld\t-\t%lld", c, ans);
			if(ans%p == 0)
				pf("**");
			pf("\t");
			while(fl > 0)
			{
				fl--;
				pf("|\t");
			}
			pf("|\n");
			if(ans%p == 0)
				ct++;
		}
		cout << "Total count is : " << ct << endl;		
	}
	return 0;
}

