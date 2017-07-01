#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define ins insert
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

vector <int> convrt(string s)
{
	int hr = s[0]*10 + s[1];
	int mn = s[3]*10 + s[4];
	int sc = s[5]*10 + s[6];
	vector <int> op;	op.pb(hr);	op.pb(mn);	op.pb(sc);
	return op;
}

string inc_s_mod (string s, int mod)
{
	string ans = "";
	int val = s[0]*10+s[1];
	val = ((val+1)%mod);
	ans = ((val/10) + '0') + (val%10 + '0');
	return ans;
}

pair<bool, string> set(int typ, string a, string b)
{
	if(typ == 0)	//hr
	{
		string new_b = b;
		string hr = b.substr(0, 2);
		if(hr == "??")
		{
			pair<bool, string> out_m = set(1, a, b);
			if(out_m.fi)
			{
				out_m.se[0] = a[0];	out_m.se[1] = a[1];
				return out_m;
			}
			else
			{
				string hr = a.substr(0, 2);
				string tmp = inc_s_mod(hr, 24);
				b[0] = tmp[0];
				b[1] = tmp[1];
				return mp(1, b);
			}
		}
		else if (hr[0] == a[0] && hr[1] == '?')
		{
			
		}
		else if (hr[0] > a[0] && hr[1] == '?')	//set every ? to 0
		{
		}
		else if( hr[0] < a[0] && hr[1] == '?')	//set every ? to 0
		{
		}
	}
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		vector <string> S;
		int N;
		for(int i = 0; i < N; i++)
		{
			string tmp;	cin >> tmp;
			S.pb(tmp);
		}
		vector <int> p_time = convrt(S[0]);
		string p_s = S[0];
		for(int i = 1; i < N; i++)
		{	
			
		}
	}
}
