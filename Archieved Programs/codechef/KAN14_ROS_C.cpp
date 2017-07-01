#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ull unsigned ll

using namespace std;

ll MOD = 1000000007;

ll perm[10000];
ull comb[1001][1001];

vector <ll> Ext_Euclid(ll a, ll b)
{
	if(b == 0)
	{
		vector <ll> tmp;
		tmp.pb(1);	tmp.pb(0);	tmp.pb(a);
		return tmp;
	}
	vector <ll> curr = Ext_Euclid(b, a%b);
	vector <ll> nu;
	nu.pb(curr[1]);	nu.pb(curr[0]-(a/b)*curr[1]);	nu.pb(curr[2]);
	return nu;
}

ll inverse_mod(ll n)
{
	vector <ll> temp = Ext_Euclid(n, MOD);
	if(temp[0] < 0)
		temp[0] += MOD;
	return temp[0];
}

ull combine(ll n, ll r)
{
	if(r == 0)
		return 1;
	if(r == 1)
		return n%MOD;
	ull num = 1;
	ull den = 1;
	num = perm[n];
	den = perm[r];
	den = (den*perm[n-r])%MOD;
	//pf("(%lld, %lld)\tNum = %lld\tDen = %lld\n", n, r, num, den);
	ull ans = num*(inverse_mod(den))%MOD;
	return ans;
}

void precompute()
{
	ll curr = 1;
	for(int i = 1; i <= 1001; i++)
	{
		perm[i-1] = curr;
		curr = (curr*(i))%MOD;
	}
	for(int i = 0; i <= 1000; i++)
	{
		comb[i][0] = 1;
		comb[i][i] = 1;
		for(int j = 1; j < i; j++)
		{
			ll mul = (i-j)%MOD;
			ll den = inverse_mod((ll)(j+1));
			mul = (mul*den)%MOD;
			comb[i][j] = (comb[i][j-1]*mul)%MOD;
		}
	}
}

ull Ans[1001][1001];

ull solve(int n, int k)
{
	if(Ans[n][k] != -1)
		return Ans[n][k];
	if(n < k)
	{
		Ans[n][k] = 0;
		return 0;
	}
	if(k == 0 && n != 0)
	{
		Ans[n][k] = 0;
		return 0;
	}
	if(k == 0 && n == 0)
	{
		Ans[n][k] = 1;
		return 1;
	}
	Ans[n][k] = 0;
	for(int s = 1; (n-s) >= k-1; s++)
	{
		ull curr_ans = (comb[n][s]*perm[s-1])%MOD;
		curr_ans = (curr_ans*solve(n-s, k-1))%MOD;
		Ans[n][k] = (Ans[n][k] + curr_ans)%MOD;
	}
	return Ans[n][k];
}

int main()
{
	precompute();
	int T;	cin >> T;
	memset(Ans, -1, sizeof(Ans));
	/*for(int t = 0; t < T; t++)
	{
		int N, K;
		sf("%d%d", &N, &K);
		ull ans = solve(N, K);
		ll den = inverse_mod(K);
		ans = (ans*den)%MOD;
		pf("%llu\n",ans);
	}*/
	return 0;
}
