#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define ull unsigned ll
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int n;	sf("%d", &n);
		int ct_0 = 0, ct_1_neg = 0, ct_1_pos = 0, ct_pos = 0, ct_neg = 0;
		int un_neg = 0, un_pos = 0;
		int flag = 0;
		int pos = 0;
		for(int i = 0; i < n; i++)
		{
			int tmp;	sf("%d", &tmp);
			if(tmp == 0)
				ct_0++;
			else if(tmp == 1)
				ct_1_pos++;
			else if(tmp == -1)
				ct_1_neg++;
			else if(tmp < 0)
			{
				if(ct_neg != 0)
					flag = 1;
				un_neg = tmp;
				ct_neg++;
			}
			else if(tmp > 0)
			{
				if(ct_pos != 0)
					flag = 1;
				un_pos = tmp;
				ct_pos++;
			}
		}
		//pf("ct_0 = %d, ct_1_neg = %d, ct_1_pos = %d, ct_pos = %d, ct_neg;
		if(flag == 1)
		{
			pf("no\n");
			continue;
		}
		if(n == 1)
		{
			pf("yes\n");
			continue;
		}
		if(ct_neg == 0 && ct_pos == 0 && ((ct_1_neg > 1 && ct_1_pos > 0) || (ct_1_neg <= 1)))
		{
			pf("yes\n");
			continue;
		}
		else if(ct_neg == 1 && ct_1_neg == 0 && ct_pos == 0)
		{
			pf("yes\n");
			continue;
		}
		else if(ct_pos == 1 && ct_1_neg == 0 && ct_neg == 0)
		{
			pf("yes\n");
			continue;
		}
		else
		{
			pf("no\n");
			continue;
		}
	}
	return 0;
}
