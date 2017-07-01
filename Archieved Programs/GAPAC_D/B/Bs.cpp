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
int arr[101][101] = {0};
int an_ar[101][101] = {0};
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

ll max_ct = 0;

ll dp(int r, int c)
{
	if(c == C)
	{
		int ct = 0;
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				if(arr[i][j] == 1)
					ct++;
				if(arr[i][j] == 1 && check(i, j) == 1)
				{
					return 0;
				}
			}
		}
		if(ct > max_ct)
		{
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
					an_ar[i][j] = arr[i][j];
			}
			max_ct = ct;
		}
		return ct;
	}
	ll ans = 0;
	arr[r][c] = 0;
	ans = max(ans, dp((r+1)%R, c + (r+1)/R));
	arr[r][c] = 1;
	ans = max(ans, dp((r+1)%R, c + (r+1)/R));
	return ans;
}

int main()
{
	int T;	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> R >> C;
		memset(arr, 0, sizeof(arr));
		memset(an_ar, 0, sizeof(an_ar));
		max_ct = 0;
		ll ans = dp(0, 0);
		pf("Case #%d: %lld\n", i+1, ans);
		for(int j = 0; j < R; j++)
		{
			for(int k = 0; k < C; k++)
				cout << an_ar[j][k] << ' ';
			pf("\n");
		}
	}
	return 0;
}
