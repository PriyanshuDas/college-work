#include <bits/stdc++.h>
#define ll long long int
#define sf scanf
#define pf printf
#define pb push_back

using namespace std;

bool pal_num(int num)
{
	vector<int> digits;
	while(num)
	{
		int curr_dig = num%10;
		digits.pb(curr_dig);
		num /= 10;
	}
	for(int I = 0; I < digits.size()/2; I++)
	{
		if(digits[I] != digits[digits.size() - I - 1])
			return false;
	}
	return true;
}
int main()
{
	ll ans = 0, i1 = 0, i2 = 0;
	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
			if(i*j > ans && pal_num(i*j))
			{
				i1 = i;
				i2 = j;
				ans = i*j;
			}
	}
	printf("The answer is : %lld = %lld * %lld\n", ans, i1, i2);
	//ans = pal_num(101);
	//printf("%lld\n",ans);
	return 0;
}