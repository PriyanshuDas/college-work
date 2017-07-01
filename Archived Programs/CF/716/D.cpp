#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back
#define ins insert
#define loop(i,l,r) for(int i = l; i < r; i++)
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll>
#define pi4 pair<pi2, pi2>

using namespace std;

int main()
{
	ll n;	cin >> n;
	ll k = 1, c1 = 2, c2 = 0;
	for(ll k = 2;  k <= n+1; k++)
	{
		c2 = k*k*(k-1) - c1;
		cout << c2 << endl;
		c1 = k-1;
	}
	return 0;
}
