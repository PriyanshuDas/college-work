#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ins insert
#define pi2 pair<ll, ll>
#define pi3 pair<ll, pi2 >
#define pi4 pair<pi2, pi2 >
#define loop(i,l,r) for(int i = l; i < r; i++)

using namespace std;

int main()
{
	string s;	cin >> s;
	int curr = 0;
	int ans = 0;
	for(int i = 0; i < s.size(); i++)
	{
		int c = s[i]-'a';
		int a = abs(c-curr);
		int b = curr+ (26-c);		//suppose c > curr
		if(c < curr)
			b = 26-curr + c;
		ans += min(a, b);
		curr = c;
	}
	cout << ans;
	return 0;
}
