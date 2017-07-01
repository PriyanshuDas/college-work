#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >
#define max_n 100001

using namespace std;

int n, m, k;
vector <int>adj[max_n+1];
bool flour[max_n+1];
int main()
{
	//Closest non special node from each
	cin >> n >> m >> k;
	vector <pi3> Inp;
	for(int i = 0; i < m; i++)
	{
		ll a, b, c;	sf("%lld%lld%lld", &a, &b, &c);
		Inp.pb(mp(c, mp(a, b)));
	}
	for(int i = 0; i < k; i++)
	{
		ll sp;	sf("%lld", &sp);
		flour[sp] = 1;
	}
	ll ans = 9999999999999999;
	for(int i = 0; i < Inp.size(); i++)
	{
		ll d= Inp[i].first;
		ll a= Inp[i].second.first;
		ll b= Inp[i].second.second;
		if((flour[a] == 1 && flour[b] ==0)||(flour[a]==0&&flour[b]==1))
		{
			ans = min(ans, d);
		}
	}
	if(ans == 9999999999999999)
		cout << "-1";
	else
		cout << ans;
	return 0;
}
