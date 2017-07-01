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

/*http://codeforces.com/contest/449/problem/D

- Tried to solve by finding ct of all x > 0, where ct is the number of sets st and of them equals x

- Ans = (2^n) - Sum{ct[x]}
- But, for some reason, unable to get exact ct[x]

*/

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

ull arr[m_max+1], F[2*m_max+1][2] = {0};

int main()
{
	ull n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		sf("%llu", &arr[i]);
		F[arr[i]][1]++;
	}
	
	for(int i = 0; i <= m_max; i++)
	{
		F[i][1] = (expon(2, F[i][1], MOD) + MOD - 1)%MOD;
	}
	for(int n = 0; n < n_max; n++)
	{
		for(int mask = 0; mask < (1<<n_max); mask++)
		{
			if((mask&(1<<n)) == 0)
				F[mask][n%2] = (F[mask][(n+1)%2]*(F[(mask^(1<<n))][(n+1)%2] + 1)%MOD)%MOD;
			else
				F[mask][n%2] = F[mask][(n+1)%2];
		}
	}
	ull ans = 0;
	for(int i = 1; i <= m_max; i++)
	{
		ans = (ans + F[i][(n_max+1)%2])%MOD;
	}
	//cout << ans << endl;
	//ans = (expon(2, n, MOD) + MOD - 1 + (MOD - ans))%MOD;
	cout << ans;
	return 0;
}
