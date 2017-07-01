#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define n_max 1000001

using namespace std;

bool is_pal(string s)
{
	for(int i = 0; i < s.size()/2; i++)
		if(s[i] != s[s.size()-i-1])
			return false;
	return true;
}

int main()
{
	int T;	sf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		string s;	cin >> s;
		if(is_pal(s))
			pf("YES\n");
		else
			pf("NO\n");
	}
	return 0;
}
