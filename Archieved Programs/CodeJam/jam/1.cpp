#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N; cin >> N;
		vector <pair<int, char> > V;
		int total = 0;
		for(int n = 0; n < N; n++)
		{
			int tmp;	cin >> tmp;
			total += tmp;
			char c = 'A'+n;
			V.pb(mp(tmp,c));
		}
		pf("Case #%d: ", t+1);
		sort(V.rbegin(), V.rend());
		while(V[0].first != 0)
		{
			string out;
			if(V.size() > 1 && V[1].first*2 > total-1)
			{
				V[0].first--;	V[1].first--;
				out += V[0].second;	out += V[1].second;
				total -= 2;
			}
			else
			{
				V[0].first--;
				out += V[0].second;
				total--;
			}
			cout << out << " ";
			sort(V.rbegin(), V.rend());
		}
		cout << endl;
	}
	return 0;
}
