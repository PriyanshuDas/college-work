#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(l,r) for(int i = l; i < r; i++)
#define k_max 100001

using namespace std;

int n, m, k;
vector <pair<int, int> > K;


vector <ll> Ext_Euclid(ll a, ll b)	//Solve Ax + By = gcd(A, B)
{
	if(b == 0)
	{
		vector <ll> tmp;	tmp.pb(1);	tmp.pb(0);	tmp.pb(a);
		return tmp;
	}
	vector <ll> curr = Ext_Euclid(b, a%b);
	vector <ll> nu;
	nu.pb(curr[1]);
	nu.pb(curr[0] - (a/b)*curr[1]);
	nu.pb(curr[2]);
	return nu;
}


int main()
{
	sf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++)
	{
		int xi, yi;	sf("%d%d", &xi, &yi);
		K.pb(mp(xi, yi));
	}
	vector<ll> ans;
	for(int i = 0; i < K.size(); i++)
	{
		ll x = K[i].first;
		ll y = K[i].second;
		ll Dx = n - x;
		ll Dy = m - y;
		vector <ll> G = Ext_Euclid(Dx, Dy);
		ll x1, y1;
		int flag = 0;
		if((y >= x && G[1] <= 0) || (x >= y && G[0] <= 0))
			flag = 1;
		if(flag == 1 &&abs(x-y)%G[2] == 0)
		{
			x1 = x + abs(G[0])*Dx;
			y1 = y + abs(G[1])*Dy;
			ans.pb(x1);
		}
		else
		{
			ans.pb((ll)-1);
		}
	}
	for(int i = 0; i < K.size(); i++)
	{
		pf("%lld\n", ans[i]);
	}
	return 0;
}
