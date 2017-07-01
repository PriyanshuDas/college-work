#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define fi first
#define se second

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N;	cin >> N;
		vector <ll> V;
		for(int i = 0; i < N; i++)
		{
			ll tmp;	sf("%lld", &tmp);
			V.pb(tmp);
		}
		sort(V.begin(), V.end());
		ll curr = V[0];
		if(V[V.size()-1] != V[V.size()-2]+1)
			curr = V[V.size()-1];
		for(int i = 1; i < V.size(); i++)
		{
			if(V[i] == V[i-1])
			{
				curr = V[i];
				break;
			}
		}
		pf("%lld\n", curr);
	}
	return 0;
}