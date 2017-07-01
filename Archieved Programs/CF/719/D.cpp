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
#define n_max 200001

using namespace std;

int main()
{
	int n, m;	cin >> n >> m;
	vector <int> T;
	for(int i = 0; i < n; i++)
	{
		int t;	sf("%d", &t);
		T.pb(t);
	}
	sort(T.begin(), T.end());
	for(int i = 0; i < m; i++)
	{
		int ai;
		sf("%d", &ai);
		int ct = 0;
		set <pair<int, int> > tline;		// timeline (time, m_no)
		ll t = 0;
		tline.ins(mp(T[0], 0));
		int nxt = 1;
		while(ct < ai)
		{
			t = (*tline.begin()).first;
			int mach = (*tline.begin()).second;
			tline.erase(mp(t, mach));
			ct++;
			tline.ins(mp(t+T[mach], mach));
			if(nxt < n)
			{
				tline.ins(mp(t+T[nxt], nxt));
				nxt++;
			}
		}
		cout << t  << endl;
	}	
	return 0;
}
