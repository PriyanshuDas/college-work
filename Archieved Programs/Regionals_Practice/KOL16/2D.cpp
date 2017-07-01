#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define n_max 100001
#define int_max 9999999
#define del 0.000001
#define fi first
#define se second

using namespace std;
ll n, l, v1, v2, k;

ll gcd(ll A, ll B)
{
	if(A == 0)	return B;
	return gcd(B%A, A);
}
pair<ll, ll> bin_s(double L, double R)
{
	double ans = l/v1;
	ll num = l, den = v1;
	ll g = gcd(num, den);
	num = num/g;	den = den/g;
	while(abs(R-L) > del)
	{
		ll T_num = (2*l-(L+R))*v2+(L+R)*v1;
		ll T_den = 2*v1*v2;
		ll T_g = gcd(T_Num, T_den);
		T_num = T_num/g;	T_den = T_den/g;
		
		ll X_num = m*(L+R)*(v1+v2)+(m-1)*(v2-v1)*d2;
		ll X_den = 2*v2*(v+v2);
		ll X_g = gcd(X_num, X_den);
		X_num = X_num/g;	X_den = X_den/g;
			
		if(X_num*T_den <= T_num*X_den)
		{
			L = ((double)(L+R))/2;
			num = d1*v2 + d2*v1, den = v1*v2;
			ll g = gcd(num, den);
			num = num/g;	den = den/g;
			//pf("d = %lf -> T = %lf\n", d2, ans);
			continue;
		}
		else
		{
			R = d2;
			continue;
		}
	}
	return mp(num, den);
}

int main()
{
    cin >> l >> n >> k >> v1 >> v2;
    while(l != 0)
    {
		int t = (ceil)(n/k);
		pair<ll, ll> ans = bin_s(0, l);
		ll num = ans.fi, den = ans.se;
		ll g = gcd(num, den);
		num = num/g;	den = den/g;
		pf("%lld/%lld\n", num, den);
		cin >> l >> n >> k >> v1 >> v2;
    }
    return 0;
}
