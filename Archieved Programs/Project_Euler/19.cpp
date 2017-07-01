#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pb push_back

int main()
{
	int ct = 0;
	int day[12] = {2,5,5,1,3,6,1,4,0,2,5,0};
	for(int i = 1901; i < 2001; i++)
	{
		if((i-1)%4 == 0)
		{
			day[0]++;
			day[1]++;
		}
		if(i%4 == 0 && (i%100!= 0 && i%400 != 0))
		{
			for (int j = 2; j < 12; j++)
				day[j]++;
		}
		for(int j = 0; j < 12; j++)
		{
			if (day[j]%7 == 0)
			{
				day[j] = 0;
				ct++;
			}
		}
	}
	pf("%d\n", ct);
	return 0;
}