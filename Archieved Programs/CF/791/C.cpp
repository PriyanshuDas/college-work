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

vector <int> ans;
int main()
{
	int n, k;
	cin >> n >> k;
	int ct = 0;
	for(int i = 0; i < n-k+1; i++)
	{
		string s;	cin >> s;
		if(s == "YES")
		{
			for(int j = ans.size(); j < i+k; j++)
			{
				if(j >= ans.size())
				{
					ans.pb(ct);
					ct++;
				}
			}
		}
		else
		{
			for(int j = ans.size(); j < i+k; j++)
			{
				if(j >= ans.size() && j != i+k-1)
				{
					ans.pb(ct);
					ct++;
				}
				if(j == i+k-1)
				{
					if(j >= ans.size())
						ans.pb(ans[i]);
					else
						ans[j] = ans[i];
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		string Ans = "Aaa";
		Ans[0] = ans[i]/(25*25) + 'A';
		Ans[1] = ans[i]/(25)+'a';
		Ans[2] = ans[i]%25 +'a';
		cout << Ans << ' ';
	}
	cout << endl;
	return 0;
}