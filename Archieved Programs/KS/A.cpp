#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
//#define ll long long int
#define ll long long int
#define ull unsigned ll
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert

using namespace std;

ll MOD = 1000000007;


vector <ll> Ext_Euclid(ll a, ll b)	//Solve Ax + By = gcd(A, B)
{
	if(b == 0)
	{
		vector <ll> tmp;	tmp.pb(1);	tmp.pb(0);	tmp.pb(a);
		return tmp;
	}
	vector <ll> curr = Ext_Euclid(b, a%b), nu;
	nu.pb(curr[1]);	nu.pb(curr[0] - (a/b)*curr[1]);	nu.pb(curr[2]);
	return nu;
}
ll inverse_mod(ll n, ll MOD)				//find inverse mod of a number
{
	vector <ll> temp = Ext_Euclid(n, MOD);
	if(temp[0] < 0)	temp[0] += MOD;
	return temp[0];
}


int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		ull w, h;	sf("%llu%llu", &w, &h);
		h %= MOD;
		w %= MOD;
		if(h < w)
			swap(h, w);
		ull m = min(h, w)%MOD;
		ull a1 = ((m*h)%MOD*w)%MOD;
		ull ans = a1;
		ull a2 = (m*(m+1)%MOD)%MOD;
		ans = (ans + (((a2*(inverse_mod(2, MOD)))%MOD)*((w+h)%MOD))%MOD)%MOD;	//add Sum(i*(w+h))
		
		a2 = (a2*((2*m)%MOD + 1))%MOD;
		a2 = (a2*inverse_mod(6, MOD))%MOD;

		ans = (ans + a2)%MOD;

		cout << ans << endl;
	}
	return 0;
}