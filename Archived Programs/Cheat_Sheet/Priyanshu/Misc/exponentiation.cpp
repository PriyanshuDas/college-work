#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int

using namespace std;

//********** Careful when mod > 10^9, Might Overflow*************
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

