
#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define max_n 500001

using namespace std;

ll MOD = 1000000007;
ll perm[max_n+1];
ll inv[max_n+1];

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

ll inverse_mod(ll n)				//find inverse mod of a number
{
	vector <ll> temp = Ext_Euclid(n, MOD);
	if(temp[0] < 0)
		temp[0] += MOD;
	return temp[0];
}

ll combine(ll n, ll r)				//Calculate nCr % MOD
{
    if(r > n)
        return 0;
    if(n == r || r == 0)
        return 1;
	ll num = 1;
	ll den = 1;
	num = perm[n]%MOD;
	if(inv[r] != -1)
        den = inv[r]%MOD;
    else
    {
        inv[r] = inverse_mod(perm[r])%MOD;
        den = inv[r]%MOD;
    }
    if(inv[n-r] != -1)
    {
        den = (den*inv[n-r])%MOD;
    }
    else
    {
        inv[n-r] = inverse_mod(perm[n-r])%MOD;
        den = (den*inv[n-r])%MOD;
    }
	ll ans = (num*den)%MOD;
	return ans;
}

void pre_compute()
{
    ll curr = 1;
    for(int i = 1; i < max_n; i++)
    {
        perm[i-1] = curr;
        //inv[i-1] = inverse_mod(curr);
        curr = (curr*i)%MOD;
    }
}

int main()
{
    ll N, K, X;
    sf("%lld%lld%lld", &N, &K, &X);
    pre_compute();
    memset(inv, -1, sizeof(inv));
    vector <ll> V;
    for(int i = 0; i < N; i++)
    {
        ll tmp; sf("%lld", &tmp);
        V.pb(tmp);
    }
    sort(V.begin(), V.end());
    ll c_pos = 0;
    ll ans = 0;
    //pf("N == %lld\tK == %lld\t X == %lld\n", N, K, X);
    for(ll i = 0; i < V.size(); i++)
    {
        ll curr = V[i];
        ll req = V[i] + X;
        //pf("req == %lld\n", req);
        while(c_pos < N-1 && V[c_pos+1] <= req)
        {
            c_pos++;
        }
        ll c_ans = combine(c_pos-i, K-1)%MOD;
        //pf("%lld\t%lld\t(%lld, %lld)\t%lld\n", V[i], req, c_pos-i+1, K, c_ans);
        ans = (ans + c_ans)%MOD;
    }
    cout << ans;
    return 0;
}
