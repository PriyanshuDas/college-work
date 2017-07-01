#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)

using namespace std;


int N, M, L;
vector<ll> A;
vector<ll> B;
vector<ll> P;
int pow_2[30];

ll dp(int pos, int c_num)
{
	if(pos == N)
	{
		ll Ai = 0, Bi = 0, Pi = 0;
		int mask = 0;
		for(int i = 0; i < N; i++)
		{
			if(((1<<i)&c_num) != 0)
			{
				Ai += A[i];
				Bi += B[i];
				Pi += P[i];
			}
		}
		//cout << Pi << endl;
		if(Ai <= L && Bi >= L)
			return Pi;
		else
			return M+1;
	}
	ll a1 = dp(pos+1, c_num + pow_2[pos]);
	ll a2 = dp(pos+1, c_num);
	ll ans = M+1;
	if(a1 >= 0)
		ans = a1;
	if(a2 >= 0)
		ans = min(ans, a2);
	return ans;
}

int main()
{
	int T;	cin >> T;
	ll p2 = 1;
	for(int i = 0; i < 32; i++)
	{
		pow_2[i] = p2;
		p2 *= 2;
	}
	for(int t = 1; t <= T; t++)
	{
		cin >> N >> M >> L;
		A.clear();	B.clear();	P.clear();
		for(int i = 0; i < N; i++)
		{
			ll Ai, Bi, Pi;
			sf("%lld%lld%lld", &Ai, &Bi, &Pi);
			A.pb(Ai);	B.pb(Bi);	P.pb(Pi);
		}
		ll ans = dp(0, 0);
		pf("Case #%d: ", t);
		if(ans > M)
		{
			pf("IMPOSSIBLE\n");
		}
		else
		{
			pf("%lld\n", ans);
		}
	}
	return 0;
}
