#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define ull unsigned ll
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		vector <int> A, A_, B;
		int N;	sf("%d", &N);
		int m1 = (1<<16)-1;
		int m2 = (-1)^m1;
		for(int n = 0; n < N; n++)
		{
			int tmp;	sf("%d", &tmp);
			int a = tmp&m1;
			int b = tmp&(m2);
			b = b>>16;
			A.pb(a);	B.pb(b);
		}
		pf("Case %d:\n", t+1);
		for(int n= 0; n < N; n++)
		{
			pf("%d ", A[n]);
		}
		pf("\n");
		for(int n= 0; n < N; n++)
		{
			pf("%d ", B[n]);
		}
		pf("\n");
	}
	return 0;
}
