#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define fi first
#define se second
#define mp make_pair
#define pi2 pair <ll, ll>
#define ull unsigned ll

using namespace std;

map<pair<vector <int>, pair<int, int> >, int > memo;
//(taken, (pos, flag))

vector <int> inp;
int a[10] = {0};

int dp(int pos, vector <int> *ma, int lim)
{
	vector <int> mask = *ma;
	pair<vector<int>, pair<int, int> > ans = mp(mask, mp(pos, lim));
	if(memo.find(ans) != memo.end())
		return memo[ans];
	if(pos == inp.size())
	{
		bool flag = 0;
		for(int i = 0; i <= 9; i++)
			if(mask[i] == a[i])
				flag = 1;
		if(flag)
			return 0;
		return 1;
	}
	ll tmp = 0;
	for(int i = 0; i <= 9; i++)
	{
		// here lies the bug
		if(i == 0)
		{
			if(lim == 2)
				tmp += dp(pos+1, ma, 2);
			else if(lim == 1 && inp[pos] == 0)
			{
				(*ma)[i]++;
				tmp += dp(pos+1, ma, 1);
				(*ma)[i]--;
			}
			else if(lim == 1 && pos == 0)
			{
				tmp += dp(pos+1, ma, 2);
			}
			else if(lim == 1 && inp[pos] > 0)
			{
				(*ma)[i]++;
				tmp += dp(pos+1, ma, 0);
				(*ma)[i]--;
			}
			else if (lim == 0)
			{
				(*ma)[i]++;
				tmp += dp(pos+1, ma, 0);
				(*ma)[i]--;
			}
			continue;
		}
		(*ma)[i]++;
		if(lim == 1 && i == inp[pos])
		{
			tmp += dp(pos+1, ma, 1);
			(*ma)[i]--;
			break;
		}
		else if(lim != 1 || i < inp[pos])
			tmp += dp(pos+1, ma, 0);
		(*ma)[i]--;
	}
	memo[ans] = tmp;
	return memo[ans];
}

/* Problem : leading 0s!!!*/

int main()
{
	int T;	cin >> T;
	while(T--)
	{
		ll L, R;	sf("%lld%lld", &L, &R);
		for(int i = 0; i <= 9; i++)
			sf("%d", &a[i]);

		memo.clear();
		inp.clear();
		L--;
		ll L1 = L, R1 = R;
		while(L > 0)
		{
			inp.pb(L%10);
			L /= 10;
		}

		for(int i = 0; i < inp.size()/2; i++)
			swap(inp[i], inp[inp.size()-1-i]);
		
		vector <int> mt;
		for(int i = 0; i <= 9; i++)
			mt.pb(0);
		ll l_ans = dp(0, &mt, 1);

		memo.clear();
		inp.clear();
		while(R > 0)
		{
			inp.pb(R%10);
			R /= 10;
		}
		
		for(int i = 0; i < inp.size()/2; i++)
			swap(inp[i], inp[inp.size()-1-i]);

		ll r_ans = dp(0, &mt, 1);
		//pf("(%lld\t%lld)\t(%lld\t%lld)\n", L1, l_ans, R1, r_ans);
		ll ans = r_ans - l_ans;
		pf("%lld\n", ans);
	}
	return 0;
}