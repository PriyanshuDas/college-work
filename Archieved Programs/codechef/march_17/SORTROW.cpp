#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ins insert
#define ll long long int
#define ull unsigned long long int
#define fi first
#define se second

using namespace std;

int main()
{
	int N; cin >> N;
	vector <vector <int> > V;
	for(int i = 0; i < N; i++)
	{
		vector <int> v;
		for(int j = 0; j < N; j++)
		{
			int tmp;
			sf("%d", &tmp);
			v.pb(tmp);
		}
		V.pb(v);
	}
	vector <vector <int> > Ans;
	for(int i = 0; i < N; i++)
	{
		vector <int> v = V[i];
		vector <int> v1 = v, v2 = v;
		sort(v1.begin(), v1.end());
		sort(v2.rbegin(), v2.rend());
		ll c1 = 0, c2 = 0;
		for(int j = 0; j < v1.size(); j++)
		{
			for(int k = 0; k < v.size(); k++)
			{
				if(v1[j] == v[k])
					c1 += (k-j)*(k-j);
				if(v2[j] == v[k])
					c2 += (k-j)*(k-j);
			}
		}
		if(c1 < c2)
			Ans.pb(v1);
		else
			Ans.pb(v2);
	}
	for(int i = 0; i < Ans.size(); i++)
	{
		for(int j = 0; j < Ans[i].size(); j++)
		{
			pf("%d ", Ans[i][j]);
		}
		pf("\n");
	}
	return 0;
}