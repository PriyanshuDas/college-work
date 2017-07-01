//Problem J

/*Segment Trees

- Make Segment Tree for minimum in a range
- Have find query as min value, position
- Have update query as update(l, r, x) => all elements from l to r, reduced by x*/

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define mp make_pair
#define n_max 200001
#define max_inp 1000000001

using namespace std; 

int n;
ll val[n_max+1];
pair<ll, int> node[2*n_max + 1];
pair<int, int> range[2*n_max+1];
bool prop[2*n_max+1];
ll p_val[2*n_max+1];
int max_n = 0;

void make_tree(int n, int l, int r)
{
	if(l == r)
	{
		node[n] = mp(val[l], l);
		return;
	}
	int md = (l+r)/2;
	make_tree(2*n, l,md);
	make_tree(2*n+1,md+1,r);
	if(node[2*n].first < node[2*n+1].first)
		node[n] = node[2*n];
	else
		node[n] = node[2*n+1];
	max_n = max(max_n, n);
}

pair<ll, int> query(int n, int l, int r)
{
	if(prop[n] == 1)
	{
		node[n].first -= p_val[n];
		
		if(2*n <= max_n)
		{
			prop[2*n] = 1;
			p_val[2*n] += p_val[n];
		}
		
		if(2*n+1 <= max_n)
		{
			prop[2*n+1] = 1;
			p_val[2*n+1] += p_val[n];
		}
		
		prop[n] = 0;
		p_val[n] = 0;
	}
	if(range[n].first == l && range[n].second == r)
		return node[n];

	pair<ll, int> ans = mp(max_inp, l);
	if(2*n <= max_n && l <= range[2*n].second && r >= range[2*n].first)
	{
		pair<ll, int> l_ans = query(2*n, max(l, range[2*n].first), min(r, range[2*n].second));
		if(l_ans.first < ans.first)
			ans = l_ans;
	}
	if(2*n+1 <= max_n && l <= range[2*n+1].second && r >= range[2*n+1].first)
	{
		pair<ll, int> r_ans = query(2*n+1, max(l, range[2*n+1].first), min(r, range[2*n+1].second));
		if(r_ans.first < ans.first)
			ans = r_ans;
	}
	return ans;
}

ll ans(int l, int r)
{
	if(l > r)
		return 0;
	if(l == r)
		return val[l];
	pair<ll, int> mn = query(1, l, r);
	update(l, r, mn.first);
	int sp_pos = mn.second;
	int ans = mn + ans(l, sp_pos-1) + ans(sp_pos+1, r);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		sf("%lld", &val[i]);
	}
	make_tree(1, 0, n-1);
	return 0;
}
