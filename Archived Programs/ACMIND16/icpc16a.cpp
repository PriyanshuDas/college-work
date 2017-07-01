#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define ull unsigned ll
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2>
#define pi 3.14159265359

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int x1, y1, x2, y2;
		sf("%d%d%d%d", &x1, &y1, &x2, &y2);
		string ans = "sad";
		if(y1 == y2)
		{
			if(x1 < x2)
			{
				ans = "right";
			}
			if(x1 > x2)
				ans = "left";
		}
		if(x1 == x2)
		{
			if(y1 < y2)
				ans = "up";
			if(y2 < y1)
				ans = "down";
		}
		cout << ans << endl;
	}
	return 0;
}
