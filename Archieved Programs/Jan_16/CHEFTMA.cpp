#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair <int, int>

using namespace std;

int main()
{
	int T;
	sf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		int N, K, M;
		vector <int> tasks;
		vector <int> buttons;
		for(int n = 0; n < N; n++)
		{
			int tmp;
			sf("%d", &tmp);
			tasks.pb(tmp);
		}
		for(int n = 0; n < N; n++)
		{
			int tmp;
			sf("%d", &tmp);
			tasks[n] -= tmp;
		}
		for(int b = 0; b < K+M; b++)
		{
			int tmp;
			sf("%d", &tmp);
			buttons.pb(tmp);
		}
		sort(tasks.begin(), tasks.end());
		sort(buttons.begin(),buttons.end());
		for(int i = 0; i < tasks.size()/2; i++)
			swap(tasks[i], tasks[tasks.size()-1-i]);
		for(int i = 0; i < buttons.size()/2;i++)
			swap(buttons[i], buttons[buttons.size()-1-i]);
			
	}
	return 0;
}
