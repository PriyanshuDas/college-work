#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define mp make_pair
#define pi2 pair <ll, ll>
#define pi3 pair <ll, pair<ll, ll> >

using namespace std;

int main()
{
	int N;	cin >> N;
	int flag = 0;
	vector <string> V;
	for(int i = 0; i < N; i++)
	{
		string s;	cin >> s;
		for(int i = 0; i < s.size()-1 && flag == 0; i++)
		{
			if(s[i] == 'O' && s[i+1] == 'O')
			{
				s[i] = '+';		s[i+1] = '+';
				flag = 1;
			}
		}
		V.pb(s);
	}
	if(flag == 0)
		cout << "NO";
	else
	{
		cout << "YES\n";
		for(int i = 0; i < N; i++)
		{
			cout << V[i] << endl;
		}
	}
	return 0;
}
