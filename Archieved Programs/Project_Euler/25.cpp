#include<bits/stdc++.h>

#define pf printf
#define pb push_back

using namespace std;

int main()
{
	int fibb1[1001] = {0};
	int fibb2[1001] = {0};
	fibb1[0] = 1;
	long long int ctr = 1;
	while(!fibb2[2])
	{
		int fibb3[1001];
		for (int i = 0; i < 1001; i++)
		{
			fibb3[i] = fibb1[i] + fibb2[i];
		}
		for(int i = 0; i < 1001; i++)
		{
			fibb3[i+1] += fibb3[i]/10;
			fibb3[i] %= 10;
			fibb1[i] = fibb2[i];
			fibb2[i] = fibb3[i];
		}
		ctr++;
	}

		cout << ctr-1;
	return 0;
}