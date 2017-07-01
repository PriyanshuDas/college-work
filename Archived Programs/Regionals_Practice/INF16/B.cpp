#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ins insert
#define pb push_back
#define ll long long int
#define ull unsigned ll
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define fi first
#define se second

using namespace std;

int main()
{
	int T;	sf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		vector <pi2> Tline;
		int R, G;	sf("%d%d", &R, &G);
		ll A, B;	sf("%lld%lld", &A, &B);
		int ans = 0;
		int mx = 0;
		for(int i = 0; i < R; i++)			// Red goes right
		{
			ll P, V;	sf("%lld%lld", &P, &V);
			if(V == 0)
			{
				if(P >= A && P <= B)
					mx++;
				continue;
			}
			ll t0 = max((A-P + V-1)/V, (ll)0);
			ll t1 = (B-P + V)/V;
			if(t1 <= 0 || t1 == t0)
				continue;
			else
			{
				Tline.pb(mp(t1, 0));
				Tline.pb(mp(t0, 1));
			}
		}
		
		
		for(int i = 0; i < G; i++)			// Green goes left
		{
			ll P, V;	sf("%lld%lld", &P, &V);
			if(V == 0)
			{
				if(P >= A && P <= B)
					mx++;
				continue;
			}
			ll t0 = max((P-B + V-1)/V, (ll)0);
			ll t1 = (P-A + V)/V;
			if(t1 <= 0 || t1 == t0)
				continue;
			else
			{
				Tline.pb(mp(t1, 0));
				Tline.pb(mp(t0, 1));
			}
		}
		sort(Tline.begin(), Tline.end());
		ans = max(ans, mx);
		for(int i = 0; i < Tline.size(); i++)
		{
			ans = max(ans, mx);
			if(Tline[i].se == 0)
				mx--;
			else
				mx++;
			ans = max(ans, mx);
		}
		pf("Case %d: %d\n", t+1, ans);
	}
	return 0;
}
