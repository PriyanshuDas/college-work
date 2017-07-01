#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define ull unsigned ll

using namespace std;

bool check (ull N)
{
	ull prev = 9;
	//pf("%lld\n", N);
	while(N > 0)
	{
		ull c = N%10;
		if(c <= prev)
		{
			prev = c;
			N /= 10;
			continue;
		}
		else
			return false;
	}
	return true;
}

void modify(ull *N, int dig)
{
	ull ten = 1;
	for (int i = 0; i < dig; ++i)
		ten *= 10;
	*N -= ten*10;
	ull t = ((*N)/ten)%10;
	*N -= t*ten;
	*N += 9*ten;
}

int main()
{
	int T;	cin >> T;
	int t = 0;
	while(T--)
	{
		t++;
		ull N;	cin >> N;
		int dig = 0;
		while(!check(N))
		{
			modify(&N, dig);
			dig++;
		}
		pf("Case #%d: %llu\n", t, N);
	}
}