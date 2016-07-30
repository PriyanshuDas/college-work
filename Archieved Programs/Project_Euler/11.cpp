#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define ll long long int

using namespace std;

int main()
{
	long long int ans = 0;
	int a[21][21];
	pair <int, int> loc;
	string direction;
	for (int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
			sf("%d", &a[i][j]);
	}
	for(int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if(j < 21-4)
			{
				ll temp = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
				if (temp > ans)
				{
					loc = {i,j};
					direction = "L to R";
					ans = temp;
				}
			}
			if (i < 21-4)
			{
				ll temp = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
				if (temp > ans)
				{
					loc = {i,j};
					direction = "U to D";
					ans = temp;
				}
			}
			if (i < 21-4 && j < 17)
			{
				ll temp = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
				if (temp > ans)
				{
					loc = {i,j};
					direction = "UL to DR";
					ans = temp;
				}
			}
			if (i < 21-4 && j > 2)
			{
				ll temp = a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
				if (temp > ans)
				{
					loc = {i,j};
					direction = "UR to DL";
					ans = temp;
				}
			}
		}
	}
	pf ("The greatest is %lld\t taking from <%d, %d> \n", ans, loc.first, loc.second);
	cout << direction << "\n";
	return 0;
}