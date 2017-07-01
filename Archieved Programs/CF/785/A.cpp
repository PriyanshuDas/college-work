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
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	map <string, int> M;
	M["Tetrahedron"] = 4;
	M["Cube"] = 6;
	M["Octahedron"] = 8;
	M["Dodecahedron"] = 12;
	M["Icosahedron"] = 20;
	ll ans = 0;
	int n = 0;
	cin >> n;
	while(n--)
	{
		string tmp;	cin >> tmp;
		ans += M[tmp];
	}
	cout << ans;
	return 0;
}