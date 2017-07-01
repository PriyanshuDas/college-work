#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back

using namespace std;

ll expon(ll num, ll p, ll mod)	//(num, pow, mod)
{
	ll pow_arr[64] = {0};
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
		ll mask = p&curr;
		//pf("@pos %d\t %lld\n", i, (p&curr));
	 	if(mask != 0)
			tmp = (tmp*pow_arr[i])%mod;
	}
	if(tmp < 0)
        tmp += mod;
	return tmp;
}

int main()
{
    ll M = 10000000000;
    ll ans = 0;
    pf("%lld\n", expon(99, 99, M));
    /*for(ll i = 1; i <= 1000; i++)
    {
        ll tmp = expon(i, i, M);
        //cout << tmp << endl;
        if(tmp < 0)
            cout << tmp << endl;
        ans = (ans + tmp)%M;
        if(ans < 0)
            cout << ans << endl;
    }*/
    cout << ans << endl;
}
