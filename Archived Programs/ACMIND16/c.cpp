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

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int d;
		sf("%d", &d);
		d = d%9;
		int s = d+1;
		if(s == 10)
			s = 1;
		cout << s << endl;
	}
	return 0;
}
