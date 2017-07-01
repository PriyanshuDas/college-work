#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert
#define inf 99999999999999

using namespace std;

vector <ll> arr;
vector <ll> abs_arr;
vector <ll> inp_arr[2];
vector <ll> ans_arr[2];

ll find_max(int typ)
{
	vector <ll> c_ans;
	for(int i = 0; i < inp_arr[typ].size(); i++)
	{
		if(i == 0 || (i%2==0 && c_ans[i-1] < 0))
		{
			c_ans.pb(inp_arr[typ][i]);
		}
		else
		{
			ll add = inp_arr[typ][i];
			c_ans.pb(c_ans[i-1]+add);
		}
	}
	ll max_ans = -1*inf;
	//pf("Type %d\n", typ);
	for(int i = 0; i < c_ans.size(); i++)
	{
		//pf("%lld ", c_ans[i]);
		max_ans = max(max_ans, c_ans[i]);
	}
	//pf("\n");
	return max_ans;
}

int main()
{
	int n;	cin >> n;
	
	for(int i =0; i < n; i++)
	{
		ll tmp;	sf("%lld", &tmp);
		arr.pb(tmp);
	}
	for(int i = 1; i < n; i++)
	{
		abs_arr.pb(abs(arr[i]-arr[i-1]));
	}
	int c_s = 1;
	for(int j = 0; j < abs_arr.size(); j++)
	{
		if(j > 0)
			inp_arr[1].pb(abs_arr[j]*(c_s*-1));
		inp_arr[0].pb(abs_arr[j]*(c_s));
		c_s = (c_s*-1);
	}
	/*for(int j = 0; j < 2; j++)
	{
		pf("@ %d\n\n", j);
		for(int i = 0; i < inp_arr[j].size(); i++)
		{
			pf("%lld ", inp_arr[j][i]);
		}
		pf("\n\n");
	}*/
	ll ans = max(find_max(0), find_max(1));
	cout << ans;
	return 0;
}