#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define lim 1000000
#define pb push_back

using namespace std;

bool prime[lim + 1];
vector <int> P_Factor[lim+1];

int Totient(int N)
{
	int ans = N;
	int den = 1;
	for(int i = 0; i < P_Factor[N].size(); i++)
	{
		den *= P_Factor[N][i];
	}
	ans /= den;
	for(int i = 0; i < P_Factor[N].size(); i++)
	{
		ans *= P_Factor[N][i] - 1;
	}
	return ans;
}

int main()
{
	for(int i = 2; i <= lim; i++)
	{
		if(!prime[i])
		{
			for(int j = i; j <= lim; j+= i)
			{
				prime[j] = 1;
				P_Factor[j].pb(i);
			}
		}
	}
	/*int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int n;
		sf("%d", &n);
		int ans = Totient(n);
		pf("%d\n", ans);
	}*/
	return 0;
}
