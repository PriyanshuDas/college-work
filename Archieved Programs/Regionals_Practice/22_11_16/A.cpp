#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back

using namespace std;

int main()
{
	int N;	cin >> N;
	for(int n = 0; n < N; n++)
	{
		vector<int> C, P;
		int K;	cin >> K;
		for(int i = 0; i < K; i++)
		{
			int tmp;
			sf("%d", &tmp);
			C.pb(tmp);
		}
		
		for(int i = 0; i < K; i++)
		{
			int tmp;
			sf("%d", &tmp);
			P.pb(tmp);
		}
		
		sort(C.begin(), C.end());
		sort(P.begin(), P.end());
		
		ll ans = 0;
		for(int i = 0; i < C.size(); i++)
		{
			ans += abs(C[i]-P[i]);
		}
		pf("Case %d: %lld\n", n+1, ans);
	}
}
