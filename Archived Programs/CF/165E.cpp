#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define m_max 4194304
#define n_max 22

using namespace std;
int arr[m_max+1];
bool Exists[m_max+20] = {0};
int F[m_max+10][2] = {0};

int main()
{
	int n;	cin >> n;
	for(int i = 0; i < n; i++)
	{
		sf("%d", &arr[i]);
		Exists[arr[i]] = 1;
		F[arr[i]][0] = arr[i];
	}
	for(int i = 1; i <= n_max; i++)
	{
		for(int mask = 0; mask < m_max; mask++)
		{
			if((mask&(1<<(i-1))) != 0)		// If ith bit of mask is 1
			{
				if((mask^(1<<(i-1))) <= m_max)
					F[mask][i%2] = F[(mask^(1<<(i-1)))][(i+1)%2];
			}
			else							//If ith bit of mask is 0
			{
				F[mask][i%2] = F[mask][(i+1)%2];
				if((mask^(1<<(i-1))) <= m_max && F[mask][i%2] == 0)
				{
					F[mask][i%2] = F[(mask^(1<<(i-1)))][(i+1)%2];
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(F[arr[i]][(n_max)%2] == 0)
			pf("-1 ");
		else
			pf("%d ", F[arr[i]][(n_max)%2]);
	}
	return 0;
}
