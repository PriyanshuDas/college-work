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
#define loop(i,l,r) for(int i = l; i < r; i++)

using namespace std;

int main()
{
	vector <string> s;
	s.pb("monday");
	s.pb("tuesday");
	s.pb("wednesday");
	s.pb("thursday");
	s.pb("friday");
	s.pb("saturday");
	s.pb("sunday");
	string s1, s2;	cin >> s1 >> s2;
	int p1, p2;
	for(int i = 0; i < 7; i++)
	{
		if(s[i] == s1)
			p1 = i;
		if(s[i] == s2)
			p2 = i;
	}
	int flg = 0;
	for(int i = 1; i < 13; i++)
	{
		int d_m = 0;
		if(i==1||i==3||i==5||i==7||i==8||i==10)
		{
			d_m = 31;
		}
		else if(i==2)
		{
			d_m = 28;
		}
		else if(i == 12)
			continue;
		else
			d_m = 30;
		int pos = (p1+d_m)%7;
		if(pos == p2)
		{
			//cout << i << endl;
			flg = 1;
		}
	}
	if(flg == 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
