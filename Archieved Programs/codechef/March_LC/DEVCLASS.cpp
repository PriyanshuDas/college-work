#include<bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
	int T;
	scanf("%d", T);
	for (int i = 0; i < T; i++
	{
		int flag = 0,typ, bc = 0, bc_eve = 0;
		scanf("%d", type);
		string S;
		cin >> S;
		int n = S.size();
		int row[n] = {0};
		for (int j = 0; j < n; j++)
		{
			if (S[j] == 'B')
			{
				bc++;
				if(j%2 == 0)
					bc_eve++;
			}
		}
		if (bc < n/2 || (bc > n/2 && n%2 != 0) || bc > (n/2) + 1)
		{
			flag = 1;
		}
		if(!flag)
		{
			if(bc_eve > bc/2)
			{
				for (int j = 0; j < n; j++)
				
			}
		}
	}
	
	return 0;
}