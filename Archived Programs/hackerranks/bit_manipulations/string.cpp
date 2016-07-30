#include <bits/stdc++.h>

#define pb push_back
#define pf printf
#define ll long long int
#define MOD 1000000007

using namespace std;

ll Perm[1001];
ll Comb[1001][1001];
ll pow_2[1001];

ll inverse_mod(ll N);

void pow()
{
	pow_2[0] = 1;
	for (int i = 1; i < 1001; i++)
	{
		pow_2[i] = (pow_2[i-1]*2)%MOD;
	}
}
ll permute(int N)
{
	if(Perm[N])
		return Perm[N];
	if(N == 1 || N == 0)
		return 1;
	Perm[N] = (N*permute(N-1))%MOD;
	return Perm[N];
}

ll combin(int N, int R)
{
	if(Comb[N][R])
		return Comb[N][R];
	ll num = permute(N);
	ll den = (permute(N-R)*permute(R))%MOD;
	ll ans = (num*inverse_mod(den))%MOD;
	if(ans < 0)
		ans = MOD + ans;
	Comb[N][R] = ans;
	return Comb[N][R];
}

vector<ll> Ext_Euclid(ll a, ll b)
{
	if(b == 0)
	{
		vector <ll> ans;
		ans.pb(a);ans.pb(1); ans.pb(0);
		return ans;
	}
	vector <ll> orig = Ext_Euclid(b, a%b);
	vector <ll> ans;
	ans.pb(orig[0]);
	ans.pb(orig[2]);
	ans.pb(orig[1] - (a/b)*orig[2]);
	return ans;
}

ll inverse_mod(ll N)
{
	vector <ll> euclids_grail = Ext_Euclid(N, MOD);
	return (euclids_grail[1]%MOD);
}

int main()
{
	Perm[1000] = permute(1000);
	pow();
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		ll N, K;
		ll wrong_ways = 0;
		scanf("%lld%lld", &N,&K);
		//cout << "inverse mod of N is" << inverse_mod(N) << endl;
		string S;
		cin >> S;
		ll total = 0;
		for(int i = 0; i <= K; i++)
		{
			total += combin(N, i)%MOD;
		}
		if(N%2)
		{
			int ct[2] = {0};
			for(int i = 0; i < N; i++)
			{
				ct[S[i] - '0']++;
			}
			if(ct[0] <= K)
				wrong_ways++;
			if(ct[1] <= K)
				wrong_ways++;
		}
		else
		{
			string s1 = S.substr(0, S.size()/2);
			string s2 = S.substr(S.size()/2, S.size()/2);
			int d = 0;
			//cout << "Part 1 - " << s1<< endl;
			//cout << "Part 2 - " << s2 << endl;
			for(int i = 0; i < N/2; i++)
			{
				if(s1[i] != s2[i])
					d++;
			}
			//cout << "D is " << d << endl;
			if(d > K)
				wrong_ways = 0;
			else if (K > 0)
			{
				wrong_ways = pow_2[d];
				//cout << wrong_ways << endl;
				ll tmp = 1;
				int n_0 = N/2 - d;
			//cout <<"N_0 is "<<n_0<<"\tLimit is - " << (K-d)/2 << endl;
				for(int i = 1; i <= (K-d)/2 && n_0; i++)
					tmp += combin(n_0, i)%MOD;
				wrong_ways *= tmp;
			}
		}
		ll ans = (total - wrong_ways) % MOD;
		//pf("Total Ways - %lld\tWrong Ways - %lld\n", total, wrong_ways);
		if(ans < 0)
			ans += MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
