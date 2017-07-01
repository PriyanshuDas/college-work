#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back
#define ins insert
#define loop(i,l,r) for(int i = l; i < r; i++)
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pair<ll, ll>
#define pi4 pair<pi2, pi2>

using namespace std;

int main()
{
	string s;	cin >> s;
	int poss = 0;
	//cout << s;
	for(int i = 0; i <= s.size() - 26 && s.size() >= 26; i++)
	{
		int ct[26], flag = 0, m_p = 0;
		memset(ct, 0, sizeof(ct));
		vector<int> m_pos;
		for(int j = 0; j < 26 && i+j < s.size(); j++)
		{
			if(s[i+j] == '?')
				m_pos.pb(i+j);
			else if (ct[s[i+j]-'A'] == 0)
				ct[s[i+j]-'A']++;
			else
				flag = 1;
		}
		//cout << flag << endl;
		if(flag == 1)
			continue;
		for(int j = 0; j < 26; j++)
		{
			if(ct[j] == 0)
			{
				s[m_pos[m_p]] = ('A'+ j);
				m_p++;
			}
		}
		poss = 1;
	}
	if(poss == 0)
	{
		cout << -1;
	}
	else
	{
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '?')
				s[i] = 'Z';
		}
		cout << s;
	}
	return 0;
}
