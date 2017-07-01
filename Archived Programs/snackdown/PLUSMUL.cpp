#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define n_max 1000006

using namespace std;

ll MOD = 1000000007;

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
ull inverse_mod(ll n)				//find inverse mod of a number
{
	ll m = MOD;
	vector <ll> temp = Ext_Euclid(n, m);
	while(temp[0] < 0)	temp[0] += m;
	return (ull)temp[0];
}

ull pow_2[n_max+1];

void precalc()
{
	pow_2[0] = 1;
	for(int i = 1; i < n_max+1; i++)
		pow_2[i] = (pow_2[i-1]*2)%MOD;
	
	//pf("Power_2[4] == %llu\n", pow_2[4]);
	return;
}

int main()
{
	precalc();
	int T;	cin >> T;
	while(T--)
	{
		int N;	sf("%d", &N);
		vector <ull> inp;
		for(int n = 0; n < N; n++)
		{
			ull tmp;	sf("%llu", &tmp);
			inp.pb(tmp);
		}
		if(N == 1)
		{
			pf("%llu\n", inp[0]);
			continue;
		}

		ull ans = (pow_2[N-2]*inp[N-1])%MOD;
		ull prev_ans = ans;
		//pf("N == %d\n", N);
		for(int i = N-2; i > 0; i--)
		{
			ull tmp = (prev_ans*inverse_mod(2))%MOD;
			tmp = ((tmp*inp[i])%MOD + (pow_2[N-3]*inp[i])%MOD)%MOD;
			//pf("@(%d\t%lld)\tPrev : %llu\tCurr : %llu\n", i, inp[i], prev_ans, tmp);
			prev_ans = tmp;
			ans = (ans + tmp)%MOD;
		}

		ull tmp = (prev_ans)%MOD;
		tmp = ((tmp*inp[0])%MOD + (pow_2[N-2]*inp[0])%MOD)%MOD;
	//	pf("@(%d\t%lld)\tPrev : %llu\tCurr : %llu\n", 0, inp[0], prev_ans, tmp);
		prev_ans = tmp;
		ans = (ans + tmp)%MOD;
		pf("%llu\n", ans);
	}
	return 0;
}