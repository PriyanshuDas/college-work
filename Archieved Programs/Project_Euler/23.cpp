#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back

using namespace std;
bool ans[10000000] = {0};
vector <int> abundant;
int main()
{
	int pow2[30];
	long long int sum = 0;
	pow2[0] = 1;
	for (int i = 1; i < 28130; i++)
	{
		int rt = sqrt(i);
		int sum = 1;
		int i2 = i;
		for(int j = 2; j <= rt; j++)
		{
			if (i2%j == 0)
			{
				sum += i2/j;
				sum += j;
			}
		}
		if(rt*rt == i)
			sum -= rt;
		if(sum > i)
		{
			abundant.pb(i);
		}
	}
	for (int i = 0 ; i < abundant.size(); i++)
	{
		for (int j = i; j < abundant.size(); j++)
			ans[abundant[i] + abundant[j]] = 1;
	}
	for(int i = 0; i < 28130; i++)
	{
		if (!ans[i])
		{
			sum += i;
		}
	}
	pf("The sum is - %lld \n", sum);
	return 0;
}