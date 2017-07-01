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
	ll a, b;	cin >> a >> b;
	int n = 0;
	while(a <= b)
	{
		n++;
		a *= 3;
		b *= 2;
	}
	cout << n;
	return 0;
}