#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define m_max 1048575
#define n_max 20
#define MOD 1000000007
#define ull unsigned ll

using namespace std;

//********** Careful when mod > 10^9, Might Overflow*************
ull expon(ull num, ull p, ull mod)	//(num, pow, mod)
{
	ull pow_arr[64];
	ull tmp = num;
	for(int i = 0; i < 63; i++)
	{
		pow_arr[i] = tmp%mod;
		tmp = (tmp*tmp)%mod;
		//cout << pow_arr[i] << '\t';
	}
	tmp = 1;
	ull tmp2 = 1;
	for(int i = 0; i < 63; i++)
	{
		ull curr = tmp2<<i;
		//pf("@pos %d\t %lld\n", i, (p&curr));
	 	if((p&curr) > 0)
			tmp = (tmp*pow_arr[i])%mod;
	}
	return tmp;
}

bool odd_bit(int n)
{
	int ct = 0;
	for(int i = 0; i < 31; i++)
	{
		if(n&(1<<i))
			ct++;
	}
	return ct%2;
}

ull arr[m_max+1], F[2*m_max+1] = {0};

int main()
{
	ull n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		sf("%llu", &arr[i]);
	}
	ll ans = 0;
	for(int i = 1; i < (1<<n); i++)
	{
		int curr = -1;
		for(int j = 0; j < n; j++)
		{
			if((i&(1<<j)) != 0)
				curr = curr&(arr[j]);
		}
		if(curr != 0)
			ans++;
	}
	cout << ans;
	return 0;
}
