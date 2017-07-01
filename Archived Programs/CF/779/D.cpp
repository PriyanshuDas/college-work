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

using namespace std;

int n;
string s, t;
vector <int> natsya;

bool check (int pos)
{
	int p = 0;
	set <int> inv;
	for(int i = 0; i <= pos; i++)
	{
		inv.ins(natsya[i]);
	}
	for(int i = 0; i < s.size(); i++)
	{
		if(inv.find(i) == inv.end() && p < t.size() && s[i] == t[p])
		{
			p++;
		}
	}
	return (p == t.size());
}

int pos_binary_srch()
{
	int l = 0, r = n-1;
	int m = (l+r)/2;
	while(l <= r)
	{
		m = (l+r)/2;
		//pf("(%d, %d, %d)\n", l, m, r);
		//int tmp;
		//cin >> tmp;
		if (check(m))
		{
			l = m+1;
			continue;
		}
		else
		{
			r = m-1;
			continue;
		}
	}
	return l;
}


int main()
{
	cin >> s >> t;
	n = s.size();
	for(int i = 0; i < s.size(); i++)
	{
		int tmp;	sf("%d", &tmp);
		natsya.pb(tmp-1);
	}
	int ans = pos_binary_srch();
	cout << ans;
	return 0;
}