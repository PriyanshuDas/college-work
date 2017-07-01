#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define llu unsigned ll

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		llu N;	cin >> N;
		int max_ct = 0;
		llu ans = 0;
		int rt_n = sqrt(N);
		float c_rt = pow(N, 1/3);
		for(int i = 2; i <= 1000000; i++)
		{
			llu n2 = N;
			int ct = 0, flag = 0;
			for(int j = 0; n2 > 0; j++)
			{
				if(n2%i == 1)
					ct++;
				else
				{
					flag = 1;
					break;
				}
				n2 /= i;
			}
			if(flag != 1 && ct > max_ct)
			{
				max_ct = ct;
				ans = i;
			}
		}
		if(max_ct < 2)
		{
			max_ct = 2;
			ans = N-1;
		}
		pf("Case #%d: %llu\n", t+1, ans);
	}
	return 0;
}
