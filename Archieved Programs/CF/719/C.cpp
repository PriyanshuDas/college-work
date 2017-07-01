#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2>
#define pi4 pair<pi2, pi2>
#define loop(i, l, r) for(int i = l; i < r; i++)

using namespace std;

int main()
{
	int n, t;	cin >> n >> t;
	string s;
	cin >> s;
	int dot_pos = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '.')
		{
			dot_pos = i;
			break;
		}
	}
	string s2 = s.substr(0, dot_pos) + s.substr(dot_pos+1, s.size()-dot_pos-1);
	int fl2 = 0, flag = 0;
	for(int i = dot_pos-1; i < s2.size()-1 && i >= dot_pos-1 && t > 0;)
	{
		//cout << s2 <<'\t' << t <<  endl;
		if(s2[i+1] >= '5')
		{
			if(flag != 1)
			{
				for(int j = i+1; j < s2.size(); j++)
					s2[j] = '0';
			}
			s2[i+1] = '0';
			while(i >= 0 && s2[i] == '9')
			{
				s2[i] = '0';
				i--;
			}
			if(i < 0)
			{
				s2 = "1"+s2;
				fl2 = 1;
			}
			else
			{
				s2[i] += 1;
				s2[i+1] = '0';
			}
			t--;
			flag = 1;
			i--;
		}
		else if (flag == 1)
		{
			break;
		}
		else
		{
			i++;
		}
	}
	//cout << s2 << '\t' << t << endl;
	s = s2.substr(0, dot_pos+fl2) + '.' + s2.substr(dot_pos+fl2, s2.size()-dot_pos-fl2);
	int j = 0;
	for(j = s.size()-1; j >= 0; j--)
	{
		if(s[j] != '0')
			break;
	}
	if(s[j] == '.')
		j--;
	s = s.substr(0, j+1);
	cout << s;
	return 0;
}
