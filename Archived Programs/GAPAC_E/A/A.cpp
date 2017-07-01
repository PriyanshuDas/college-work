#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned ll

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		string S;
		cin >> S;
		ull l, r;
		cin >> l >> r;
		ull ans = 0;
		ull b_rond = 0;
		for(int i = 0; i < S.size(); i++)
		{
			if(S[i] == 'B')
				b_rond++;
		}
		ans += ((r-l+1)/S.size())*b_rond;
		l = (l-1)%S.size();
		r = (r-1)%S.size();
		if(r < l)
			r += (S.size());
		if(r%(S.size()) == (l+S.size()-1)%S.size())
		{
			pf("Case #%d: %llu\n", t, ans);
			continue;
		}
		for(l; l <= r; l++)
		{
			if(S[l%S.size()] == 'B')
				ans++;
		}
		pf("Case #%d: %llu\n", t, ans);
	}
	return 0;
}
