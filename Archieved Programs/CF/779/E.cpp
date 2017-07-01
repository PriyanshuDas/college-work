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

map <string, int> M;
vector <string> variables;
vector <pair<int, pair< string, pair<int, int> > > > expression;

pair <string, pair<string, string> > parse(string S)
{
	string a = "", b = "", op = "";
	int ct = 0;
	string tmp = "";
	for(int i = 0; i < S.size(); i++)
	{
		if(S[i] != ' ')
			tmp += S[i];
		
		if(S[i] == ' ' && a == "")
		{
			a = tmp;
			tmp = "";
		}
		else if (S[i] == ' ' && op == "")
		{
			op = tmp;
			tmp = "";
		}
		else if(i == S.size()-1)
		{
			b = tmp;
			tmp = "";
		}
	}
	return mp(op, mp(a, b));
}

char operate(string op, char l, char r)
{
	if(op == "XOR")
	{
		if(l == r)
			return '0';
		return '1';
	}
	if(op == "AND")
	{
		if(l == '0' || r == '0')
			return '0';
		return '1';
	}
	if(op == "OR")
	{
		if(l == '1' || r == '1')
			return '1';
		return '0';
	}
}

int solve(int pos)
{
	int ct = 0;
	for(int i = 0; i < expression.size(); i++)
	{
		int p = expression[i].first;
		string op = expression[i].second.first;
		int lo = expression[i].second.second.first;
		int ro = expression[i].second.second.second;
		char l = variables[lo][pos];
		char r = variables[ro][pos];
		char res = operate(op, l, r);
		///pf("(%d, %d, %d, %d) == %c %c == %c\n", pos, p, lo, ro, l, r, res);
		variables[p][pos] = res;
		if(res == '1')
			ct++;
	}
	return ct;
}

int main()
{
	int n, m;
	cin >> n >> m;
	string flush;
	getline (cin,flush);
	string m_zero;
	for(int i = 0; i < m; i++)
		m_zero += '0';
	M["?"] = 0;
	variables.pb(m_zero);
	for(int i = 1; i <= n; i++)
	{
		string tmp;
		getline (cin,tmp);
		//cout << tmp << endl;
		string var, val;
		int pos = 0;
		while(tmp[pos] != ' ')
		{
			var += tmp[pos];
			pos++;
		}
		pos += 4;
		tmp = tmp.substr(pos, tmp.size()-pos);
		int flag = 0;
		for(int ii = 0; ii < tmp.size(); ii++)
		{
			if(tmp[ii] == ' ')
				flag = 1;
		}
		if(flag == 0)
		{
			M[var] = i;
			variables.pb(tmp);
		}
		else
		{
			pair<string, pair< string, string> > expr = parse(tmp);
			variables.pb(m_zero);
			M[var] = i;
			string op = expr.first;
			string lo = expr.second.first;
			string ro = expr.second.second;
			int lv = M[lo];
			int rv = M[ro];
			expression.pb(mp(i, mp(op, mp(lv, rv))));
		}
	}
	string ans_min = "", ans_max;
	for(int i = 0; i < m; i++)
	{
		int ct[2] = {0};
		variables[0][i] = '0';
		//cout << variables[0] << endl;
		ct[0] += solve(i);
		variables[0][i] = '1';
		//cout << variables[0] << endl;
		ct[1] += solve(i);
		//pf("%d \t (%d, %d)\n", i, ct[0], ct[1]);
		if(ct[1] > ct[0])
		{
			ans_max += '1';
			ans_min += '0';
		}
		else if(ct[1] == ct[0])
		{
			ans_min += '0';
			ans_max += '0';
		}
		else
		{
			ans_max += '0';
			ans_min += '1';
		}
	}
	cout << ans_min << endl << ans_max;
	return 0;
}