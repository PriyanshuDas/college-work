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

int mn, mx, mean, med;
int arr[15] = {0};
int cur_sz = 0;
int flag = 0;

void fill(int pos)
{
	/*pf("@%d", pos);
	int tmp;
	sf("%d", &tmp);*/
	if(pos == 0)
	{
		arr[pos] = mn;
		fill(pos+1);
	}
	else if(pos == cur_sz-1)
	{
		arr[pos] = mx;

		int c_mean = 0, c_med = 0;
		for(int i = 0; i < cur_sz; i++)
			c_mean += arr[i];

		for(int i = 0; i <= pos; i++)
		{
			pf("%d ", arr[i]);
		}
		pf("\n");
		if(c_mean%cur_sz == 0 && c_mean/cur_sz == mean)
		{
			if(cur_sz%2 == 1 && arr[cur_sz/2] == med)
			{
				flag = 1;
				return;
			}
			else if(cur_sz%2 == 0 && (arr[cur_sz/2 - 1] + arr[cur_sz/2])%2 == 0 && (arr[cur_sz/2 - 1] + arr[cur_sz/2])/2 == med)
			{
				flag = 1;
				return;
			}
			return;
		}
		return;
	}
	else if(cur_sz%2 != 0 && pos == cur_sz/2)
	{
		arr[pos] = med;
	}
	else if(pos < cur_sz/2)
	{
		for(int i = mn; i <= med; i++)
		{
			arr[pos] = i;
			fill(pos+1);
		}
	}
	else if(pos >= cur_sz/2)
	{
		for(int i = med; i <= mx; i++)
		{
			arr[pos] = i;
			fill(pos+1);
		}
	}
}

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		sf("%d%d%d%d", &mn, &mx, &mean, &med);
		for(cur_sz = 1; cur_sz < 14; cur_sz++)
		{
			flag = 0;
			fill(0);
			if(flag == 1)
			{
				pf("Case #%d: %d\n", t, cur_sz);
				break;
			}
		}
		if(flag == 0)
		{
			pf("Case #%d: IMPOSSIBLE\n", t);
		}

	}
	return 0;
}