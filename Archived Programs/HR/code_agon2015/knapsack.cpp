#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int Max = N;
	bool arr[100000] = {0};
	int i = 0;
	for(i; i <= N; i++)
	{
		if (M == 0 || Max == 0)
			break;
		else if (Max > 0 && M >= Max)
		{
			M-= Max;
			Max--;
		}
		else if (M < Max)
		{
			M = 0;
		}
	}
	if(M != 0)
		cout << -1;
	else
		cout << i;
	return 0;
}
