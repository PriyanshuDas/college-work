#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi2 pair <ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>
#define loop(i, l, r) for(ll i = l; i < r; i++)
#define ins insert

using namespace std;

int main()
{
	string s;
	cin >> s;
	int x = 0, y = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'R')
			x++;
		if(s[i] == 'L')
			x--;
		if(s[i] == 'U')
			y++;
		if(s[i] == 'D')
			y--;
	}
	if((abs(x)+abs(y))%2 != 0)
	{
		cout << -1;
	}
	else
	{
		int ans = abs(x)+abs(y);
		ans = ans/2;
		cout << ans;
	}
	return 0;
}
