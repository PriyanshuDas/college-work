#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair

using namespace std;

int Max[121];
int main()
{
	int nodes[121];
	int k = 15;
	for (int i = 1; i < 121; i++)
	{
		sf("%d", &nodes[i]);
	}
	for (int i = 106; i < 121; i++)
	{
		Max[i] = nodes[i];
		pf("%d ) %d\n ", i, Max[i]);
	}
	int l = k;
	for (int i = 105; i >0; i--)
	{
		l--;
		Max[i] = nodes[i] + max(Max[i+k], Max[i+k-1]);
		pf("%d ) %d - %d\n ", i, nodes[i], Max[i]);
		if(l == 1)
		{
			k--;
			l = k;
		}
	}
	pf("%d", Max[1]);
	return 0;
}