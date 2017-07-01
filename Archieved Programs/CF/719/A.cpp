#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>
#define loop(i, l, r) for(int i = l; i < r; i++)

using namespace std;

int main()
{
	int n;	cin >> n;
	vector<int> V;
	for(int i = 0; i < n; i++)
	{
		int tmp;	cin >> tmp;
		V.pb(tmp);
	}
	if((V.size() > 1 && ((V[n-1] > V[n-2] && V[n-1] != 15))) || V[n-1] == 0)
	{
		cout << "UP";
	}
	else if((V.size() > 1 && ((V[n-1] < V[n-2] && V[n-1] != 0))) || V[n-1] == 15)
	{
		cout << "DOWN";
	}
	else
	{
		cout << -1;
	}
	return 0;
}
