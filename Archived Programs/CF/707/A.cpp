#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >

using namespace std;

int main()
{
	int col = 0;
	int n, m;	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char tmp;	cin >> tmp;
			if(tmp != 'B' && tmp != 'W' && tmp != 'G')
			{
				col = 1;
			}
		}
	}
	if(col == 0)
		cout << "#Black&White";
	else
		cout << "#Color";
	return 0;
}
