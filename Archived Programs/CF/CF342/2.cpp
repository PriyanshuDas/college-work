#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<long long int, long long int>

using namespace std;

int n, m;
int grid[501][501];
int main()
{
	cin >> n >> m;
	int curr = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m-1; j++)
		{
			grid[i][j] = curr;
			curr++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = m-1; j < n; j++)
		{
			grid[i][j] = curr;
			curr++;
		}
	}
	ll total = 0;
	for(int i = 0; i < n; i++)
	{
		total += grid[i][m-1];
	}
	cout << total << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			pf("%d ", grid[i][j]);
		pf("\n");
	}
	return 0;
}
