#include <bits/stdc++.h>

#define ll long long int
#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N;	cin >> N;
		vector<int> n_list;
		for(int n = 0; n < 2*N; n++)
		{
			vector <int> t_vec;
			for(int i = 0; i < N; i++)
			{
				int tmp;	sf("%d", &tmp);
				t_vec.pb(tmp);
			}
			n_list.pb(t_vec);
		}
	}
	return 0;
}
