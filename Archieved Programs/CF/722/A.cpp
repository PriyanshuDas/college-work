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

int main()
{
	int x;	cin >> x;
	string s;	cin >> s;
	int hr = (s[0] - '0')*10 + (s[1] - '0');
	int mn = (s[3] - '0')*10 + (s[4] - '0');
	int ct = 0;
	if(mn > 59)
	{
		ct++;
		mn = mn%10;
	}
	if(x == 12 && (hr > 12 || hr == 0))
	{
		hr = hr%10;
		if(hr == 0)
		{
			hr = 10;
		}
		ct++;
	}
	else if( x == 24 && hr > 23)
	{
		ct++;
		hr = hr%10;
	}
	string ans;
	ans += ('0'+hr/10);
	ans += ('0'+hr%10);
	ans += ':';
	ans += ('0'+mn/10);
	ans += ('0'+mn%10);
	//cout << hr << ':' << mn << endl;
	cout << ans << endl;
	return 0;
}
