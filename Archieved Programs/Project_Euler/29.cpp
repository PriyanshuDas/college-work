#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ans = 99*99;
	for (int i = 2; i <= 11; i++)
	{
		for (int j = 2; pow(i, j) <= 100; j++)
		{
			ans -= 100/j;
		}
	}
	printf("Answer is - %d\n", ans);
	return 0;
}
