#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define mp make_pair
#define pb push_back

using namespace std;

typedef struct pair<int, int> PII;

int main()
{
	int n, ans = 0;
	cin >> n;
	map <int, int> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if(m[i] >1)
		{
			while(m[i] > 1)
			{
				int j = i;
				while(m[j] != 0)
				{
					j++;
					if(m[j] == 0)
					{
						m[j] = 1;
						ans += j - i;
						m[i]--;
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
