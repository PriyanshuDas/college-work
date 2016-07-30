#include <bits/stdc++.h>

#define pf printf
#define sf scanf

using namespace std;

int Max[5051];
int main()
{
	int nodes[5051];
	int k = 100;
	for (int i = 1; i < 5051; i++)
	{
		sf("%d", &nodes[i]);
	}
	for (int i = 4951; i < 5051; i++)
	{
		Max[i] = nodes[i];
		//pf("%d ) %d\n ", i, Max[i]);
	}
	int l = k;
	for (int i = 4950; i >0; i--)
	{
		l--;
		Max[i] = nodes[i] + max(Max[i+k], Max[i+k-1]);
		if(l == 1)
		{
			k--;
			l = k;
		}
	}
	for (int i = 4800; i < 5051; i++)
		pf("%d) %d - %d\n",i, nodes[i], Max[i]);
	pf("%d", Max[1]);
	return 0;
}