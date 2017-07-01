#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >

using namespace std;

int main()
{
	ll n, b, d;	cin >> n >> b >> d;
	ll w = 0, ct = 0;
	for(int i = 0; i < n; i++)
	{
		ll tmp;		cin >> tmp;
		if(tmp <= b)
			w += tmp;
		while(w > d)
		{
			ct++;
			w = 0;
		}
	}
	cout << ct;
	return 0;
}
