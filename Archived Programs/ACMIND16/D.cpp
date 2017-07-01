/*	Prime Numbers Part I
	Includes :
(1)	Prime Generation (Sieve of Erastothenes)
(2) Prime Factorisation (No powers)

	Written by Priyanshu Das	*/

#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned ll
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 750001
#define lim_lg 20
#define MOD 1000000007

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <int> primes;

vector<int> Factors[limit];
int arr[limit+1];
vector<int> factr[limit+1];
vector<int> conn[limit+1];
int n;
map<int, int> num_pos;
vector<pair<int, int> > pr_pow;

void find_factors(int a_pos, int pos, int curr)
{
	vector <int> ans;
	if(pos == pr_pow.size())
	{
		return;
	}
	int nxt = curr;
	for(int i = 0; i <= pr_pow[pos].second; i++)
	{
		nxt = curr/(pr_pow[pos].first);
		auto it = num_pos.find(nxt);
		if(it == num_pos.end())
			find_factors(a_pos, pos+1, nxt);
		else
		{
			int p = it->second;
			for(int j = 0; j < conn[p].size(); j++)
			{
				conn[a_pos].pb(conn[p][j]);
			}
			break;
		}
	}
	return;
}

void factorise(int pos)
{
	int n = arr[pos];
	//pf("Factors for %d :\n", n);
	for(int j = 0; j < Factors[n].size(); j++)
	{
		int n2 = n;
		int ct = 0;
		while(n2%Factors[n][j] == 0)
		{
			n2 /= Factors[n][j];
			ct++;
		}
		//pf("%d\t%d\n", Factors[n][j], ct);
		pr_pow.pb(mp(Factors[n][j], ct));
	}
	find_factors(pos, 0, arr[pos]);
	conn[pos].pb(pos);
	pr_pow.clear();
	//pf("\n");
}

ull memo[limit+1] = {0};

ull dp(int pos)
{
	if(pos == -1)
		return 0;
	if(memo[pos] != -1)
		return memo[pos];
	ull ans = 1;
	//pf("@(%d)\n", pos);
	for(int i = 0; i < conn[pos].size(); i++)
	{
		if(conn[pos][i] != pos)
			ans = (ans + dp(conn[pos][i]))%MOD;
	}
	memo[pos] = ans;
	return memo[pos];
}
int main()
{
    not_prime[0] = 1;
    not_prime[1] = 1;
	for(int i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			primes.pb(i);
			for(ll j = i; j < limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				Factors[j].pb(i);
				not_prime[j] = 1;
			}
		}
	}
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		sf("%d", &n);
		num_pos.clear();
		for(int i = 0; i < n; i++)
		{
			conn[i].clear();
		}
		for(int i = 0; i < n; i++)
		{
			int tmp;	sf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		for(int i = 0; i < n; i++)
		{
			num_pos[arr[i]] = i;
		}
		for(int i = 0; i < n; i++)
		{
			factorise(i);
		}
		for(int i = 0; i < n; i++)
		{
			pf("Multiples for %d :\n", arr[i]);
			for(int j = 0; j < conn[i].size(); j++)
			{
				pf("%d\t", arr[conn[i][j]]);
			}
			pf("\n");
		}
		ull ans = 0;
		for(int i = 0; i < n; i++)
		{
			memo[i] = -1;
		}
		for(int i = n-1; i >= 0; i++)
		{
			//pf("Starting with arr[%d] == %d\n", i, arr[i]);
			ans = (ans + dp(i))%MOD;
		}
		pf("%llu\n", ans);
	}
	return 0;
}
