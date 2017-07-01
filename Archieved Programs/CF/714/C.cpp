#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define n_max 530000

using namespace std;

int ct[n_max] = {0};

int conv_to_bin(ll n)
{
	vector <int> N;
	while(n > 0)
	{
		N.pb(n%10);
		n /= 10;
	}
	int ans = 0;
	for(int i = N.size() - 1; i >= 0; i--)
	{
		ans *= 2;
		if(N[i]%2 != 0)
			ans++;
	}
	return ans;
}

int conv_to_dec(string s)
{
	ll ans = 0;
	for(int i = 0; i < s.size(); i++)
	{
		ans *= 2;
		if(s[i] == '1')
			ans++;
	}
	return ans;
}

int main()
{
	int t;	cin >> t;
	for(int i = 0; i < t; i++)
	{
		char ci;
		cin >> ci;
		if(ci == '+')
		{
			ll tmp;	cin >> tmp;
			ct[conv_to_bin(tmp)]++;
		}
		if(ci == '-')
		{
			ll tmp;	cin >> tmp;
			ct[conv_to_bin(tmp)]--;
		}
		if(ci == '?')
		{
			string s;	cin >> s;
			ll ans = ct[conv_to_dec(s)];
			cout << ans << endl;
		}
	}
}
