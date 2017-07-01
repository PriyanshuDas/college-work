#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back
#define ll long long int

int mem[100001];
using namespace std;

int main()
{
	int inp;
	cin >> inp;
	ll sum = 0;
	for(int i = 2; i < inp; i++)
	{
		int sum_tmp=1;
		int rt = sqrt(i);
		for (int j= 2; j<= rt; j++)
		{
			if ((i % j)==0)
			{
				sum_tmp += j;
				int t2 = i/j;
				if(j != t2)
					sum_tmp += i/j;

				//cout << sum_tmp << "__ ";
			}
		}
		pf("i - %d, sum_tmp = %d\n", i, sum_tmp);
		mem[i] = sum_tmp;
		if (mem[sum_tmp] == i && sum_tmp != i)
			sum+= + i + sum_tmp;
	}
	cout << sum << endl;
	return 0;
}