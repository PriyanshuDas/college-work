#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define mp make_pair

using namespace std;

int main()
{
	int T;	cin >> T;
	while(T--)
	{
		set <string> s;
		for(int i = 0; i < 4; i++)
		{
			string tmp;	cin >> tmp;
			s.ins(tmp);
		}
		int ct = 0;
		for(int i = 0; i < 4; i++)
		{
			string tmp;	cin >> tmp;
			if(s.find(tmp) != s.end())
				ct++;
		}
		if (ct >= 2)
			pf("similar\n");
		else
			pf("dissimilar\n");
	}
	return 0;
}