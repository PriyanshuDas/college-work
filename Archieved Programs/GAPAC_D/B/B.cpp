#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)

using namespace std;
int arr[105][105] = {0};
int R, C;

bool check(int r, int c)
{
	int r_flag = 1, c_flag = 1;
	if(r == 0 || r == R-1 || (arr[r-1][c] == 0 || arr[r+1][c] == 0))
		r_flag = 0;
	if(c == 0 || c == C-1 || (arr[r][c-1] == 0 || arr[r][c+1] == 0))
		c_flag = 0;
	if(r_flag == 1 || c_flag == 1)
		return 1;
	return 0;
}

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> R >> C;
		memset(arr, 0, sizeof(arr));
		int ct = 0;
		int pat[] = {0, 1, 1};
		ll ans = 0;
		for(int k = 0; k < 2; k++)
		{
			ll ans1 = 0;
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					ans1 += pat[(i+j+k)%3];
				}
			}
			ans = max(ans, ans1);
		}
		for(int k = 0; k < 2; k++)
		{
			ll ans1 = 0;
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					ans1 += pat[(i-j+k)%3];
				}
			}
			ans = max(ans, ans1);
		}
		for(int k = 0; k < 2; k++)
		{
			ll ans1 = 0;
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
					ans1 += pat[(j-i+k)%3];
			}
			ans = max(ans, ans1);
		}
		pf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
