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
	int n;	cin >> n;
	int ct = 0, ans = 0;
	set <int> sock;
	for(int i = 0; i < 2*n; i++)
	{
		int tmp;
		sf("%d", &tmp);
		if(sock.find(tmp) == sock.end())
		{
			ct++;
			sock.insert(tmp);
		}
		else
		{
			ans = max(ans, ct);
			ct--;
			sock.erase(tmp);
		}
	}
	cout << ans;
	return 0;
}
