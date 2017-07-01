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
	int n, m;	cin >> n >> m;
	int f = 0;
	for(int t = 0; t < m; t++)
	{
		map<int, set<int> > group;
		int k;	sf("%d", &k);
		for(int i = 0; i < k; i++)
		{
			int x;	sf("%d", &x);
			if(x < 0)
			{
				group[abs(x)].ins(-1);
			}
			else
			{
				group[abs(x)].ins(1);
			}
		}
		int flag = 1;
		for(auto it = group.begin(); it != group.end(); it++)
		{
			if(it->second.size() > 1)
				flag = 0;
		}
		if(flag == 1)
		{
			f = 1;
		}
	}
	if(f == 1)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}