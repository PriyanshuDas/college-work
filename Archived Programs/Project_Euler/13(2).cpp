#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define pb push_back
#define max = 10000001
#define ll long long int
using namespace std;

int main()
{
	string s[100];
	int nos[100][50];
	for (int i = 0; i < 100; i++)
	{
		cin >>s[i];
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 50; j++)
			nos[i][j] = s[i][j] - '0';
	}
	//pf ("%d%d%d",nos[99][49], nos[99][48], nos[99][47]);
	//printf("H E R E ! \n");
	int ans[100] = {0};
	int rem = 0;
	for(int i = 49; i >= 0; i--)
	{
		rem = 0;
		for (int j = 0; j < 100; j++)
		{
			ans[100 - (50 - i)] += nos[j][i];
			rem += ans[100 - (50 - i)]/10;
			ans[100 - (50 - i)] %= 10;
		}
		ans[100 - (50 -i) - 1] = rem;
	}
	int ct = 149;
	while(rem!= 0)
	{
		ans[ct] = rem%10;
		rem/= 10;
		ct--;
	}
	for (int i = 0; i < 100; i++)
		pf("%d", ans[i]);
	pf ("\n");
	return 0;
}