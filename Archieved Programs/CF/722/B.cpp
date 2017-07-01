#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define ins insert
#define pi2 pair<ll, ll>
#define pi4 pair<pi2, pi2 >
#define pi3 pair<ll, pi2 >
#define ull unsigned long long int

using namespace std;

int vow_ct(string s)
{
	int ct = 0;
	for(int i = 0; i < s.size(); i++)
		if(s[i] =='a'||s[i] =='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
			ct++;
	return ct;
}

int main()
{
	int n;	cin >> n;
	vector <int> V1, V2;
	for(int i = 0; i < n; i++)
	{
		int tmp;	cin >> tmp;
		V1.pb(tmp);
	}
	cin.ignore(256, '\n');
	for(int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s, '\n');
		int v_c = vow_ct(s);
		V2.pb(v_c);
	}
	int flag = 0;
	for(int i = 0; i < V1.size(); i++)
	{
		//cout << V1[i] << ' ' << V2[i] << endl;
		if(V1[i] != V2[i])
			flag = 1;
	}
	if(flag == 1)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
