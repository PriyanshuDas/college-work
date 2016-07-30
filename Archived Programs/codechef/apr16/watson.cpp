#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int

using namespace std;

ll expon(ll num, ll p, ll mod)	//(num, pow, mod)
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
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        ll N, K;    cin >> N >> K;
        ll ans = expon((K-1), N-1, MOD);
        ans = (ans*K)%MOD;
        cout << ans << endl;
    }
    return 0;
}
