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
	int n;	string s;
	cin >> n >> s;
	int ct = 0;
	vector<int> V;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'B')
		{
			ct++;
			int tmp = 1;
			for(int j = i+1; j < s.size(); j++)
			{
				if(s[j] == 'B')
				{
					tmp++;
					i++;
				}
				else
				{
					break;
				}
			}
			V.pb(tmp);
		}
	}
	cout << ct << endl;
	for(int i = 0; i < V.size(); i++)
	{
		pf("%d ", V[i]);
	}
	return 0;
}
