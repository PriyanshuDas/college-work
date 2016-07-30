#include<bits/stdc++.h>

#define pf printf
#define sf scanf
#define MOD 1000000007
#define ll long long int

using namespace std;

int ct[101];
int char_p[101][30];

int main()
{
	int n, m;
	cin >> n >> m;
	string s[100];
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!char_p[j][s[i][j] - 'A'])
			{
				char_p[j][s[i][j] - 'A']++;
				ct[j]++;
			}
		}
	}
	ll ans = 1;
	for(int i = 0; i < m; i++)
	{
		ans = (ans*ct[i])%MOD;
	}
	cout << ans;
	return 0;
}
