#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
	string s;	cin >> s;
	int ct_q = 0, ct_o = 0, ct_c = 0;
	int req_o = 0, req_c = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '?')
			ct_q++;
		if(s[i] == '(')
			ct_o++;
		if(s[i] == ')')
			ct_c++;
	}
	if(ct_o > ct_c)
		req_c = ct_o - ct_c;
	if(ct_c > ct_o)
		req_o = ct_c - ct_o;
	ct_q -= (req_c+req_o);
	req_o += ct_q/2;
	req_c += ct_q/2;

	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '?' && req_o > 0)
		{
			req_o--;
			s[i] = '(';
		}
		else if(s[i] == '?' && req_c > 0)
		{
			req_c--;
			s[i] = ')';
		}
	}
	int tmp = 0;
	for(int i =0; i < s.size(); i++)
	{
		if(s[i] == '(')
			tmp++;
		if(s[i] == ')')
			tmp--;
		if(tmp < 0 || s[i] == '?')
		{
			cout << "Impossible";
			return 0;
		}
	}
	if(tmp == 0)
		cout << s;
	else
		cout << "Impossible";
	return 0;
}
