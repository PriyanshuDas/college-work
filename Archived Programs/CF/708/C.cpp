#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll> >

using namespace std;

int main()
{
	string s;	cin >> s;
	int flag = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(flag == 0 && s[i] != 'a')
		{
			flag = 1;
			while(i < s.size() && s[i] != 'a')
			{
				s[i] = s[i] - 1;
				i++;
			}
		}
	}
	if(flag == 0)
		s[s.size()-1] = 'z';
	cout << s;
	return 0;
}
