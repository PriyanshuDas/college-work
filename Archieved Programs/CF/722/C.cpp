#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define pi2 pair<ll, ll>
#define pi4 pair<pi2, pi2 >
#define pi3 pair<ll, pi2 >
#define ull unsigned long long int
#define n_max 100000

using namespace std;

map<int, ll> S;
multiset <pair<ll, int> > M;
int par[n_max+1];
vector <int> arr;
int n;

void new_seg(int x)	//S[seg] is value of seg. M stores (seg_val, seg_id)
{
	par[x] = x;
	M.ins(mp(arr[x], x));
	S[x] = arr[x];
}

void add(int p, int s)
{
	par[p] = s;
	ll val_s = S[s];
	S[s] += arr[p];
	M.erase(mp(val_s, s));
	M.ins(mp(val_s+arr[p], s));
}

int find_par(int x)
{
	if(par[x] == -1)
		return -1;
	if(par[x] == x)
	{
		return x;
	}
	par[x] = find_par(par[x]);
	return par[x];
}

void Union(int a, int b)
{
	int p_a = find_par(a);
	int p_b = find_par(b);
	ll v_a = S[p_a];	ll v_b = S[p_b];
	if(v_a < v_b)
	{
		S.erase(p_a);
		S[p_b] += v_a;
		par[p_a] = p_b;
		M.erase(mp(v_a, p_a));
		M.erase(mp(v_b, p_b));
		M.insert(mp(v_a+v_b, p_b));
	}
	else
	{
		S.erase(p_b);
		S[p_a] += v_b;
		par[p_b] = p_a;
		M.erase(mp(v_a, p_a));
		M.erase(mp(v_b, p_b));
		M.insert(mp(v_a+v_b, p_a));
	}
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		arr.pb(tmp);
	}
	vector <int> des;
	vector<ll> seg_sum;
	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		tmp--;
		des.pb(tmp);
	}
	int seg_ct = 0;
	vector<ll> Ans;
	memset(par, -1, sizeof(par));
	M.ins(mp(0, -1));
	for(int i = n-1; i >= 0; i--)
	{
		int p = des[i], f = 0;
		pair <ll, int> tmp = *(M.rbegin());
		ll ans = tmp.first;
		Ans.pb(ans);
		if(p > 0 && find_par(p-1) != -1)
		{
			f++;
			add(p, par[p-1]);
		}
		if(p < n-1 && find_par(p+1) != -1)
		{
			f++;
			if(f == 1)
				add(p, par[p+1]);
		}
		if(f == 2)
		{
			Union(p-1, p+1);
		}
		if(f == 0)
		{
			new_seg(p);
		}
	}
	for(int i = Ans.size()-1; i >= 0; i--)
	{
		pf("%lld\n", Ans[i]);
	}
	return 0;
}
