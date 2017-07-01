#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
	int n;	cin >> n;
	ll l_max = -9999999999999;
	vector <ll> R;
	vector <pair<ll, ll> > V;
	for(int i = 0; i < n; i++)
	{
		ll li, ri;	cin >> li >> ri;
		V.pb(mp(li, ri));
	}
	sort(V.begin(), V.end());
	l_max = V[V.size()-1].first;
	int ans = 0;
	for(int i = 0; i < V.size(); i++)
	{
		if(V[i].second >= l_max)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
