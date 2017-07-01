#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned ll
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)
#define n_size 4001
#define MOD 1000000007

using namespace std;

map <map <char, int>, int > M;
string S;
ull memo[4001];

ull word(int s, int n)
{
	int ans = 0;
	map<char, int> t_m;
	for(int i = s; i <= n; i++)
	{
		//cout << S[i];
		t_m[S[i]]++;
	}
	//cout << endl;
	map <map <char, int>, int >::iterator it = M.find(t_m);
	if(it == M.end())
		return 0;
	//cout << it->second << endl << endl;
	return it->second;
}

ull dp(int pos)
{
	if(memo[pos] != -1)
		return memo[pos];
	if(pos == S.size())
		return 1;
	ull ans = 0;
	for(int i = 0; i <= 20 && (pos+i) < S.size(); i++)
	{
		ull tmp = word(pos, pos+i);
		//pf("@(%d, %llu)\n", pos, tmp);
		if(tmp != 0)
		{
			ans = (ans + tmp*dp(pos+i+1)%MOD)%MOD;
		}
	}
	memo[pos] = ans;
	//f("@(%d)\t%llu\n", pos, memo[pos]);
	return memo[pos];
}
int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int V, S_ct;		//size of vocab, no of strings
		cin >> V >> S_ct;
		M.clear();
		for(int i = 0; i < V; i++)
		{
			string s;	cin >> s;
			map <char, int> tmp_m;
			for(int i = 0; i < s.size(); i++)
			{
				tmp_m[s[i]]++;
			}
			M[tmp_m]++;
		}
		vector<ll> Ans;
		for(int i = 0; i < S_ct; i++)
		{
			memset(memo, -1, sizeof(memo));
			cin >> S;
			ull ans = dp(0);
			Ans.pb(ans);
		}
		pf("Case #%d: ", t);
		for(int i = 0; i < Ans.size(); i++)
			pf("%llu ", Ans[i]);
		pf("\n");
	}
	return 0;
}
