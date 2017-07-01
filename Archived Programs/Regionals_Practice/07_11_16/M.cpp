#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

vector<int> solve (int st, int en)
{
	char c;
	vector<int> V;
	if(st == en - 1)
	{
		pf("? %d %d\n", st, en);
		fflush(stdout);
		cin >> c;
		if(c == '>')
		{
			V.pb(st);
			V.pb(en);
		}
		else
		{
			V.pb(en);
			V.pb(st);
		}
		//cout << V.size() << endl;
		return V;
	}
	if(st == en)
	{
		V.pb(st);
		return V;
	}
	int md = (st+en)/2;
	vector<int> V1 = solve(st, md);
	vector<int> V2 = solve(md+1, en);
	//cout << V1.size() << '\t' << V2.size() << '\t'<< endl;
	
	pf("? %d %d\n", V1[0], V2[0]);
	fflush(stdout);
	cin >> c;

	int m = 0, l = 0;
	if(c == '>')
	{
		m = 11;
		V.pb(V1[0]);
	}
	else
	{
		m = 21;
		V.pb(V2[0]);
	}
	if(V1.size() == 1 && m == 11)
	{
		V.pb(V2[0]);
		return V;
	}
	else if(V2.size() == 1 && m == 21)
	{
		V.pb(V1[0]);
		return V;
	}
	
	if(m == 11)
	{
		pf("? %d %d\n", V1[1], V2[0]);
		fflush(stdout);
		cin >> c;
		if(c == '>')
		{
			V.pb(V1[1]);
		}
		else
		{
			V.pb(V2[0]);
		}
	}
	else
	{
		pf("? %d %d\n", V1[0], V2[1]);
		fflush(stdout);
		cin >> c;
		if(c == '>')
		{
			V.pb(V1[0]);
		}
		else
		{
			V.pb(V2[1]);
		}
	}
	return V;
}

int n;

int main()
{
	cin >> n;
	vector<int> ans = solve(1, n);
	pf("! %d\n", ans[1]);
	return 0;
}
