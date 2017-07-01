#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define ull unsigned ll
#define inf 9999999999999
#define fi first
#define se second
#define mp make_pair

using namespace std;

int main()
{
	int T, t = 0;	cin >> T;
	while(T--)
	{
		t++;
		ull N, K;
		sf("%llu%llu", &N, &K);
		ull c = 1;
		while(K > c)
		{
			K -= c;
			N -= c;
			c *= 2;
		}
		ull div = N/c;
		ull ext = N%c;
		if(K <= ext)
			div++;
		ull left = div/2;
		if(div%2 == 0)
			left--;
		ull right = div - left - 1;
		ull l = max(left, right);
		ull r = min(left, right);
		pf("Case #%d: %llu %llu\n", t, l, r);
	}
	return 0;
}