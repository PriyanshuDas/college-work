#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(l,r) for(int i = l; i < r; i++)

using namespace std;

int arr[21][21];

int main()
{
	int n, m;	cin >> n >> m;
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	string ans = "NO";
	for(int i = 0; i < m; i++)
	{
		for(int j = i; j < m; j++)
		{
			for(int k = 0; k < n; k++)
			{
				swap(arr[i][k], arr[j][k]);
			}
			int f2 = 0;
			for(int k = 0; k < n; k++)
			{
				int flag = 0;
				for(int l = 0; l < n; l++)
				{
					if(arr[k][l] != (l+1))
						flag++;
				}
				if(flag > 2)
					f2 = 1;
			}
			if(f2 == 0)
			{
				ans = "YES";
			}
			for(int k = 0; k < n; k++)
			{
				swap(arr[i][k], arr[j][k]);
			}
		}
	}
	cout << ans;
	return 0;
}
