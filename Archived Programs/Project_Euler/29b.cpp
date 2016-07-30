#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ans = 4*4;
	for (int i = 2; i < 6; i++)
	{
		for (int j = 2; pow(i, j) <= 5; j++)
		{
			ans -= 5/j;
		}
	}
	printf("Answer is - %d\n", ans);
	return 0;
}
