#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define n_max 100

using namespace std;

int state[n_max+1];

int find_state(int n)
{
	if(n == 0)
		return 0;
	if(state[n] != -1)	return state[n];
	int vis[10] = {0};
	if(n >= 2)	vis[find_state(n-2)] = 1;
	if(n >= 3)	vis[find_state(n-3)] = 1;
	if(n >= 5)	vis[find_state(n-5)] = 1;
	for(int i = 0; i < 10; i++)
		if(vis[i] == 0)
		{
			state[n] = i;
			return i;
		}
	return 0;
}

int main()
{
	memset(state, -1, sizeof(state));
	int T;	cin >> T;
	while(T--)
	{
		int n;	sf("%d", &n);
		if(find_state(n) == 0)	pf("Second\n");
		else	pf("First\n");
	}
	return 0;
}