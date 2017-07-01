#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int N, M;	sf("%d%d", &N, &M);
		pf("Case %d:\n", t+1);
		vector<int> num;
		for(int i = 0; i < N; i++)
		{
			double d;	sf("%lf", &d);
			d *= 100;
			num.pb((int)d);
		}
		sort(num.begin(), num.end());
		for(int m = 0; m < M; m++)
		{
			double z1;	sf("%lf", &z1);
			pf("Scenario %d:\n", m+1);
			int z = (int)(z1*100 + 0.5);
			vector<pair<int, int> > V;
			for(int i = num.size()-1; i >= 0 && z > 0; i--)
			{
				//cout << num[i] << '\t' << z << endl;
				int req = (z/num[i]);
				if(req > 0)
					V.pb(mp(num[i], req));
				z = z%num[i];
			}
			for(int i = 0; i < V.size(); i++)
			{
				int val = V[i].first, ct = V[i].second;
				if(val < 100)
				{
					if(val > 9)
						pf("0.%d %d\n", val, ct);
					else
						pf("0.0%d %d\n", val, ct);
				}
				else
				{
					int d = val/100;
					pf("%d %d\n", d, ct);
				}
			}
		}
	}
	return 0;
}
