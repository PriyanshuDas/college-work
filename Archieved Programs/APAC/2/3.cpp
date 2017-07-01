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
set<ll> active;

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
		Line.pb(mp(min(L1, R1), mp(0, 0)));
		Line.pb(mp(max(R1, L1), mp(1, 0)));
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
		ll c_pos = 0;
		curr_act = 0;
		ll total = 0;
		int flag = 0;
		for(int i = 0; i < Line.size(); i++)
		{
			ll x= Line[i].first;
			ll t= Line[i].second.first;
			ll n= Line[i].second.second;
			set<ll>::iterator it = active.begin();
			//pf("(%lld, (%lld, %lld) -- %d )\n", x, t, n, curr_act);
			if(c_pos < x)						// Update
			{
				if(curr_act > 0)
				{
					total += x - c_pos;
				}
				if(curr_act == 1)
				{
					dist[*it] += x - c_pos;
				}
				c_pos = x;
			}
			int j = i;
			while(j < Line.size() && Line[j].second.first == 0 && Line[j].first == x)	// Open
			{
				ll n1= Line[j].second.second;
				active.ins(n1);
				curr_act++;
				j++;
			}
			it = active.begin();
			if(curr_act > 0)
			{
				total++;
				if(curr_act == 1)
					dist[*it]++;
			}
			c_pos++;
			while(j < Line.size() && Line[j].second.first == 1 && Line[j].first == x)	// Close
			{
				ll n1= Line[j].second.second;
				active.erase(n1);
				curr_act--;
				max_ans = max(max_ans, dist[n1]);
				j++;
			}
			i = j-1;
		}
		ll ans = total - max_ans;
		pf("Case #%d: %lld\n", t+1, ans);
	}
	return 0;
}
