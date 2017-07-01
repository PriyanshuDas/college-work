#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

vector <int> primes;
vector <int> prim;
vector <int>prim_pow;


ll pow(ll num, ll p, ll mod)	//(num, pow, mod)
{
	ll pow_arr[64];
	ll tmp = num;
	for(int i = 0; i < 63; i++)
	{
		pow_arr[i] = tmp%mod;
		tmp = (tmp*tmp)%mod;
		//cout << pow_arr[i] << '\t';
	}
	tmp = 1;
	ll tmp2 = 1;
	for(int i = 0; i < 63; i++)
	{
		ll curr = tmp2<<i;
		//pf("@pos %d\t %lld\n", i, (p&curr));
	 	if((p&curr) > 0)
			tmp = (tmp*pow_arr[i])%mod;
	}
	if(tmp == mod-1)
		tmp -= mod;
	return tmp;
}

int main()
{
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int tmp;
        sf("%d", &tmp);
        primes.pb(tmp);
    }
    sort(primes.begin(), primes.end());
    int ct = 1;
    prim.pb(primes[0]);
    for(int i = 1; i < primes.size(); i++)
    {
        if(primes[i] != primes[i-1])
        {
            prim_pow.pb(ct);
            prim.pb(primes[i]);
            ct = 0;
        }
        ct++;
    }
    prim_pow.pb(ct);
    /*for(int i = 0; i < prim.size(); i++)
    {
        cout << prim[i] << '\t' << prim_pow[i] << endl;
    }*/

    int S = 1;
    int flag = 0;
    for(int i = 0; i < prim.size(); i++)
    {
        if(prim_pow[i]%2 != 0 && !flag)
        {
            flag = 1;
            S = (S*((prim_pow[i]+1)/2))%(MOD-1);
        }
        else
            S = (S*(prim_pow[i]+1))% (MOD-1);
    }
    int prod_prim = 1;
    for(int i = 0; i < prim.size(); i++)
    {
        prod_prim = (prod_prim*prim[i])%MOD;
    }
    ll num2 = 1;
    for(int i = 0; i < prim.size(); i++)
    {
        int tmp = prim_pow[i];
        if(flag == 0)
        {
            tmp /= 2;
        }
        num2 = (num2* pow(prim[i], tmp, MOD))%MOD;
    }
    ll ans = pow(num2, S, MOD);
    cout << ans;
    return 0;
}
