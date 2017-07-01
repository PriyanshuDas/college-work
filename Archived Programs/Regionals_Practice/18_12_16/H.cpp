#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back

using namespace std;

int T, n;

int main()
{
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		cin >> n;
		vector <ll> coal;
		vector <ll> pol;
		for(int i = 0; i < n; i++)
		{
			ll tmp;	sf("%lld", &tmp);
			coal.pb(tmp);
		}
		
		for(int i = 0; i < n-1; i++)
		{
			ll tmp;	sf("%lld", &tmp);
			pol.pb(-1*tmp);
		}
		for(int i = 0; i < n-1; i++)
		{
			int p;	sf("%d", &p);
			if(p == 2)
				pol[i] *= 2;
		}
		
		vector <ll> fin;
		for(int i = 0; i < 2*n - 1; i++)
		{
			if(i%2 == 0)
				fin.pb(coal[i/2]);
			else
				fin.pb(pol[i/2]);
		}
		ll ans = 0;
		ll curr = 0;
		for(int i = 0; i < fin.size(); i++)
		{
			//pf("%lld ", fin[i]);
			curr += fin[i];
			if(curr > ans)
				ans = curr;
		}
		cout << ans << endl;
	}
	return 0;
}
