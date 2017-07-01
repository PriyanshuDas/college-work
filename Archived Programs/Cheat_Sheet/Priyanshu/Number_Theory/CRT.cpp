/* ---------------------Chinese Remainder Theorem-----------------------------
Tries to solve a set of modular equations ax = rx mod nx, for some n=lcm(nx)
returns (a, n), a = -1 if no solution possible. Uses binary split
Works only for prime numbers.
For non prime numbers can tell if solution exists or not		*/

#include <bits/stdc++.h>

#define sf scanf			
#define pf printf
#define ll long long int	
#define pi2 pair<ll, ll>
#define fi first			
#define se second
#define pb push_back
#define mp make_pair
#define pi3 pair<pi2, ll>

using namespace std;

vector <pair <ll, ll> > E;	//(ai, ni)
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
ll inverse_mod(ll n, ll m)				//find inverse mod of a number
{
	vector <ll> temp = Ext_Euclid(n, m);
	if(temp[0] < 0)	temp[0] += m;
	return temp[0];
}

ll gcd(ll A, ll B)
{
	if(A == 0)	return B;
	return gcd(B%A, A);
}

ll lcm(ll A, ll B)
{
	return ((A*B)/gcd(A, B));	//Careful for ll A, B use sieve if needed
}

pair <pi2, ll> solve_2(pi2 A, pi2 B)
{
	if(A == B)
		return A;
	ll g = gcd(A.se, B.se), l = lcm(A.se, B.se);
	if(A.fi%g != B.fi%g)
		return mp(mp(-1, l), g);
	ll Ai = inverse_mod(A.se, B.se), Bi = inverse_mod(B.se, A.se);
	ll n = (A.fi*B.se*Bi + B.fi*A.se*Ai)%l;
	return mp(mp(n, l), g);
}

pair <ll, ll> solve(int l, int r)
{
	int mid = (l+r)/2;
	pi2 ans;
	if(r <= l+1)
	{
		ans = solve_2(E[l], E[r]);
		pf("(%d, %d)\t(%lld, %lld)\n", l, r, ans.fi, ans.se);
		return ans;
	}
	pi2 left = solve(l, mid);
	pi2 rigt = solve(mid+1,r);
	if(left.fi == -1 || rigt.fi == -1)
		ans = mp(-1, lcm(left.se, rigt.se));
	else	ans = solve_2(left, rigt);
	pf("(%d, %d)\t(%lld, %lld)\n", l, r, ans.fi, ans.se);
	return ans;
}

int main()
{
	int n;	cin >> n;
	for(int i = 0; i < n; i++)
	{
		ll a, n;	cin >> a >> n;
		E.pb(mp(a, n));
	}
	pair<ll, ll> ans = solve(0, n-1);
	pf("x == %lld MOD %lld\n", ans.fi, ans.se);
	return 0;
}
