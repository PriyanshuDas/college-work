#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >
#define max_n 100001

using namespace std;

int main()
{
	ll n, k;	cin >> n >> k;
	vector <ll> pts;
	for(int i = 0; i < n; i++)
	{
		ll tmp;	cin >> tmp;
		pts.pb(tmp);
	}
	sort(pts.begin(), pts.end());
	ll s1 = 0, s2 = 0;
	for(int i = 1; i < n-1; i++)
	{
		s1 += pts[i] - pts[i-1];
	}
	for(int i = 2; i < n; i++)
	{
		s2 += pts[i] - pts[i-1];
	}
	ll s_1_f = 0;
	if(pts.size() > 0)
		s_1_f = s1 + abs(k - pts[0]);
	
	ll s_1_b = 0; 
	if(n > 1)
	s_1_b = s1 + abs(k - pts[n-2]);
	
	ll s_2_f = 0;
	if(n > 0)
		s_2_f =  s2 + abs(k - pts[1]);
	ll s_2_b = 0;
	if(n > 0)
		s_2_b = s2 + abs(k - pts[n-1]);
		
	ll ans = min(min(s_1_f, s_1_b), min(s_2_f, s_2_b));
	cout << ans;
	return 0;
}
