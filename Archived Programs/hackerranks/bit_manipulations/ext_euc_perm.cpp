#include <bits/stdc++.h>

#define pb push_back
#define ll long long int
#define pf printf
#define MOD 1000000007

using namespace std;

ll Perm[1001];
ll permute(int N)
{
	if(Perm[N])
		return Perm[N];
	if(N == 1 || N == 0)
		return 1;
	Perm[N] = (N*permute(N-1))%MOD;
	return Perm[N];
}

vector<ll> Ext_Euclid(ll a, ll b)
{
	if(b == 0)
	{
		vector <ll> ans;
		ans.pb(a);ans.pb(1); ans.pb(0);
		return ans;
	}
	vector <ll> orig = Ext_Euclid(b, a%b);
	vector <ll> ans;
	ans.pb(orig[0]);
	ans.pb(orig[2]);
	ans.pb(orig[1] - (a/b)*orig[2]);
	pf("%lld * %lld + %lld * %lld = %lld\n\n", a, ans[1], b, ans[2], ans[0]);
	return ans;
}

ll inverse_mod(ll N)
{
	vector <ll> euclids_grail = Ext_Euclid(N, MOD);
	return (euclids_grail[1]%MOD);
}

int main()
{
	ll A, B;
	cin >> A >> B;
	Ext_Euclid(A,B);
	return 0;
}
