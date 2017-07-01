#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define ins insert

using namespace std;

int main()
{
	int n;	cin >> n;
	int ct[2][6] = {0};
	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		ct[0][tmp]++;
	}
	for(int i = 0; i < n; i++)
	{
		int tmp;	sf("%d", &tmp);
		ct[1][tmp]++;
	}
	int diff = 0;
	int flag = 0;
	for(int i = 1; i <= 5; i++)
	{
		if(ct[0][i] != ct[1][i])
		{
			int tmp = abs(ct[0][i] - ct[1][i]);
			if(tmp%2 != 0)
				flag = 1;
			diff += tmp/2;
		}
	}
	if(flag == 0)
		cout << diff/2;
	else
		cout << -1;
	return 0;
}