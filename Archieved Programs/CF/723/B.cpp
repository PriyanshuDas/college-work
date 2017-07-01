#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair <ll, pi2 >
#define pi4 pair<pi2, pi2>
#define loop(l,r) for(int i = l; i < r; i++)
#define ull unsigned long long int

using namespace std;

int main()
{
	int n;	cin >> n;
	string s;	cin >> s;
	int p_ct = 0;	int lngest = 0, fl = 0, curr = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(fl==0 && s[i]!='_' && s[i] != '(')
		{
			curr++;
		}
		if(fl == 0&&(s[i]=='(' || s[i]=='_') && (i > 0 && s[i-1]!=')'||s[i-1]!='_'))
		{
			lngest = max(lngest, curr);
			curr = 0;
		}
		if(s[i] == '(')
		{
			fl = 1;
		}
		if(fl == 1 && (s[i] == '_' || s[i] == ')') && (s[i-1] != '(' && s[i-1] != '_'))
		{
			p_ct++;
			//cout << i << ' ' << p_ct << endl;
		}
		if(fl == 1 && s[i] == ')')
		{
			fl = 0;
			continue;
		}
	}
	lngest = max(curr, lngest);
	cout << lngest << ' ' << p_ct;
	return 0;
}
