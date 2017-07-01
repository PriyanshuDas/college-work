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
	int X, Y;	cin >> X >> Y;
	vector <int> tri;
	tri.pb(X);
	tri.pb(X);
	tri.pb(X);
	int ct = 0;
	while(tri[2] != Y || tri[1] != Y)
	{
		if(tri[0] != Y)
		{
			pf("(%d, %d, %d)\n", tri[0], tri[1], tri[2]);
			tri[0] = Y;
			ct++;
		}
		if(tri[1] != Y && tri[1] >= tri[2])
		{
			pf("(%d, %d, %d)\n", tri[0], tri[1], tri[2]);
			tri[1] = max(Y, tri[2] - tri[0] + 1);
			ct++;
		}
		if(tri[2] != Y && tri[2] >= tri[1])
		{
			pf("(%d, %d, %d)\n", tri[0], tri[1], tri[2]);
			ct++;
			tri[2] = max(Y, tri[1] - tri[0] + 1);
		}
	}
	cout << ct;
	return 0;
}
