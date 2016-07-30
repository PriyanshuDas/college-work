#include <bits/stdc++.h>

#define ll long long int
#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define loop(i, l, r) for(auto i = l; i != r; i++)
#define ins insert

using namespace std;

int main()
{							// a secs to swipe b to rotate 1 sec to see
	int n, a, b, T;
	cin >> n >> a >> b >> T;
	ll ans = 0;
	int cost[500001] = {0};
	string s;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'w')
			cost[i] = b + 1;
		else
			cost[i] = 1;
	}
	int count_st = 1, count_rv = 0, pos_st = 1, pos_rv = n-1;
	
	ll time_st = cost[0], time_rv = 0;

	if(time_st > T)
		count_st = 0;
		
	map<ll, int> no_p_rev;
	
	while(pos_rv > 0 && time_rv < T)
	{
		time_rv += a;
		time_rv += cost[pos_rv];
		if(time_rv <= T)
		{
			pos_rv--;
			count_rv++;
			no_p_rev[time_rv] = count_rv;
			//pf("Time : %lld\t at %d\n", time_rv, pos_rv);
		}
	}
	while(pos_st < n && time_st < T)
	{
		time_st += a;
		time_st += cost[pos_st];
		if(time_st <= T)
		{
			pos_st++;
			count_st++;
			ll t_beg = (count_st - 1)*a;
			ll t_left = T - (time_st + t_beg);
			ll ct_r = no_p_rev.lower_bound(t_left)->second;
			ans = max(ans, ct_r + count_st);
		}
	}
	if(ans > 0)
		ans --;
	cout << ans;	
	
	return 0;
}	
