#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define ll long long int
using namespace std;

int main()
{
	string s;
	cin >> s;
	pf ("Enter the no. \n");
	ll ans = 0;
	for (int i = 0; i < 1000-12; i++)
	{
		ll curr = 1;
		string s2 = s.substr(i, 13);
		bool flag = false;
		for (int j = 0; j<13; j++)
		{
			curr *= s2[j] - '0';
			if (s2[i] == '0')
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		else
		{
			if (curr > ans)
				ans = curr;
		}
	}
	pf("The Ans is - %lld", ans);
	return 0;
}