
#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define ull long long int
#define mp make_pair
#define pb push_back
#define max_n 10000001
#define n_max 2000001

using namespace std;
ull perm[max_n+1], MOD = 1000000007;

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
ll inverse_mod(ll n)				//find inverse mod of a number
{
	vector <ll> temp = Ext_Euclid(n, MOD);
	if(temp[0] < 0)	temp[0] += MOD;
	return temp[0];
}
void precomp()
{
	ull c = 1;
	perm[0] = 1;
	for(int i = 1; i < max_n; i++)
		perm[i] = c = (c*i)%MOD;
}
ll combine(ll n, ll r)
{
	ll num = perm[n], den = (perm[r]*perm[n-r])%MOD;
	den = inverse_mod((ll)den);
	ll ans = (num*den)%MOD;
	return ans;
}


string s;	
int ct[2][n_max+1];
ll n = 0;
ll ans = 0;

void solve()
{
	for(int i = 1; i < n; i++)
	{
		if(s[i-1] != '(')
			continue;
		ll tmp = 0;
		//pf("(%d, %d)\n", ct[0][i], ct[1][i]);
		int m = min(ct[0][i], ct[1][i]);
		tmp = combine(ct[0][i]+ct[1][i]-1, ct[1][i]-1);
		ans = (ans + tmp)%MOD;
	}
	cout << ans;
	return;
}

int main()
{
	precomp();
	/*for(int i = 1; i < 10; i++)
	{
		for(int j = 0; j < i; j++)
		{
			pf("(%d, %d) == %lld\n", i, j, combine(i, j));
		}
	}*/cin >> s;
	n = s.size();
	for(int i = 0; i < s.size(); i++)
	{
		ct[0][i+1] = ct[0][i];
		if(s[i] == '(')
			ct[0][i+1]++;
	}
	
	for(int i = s.size()-1; i >= 0; i--)
	{
		ct[1][i] = ct[1][i+1];
		if(s[i] == ')')
			ct[1][i]++;
	}
	solve();
	return 0;
}