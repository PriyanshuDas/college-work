#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<long long int, long long int>

using namespace std;

int main()
{
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	ll net = b-c, ct = 0;
	if(net >= a)
	{
		ct = n/a;
		cout << ct;
		return 0;
	}
	ll n2 = n-b;
	ct += n2/net;
	n2 = b + n2%net;
	ll ct2 = ct;
	ct2 += n2/a;
	while(n2 >= b)
	{
		ct++;
		n2 = n2 - b + c;
	}
	if(n2 >= a)
		ct += n2/a;
	ct = max(ct2, ct);
	cout << ct;
	return 0;
}
