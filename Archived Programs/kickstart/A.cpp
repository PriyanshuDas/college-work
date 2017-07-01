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
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		string w;	cin >> w;
		vector <int> a;

		for(int i = 0; i < w.size(); i++)
			a.pb(w[i]-'A');

		if(a.size()%2 != 0)
			pf("Case #%d: AMBIGUOUS\n", t);
		else
		{
			
			a[1] = w[0] - 'A';
			a[a.size()-2] = w[w.size()-1] - 'A';
			int tmp;
			for(int i = 1; i < ((int)a.size()-3); i+=2)
			{
				pf("%d\t%d\n", i, (int)a.size());
				sf("%d", &tmp);
				a[i+2] = (w[i+1]-'A') - a[i];
				while(a[i+2] < 0)
					a[i+2] += 26;
			}
			for(int i = a.size()-2; i > 2; i-=2)
			{
				pf("%d\t%d\n", i, (int)a.size());
				sf("%d", &tmp);
				a[i-2] = (w[i-1]-'A') - a[i];
				while(a[i-2] < 0)
					a[i-2] += 26;
			}
			if(a.size() > 2)
			{
				a[0] = (w[1]-'A') - a[2];
				while(a[0] < 0)
					a[0] += 26;

				a[a.size()-1] = (w[w.size()-2] - 'A') - a[a.size()-3];
				while(a[a.size()-1] < 0)
					a[a.size()-1] += 26;
			}
			pf("Case #%d: ", t);
			for(int i = 0; i < a.size(); i++)
				w[i] = a[i] + 'A';
			cout << w << endl;
		}
	}
	return 0;
}