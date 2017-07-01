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
		vector <int> A, B;
		for(int i = 0; i < N; i++)
		{
			int tmp;
			sf("%d", &tmp);
			A.pb(tmp);
		}
		for(int i = 0; i < N; i++)
		{
			int tmp;
			sf("%d", &tmp);
			B.pb(tmp);
		}
		ll ans_A = 0, ans_B = 0;
		for(int i = 0; i < N; i++)
		{
			if(i%2 == 0)
			{
				ans_B += B[i];
				ans_A += A[i];
			}
			else
			{
				ans_B += A[i];
				ans_A += B[i];
			}
		}
		pf("%lld\n", min(ans_A, ans_B));
	}
	return 0;
}