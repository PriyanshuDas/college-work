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

int main()
{
	ull n, k;	cin >> n >> k;
	vector<string> S;
	for(int i = 0; i < n; i++)
	{
		string tmp;	cin >> tmp;
		S.pb(tmp);
	}
	string pass;
	cin >> pass;
	sort(S.begin(), S.end());
	ull best = 0, worst = 0, b_ans = 0, w_ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(S[i].size() < pass.size())
		{
			if(best%k == 0 && best != 0)
				b_ans = b_ans + 5;
			best++;
			b_ans++;
		}
		if(S[i].size() <= pass.size())
		{
			if(worst%k == 0 && worst != 0)
				w_ans = w_ans + 5;
			worst++;
			w_ans++;
		}
	}
	if(best%k == 0 && best != 0)
		b_ans = b_ans + 5;
	b_ans++;
	//cout << best << endl << worst << endl;=
	cout << b_ans << ' ' << w_ans;
	return 0;
}
