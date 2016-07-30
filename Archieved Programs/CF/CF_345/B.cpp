#include <bits/stdc++.h>

#define ll long long int
#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define loop(i, l, r) for(auto i = l; i != r; i++)
#define ins insert

using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	int ct[1001] = {0};
	loop(i, 0, n)
	{
		int tmp;
		sf("%d",&tmp);
		ct[tmp]++;
	}
	for(int i = 0; i < 1000; i++)
	{
		int curr_ct = 0;
		for(int j = 0; j < 1000; j++)
		{
			if(ct[j])
			{
				curr_ct++;
				ct[j]--;
			}
		}
		if(curr_ct > 1)
			ans += curr_ct-1;
		else
			break;
	}
	cout << ans;
	return 0;
}
