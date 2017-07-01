#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define ll long long int
using namespace std;

int main()
{
	for (int i = 1; i < 333; i++)
	{
		for (int j = i+1; j < 500; j++)
		{
			for (int k = j+1; k < 1000; k++)
			{
				if (i+j+k == 1000)
				{
					if (i*i + j*j == k*k)
					{
						ll a = i*j*k;
						pf ("%lld\n\n", a);
					}
				}
			}
		}
	}
	return 0;
}