#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define loop(n) for(int i = 0; i < n; i++)
#define loop(l,n) for(l; l < n; l++)
#define pi2 pair<int, int>
#define pi3 pair<int, pair<int,int> >
#define pi4 pair<pair<int, int>, pair<int, int> >

using namespace std;

ll l, r, k;
ll min_pow, max_pow;

ll expon(ll num, ll p)	//(num, pow, mod)
{
	ll pow_arr[64];
	ll tmp = num;
	for(int i = 0; i < 63; i++)
	{
		pow_arr[i] = tmp;
		tmp = (tmp*tmp);
		//cout << pow_arr[i] << '\t';
	}
	tmp = 1;
	ll tmp2 = 1;
	for(int i = 0; i < 63; i++)
	{
		ll curr = tmp2<<i;
		//pf("@pos %d\t %lld\n", i, (p&curr));
	 	if((p&curr) > 0)
			tmp = (tmp*pow_arr[i]);
	}
	return tmp;
}
void gen(ll curr)
{
    if(k == 1)
        cout << 1;
    ll tmp = curr;
    while(tmp < r)
    {
        pf("%lld ", tmp);
        if(tmp > r/k)
            break;
        tmp *= k;
    }
}

int main()
{
    vector <ll> powers;
    ll l, r, k;
    cin >> l >> r >> k;
    ll tmp = 1;
    powers.pb(1);
    while(tmp <= r/k && k != 1)
    {
        tmp *= k;
        powers.pb(tmp);
    }
    int flag = 0;
    for(int i = 0; i < powers.size(); i++)
    {
        if(powers[i] >= l && powers[i] <= r)
        {
            pf("%lld ", powers[i]);
            flag = 1;
        }
    }
    if(!flag)
        cout << -1;
    return 0;
}
