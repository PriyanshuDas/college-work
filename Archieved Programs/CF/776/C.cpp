
#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 1000000
#define max_n 1000000

using namespace std;

int n, k;

vector<ll> A;
map <ll, vector <ll> > M;

int pos_binary_srch(vector <ll> *V, int val)
{
	int l = 0, r = V->size()-1;
	int m = (l+r)>>2;
	while(l <= r)
	{
		m = (l+r)>>2;
		if ((*V)[m] < val)
		{
			l = m+1;
			continue;
		}
		if((*V)[m] >= val)
		{
			r = m-1;
			continue;
		}
	}
	return V->size() - r - 1;
}

int main()
{
	cin >> n >> k;
	ll sum = 0;
	M[sum].pb(0);
	ll arr_sum[max_n+2];
	arr_sum[0] = 0;
	for(int i = 0; i < n; i++)
	{
		ll a;	sf("%lld", &a);
		sum += a;
		A.pb(a);
		M[sum].pb(i+1);
		arr_sum[i+1] = sum;
	}
	ll max_sm = 1000000000000000;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		ll p_k = 1;
		while(p_k <= max_sm)
		{
			//pf("[%lld]\n", p_k);
			auto it = M.find(p_k + arr_sum[i]);
			if(it != M.end())
			{
				int ex = pos_binary_srch(&(it->second), i+1);
				//pf("(%lld, %d, %lu)\t\t%d\n", p_k, i, it->second.size(), ex);
				ans += ex;
			}
			p_k *= k;
		}
	}
	cout << ans;
	return 0;
}
