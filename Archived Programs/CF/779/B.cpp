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
	ll n;	cin >> n;
	ll k;	cin >> k;
	ll curr = n;
	ll m = 1;
	int ct = 0;
	for(ll i = 0; i < k; i++)
	{
		m *= 10;
		int tmp = curr%m;
		//cout << curr << '\t' << tmp << endl;
		if(tmp != 0)
		{
			curr = curr - tmp;
			curr /= 10;
			i--;
			m /= 10;
			ct++;
		}
	}
	if(n == 0)
		ct = 0;
	if(curr == 0 && n != 0)
	{
		ct = 0;
		while(n > 0)
		{
			ct++;
			n /= 10;
			//cout << n << '\t' << ct << endl;
		}
		ct--;
	}
	cout << ct;
	return 0;
}