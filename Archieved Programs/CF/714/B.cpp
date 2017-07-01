#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int n;	cin >> n;
	vector<ll> V;
	ll mn= 1000000001, mx = 0;
	for(int i = 0; i < n; i++)
	{
		ll tmp;	sf("%lld", &tmp);
		V.pb(tmp);
		mn = min(mn, tmp);
		mx = max(mx, tmp);
	}
	ll x = (mn + mx)/2;
	//cout << mn << ' ' << x << ' ' << mx << endl;
	/*if((mn+mx)%2 != 0 && n > 2)
	{
		cout << "NO";
		return 0;
	}*/
	int flag = 0, flag2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(V[i] != mn && V[i] != mx && V[i] != x)
			flag = 1;
		if(V[i] == x && V[i] != mn && V[i] != mx)
			flag2 = 1;
	}
	if(flag == 0)
	{
		if(flag2 == 1 && (mn+mx)%2 != 0)
		{
			cout << "NO";
			return 0;
		}
		cout << "YES";
	}
	else
		cout << "NO";
	return 0;
}
