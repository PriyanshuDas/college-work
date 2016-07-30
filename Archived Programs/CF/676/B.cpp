#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pii pair<int, int>

using namespace std;

double delta = 0.0000001;

int main()
{
	double glasses[20][20] = {0};
	int n, t;	cin >> n >> t;
	glasses[1][1] = t;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(glasses[i][j] - 1 < 0)
				continue;
			//pf("[%d][%d] full! ", i, j);
			double extra = glasses[i][j] - 1;
			//cout << extra << endl;
			glasses[i][j] = 1;
			glasses[i+1][j] += 0.5*extra;
			glasses[i+1][j+1] += 0.5*extra;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(1 - glasses[i][j] < delta)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
