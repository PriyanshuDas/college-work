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

int main()
{
	int n, k;	cin >> n >> k;
	int days = 0;
	int c_p = 0;
	for(int i = 0; i < n; i++)
	{
		int w;	sf("%d", &w);
		while(w > 0)
		{
			w -= k;
			c_p = (c_p+1)%2;
			if(c_p == 1)
				days++;
		}
	}
	cout << days;
	return 0;
}