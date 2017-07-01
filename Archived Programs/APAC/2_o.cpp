#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >
#define pi4 pair<pair<ll, ll>, pair<ll, ll> >
#define max_n 500001

using namespace std;

vector<pi3> Line;	//(coord, (open/close, interval num)
ll last_c = 0;
vector<ll> x;
vector<ll> y;
int curr_act = 0;
set<int> active;

ll dist[max_n+1];

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		memset(dist, 0, sizeof(dist));
		curr_act = 0;
		x.clear();
		y.clear();
		Line.clear();
		active.clear();
		
		ll N, L1, R1, A, B, C1, C2, M;
		sf("%lld%lld%lld%lld%lld%lld%lld%lld", &N, &L1, &R1, &A, &B, &C1, &C2, &M);
		x.pb(L1);	y.pb(R1);
		Line.pb(mp(L1, mp(0, 1)));
		Line.pb(mp(R1, mp(1, 1)));
		for(int i = 1; i < N; i++)
		{
			ll xi = ((x[i-1]*A)%M + (B*y[i-1])%M + C1)%M;
			ll yi = ((y[i-1]*A)%M + (B*x[i-1])%M + C2)%M;
			x.pb(xi);	y.pb(yi);
			ll Li = min(xi, yi);
			ll Ri = max(xi, yi);
			Line.pb(mp(Li, mp(0, i)));
			Line.pb(mp(Ri, mp(1, i)));
		}
		sort(Line.begin(), Line.end());
		ll max_ans = 0;
		ll total = Line[Line.size()-1].first - Line[0].first + 1;
		
		for(int i = 0; i < Line.size(); i++)
		{
			pi3 c = Line[i];
			ll x = c.first;
			ll t = c.second.first;
			ll n = c.second.second;
			pf("(%lld, (%lld, %lld) )\n", x, t, n);
			if(curr_act == 1)
			{
				set<int>::iterator it = active.begin();
				dist[*it] += x - last_c - 1;
				if(Line[i-1].second.second == *it)
					dist[*it]++;
			}
			if(t == 0)	//open
			{
				active.ins(n);
			}
			if(t == 1)
			{
				max_ans = max(max_ans, dist[n]);
				active.erase(n);
			}
			curr_act = active.size();
			last_c = x;
		}
		ll ans = total - max_ans;
		pf("Active Size : %lu\t%lld\n", active.size(), ans);
	}
	return 0;
}
