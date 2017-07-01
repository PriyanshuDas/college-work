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

string S;
int N, K;

int solve(int k)
{
	int l = 1, r = N;
	while(l < r)
	{
		int mid = (l+r)>>1;
		//pf("%d %d %d\n", l, mid, r);
		int flag = 0, cur = k, ct = 1;
		if(mid == 1)
		{
			int c1 = 0, c2 = 0;	// c1 = 010 c2 = 101
			for(int i = 0; i < S.size(); i++)
			{
				if(S[i] == '1')
				{
					if(i%2 == 0)
						c1++;
					if(i%2 == 1)
						c2++;
				}
				else
				{
					if(i%2 == 0)
						c2++;
					else
						c1++;
				}
			}
			//pf("%d %d %d\n\n", c1, c2, k);
			if(min(c1, c2) <= k)
				return 1;
			else
			{
				l = mid+1;
				continue;
			}
		}
		for(int i = 1; i < S.size(); i++)
		{
			if(S[i] == S[i-1])
				ct++;
			else
				ct = 1;
			if(ct > mid)
			{
				cur--;
				ct = 0;
			}
		}
		if(cur >= 0)
		{
			r = mid;
			continue;
		}
		else
		{
			l = mid+1;
			continue;
		}
	}
	return l;
}

int main()
{
	int T;	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		cin >> S;
		int ans = solve(K);
		pf("%d\n", ans);
	}
	return 0;
}