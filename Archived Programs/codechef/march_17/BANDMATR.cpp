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
	while(T--)
	{
		int N;	sf("%d", &N);
		int ct = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
			{
				int tmp;	sf("%d", &tmp);
				ct += tmp;
			}
		int bwith = 0;
		for(int i = 0; i < N && ct > 0; i++)
		{
			if(i == 0)
				ct -= N;
			else
				ct -= 2*(N-i);
			bwith++;
		}
		bwith--;
		bwith = max(bwith, 0);
		pf("%d\n", bwith);
	}
	return 0;
}