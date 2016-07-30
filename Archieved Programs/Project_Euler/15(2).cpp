#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define pb push_back
#define mp make_pair
#define ll long long int
#define R 100
#define C 100
using namespace std;


int dx[] = {1,0};
int dy[] = {0,1};
ll way[R+1][C+1] = {0};

ll ways(ll x, ll y)
{
	ll ct = 0;
	if (way[x][y])
		return way[x][y];
	for (ll i = 0; i < 2; i++)
	{
		if(x+dx[i] < R+1 && y+dy[i] < C+1)
			ct += ways(x+dx[i], y+dy[i]);
	}
	//cout  << ct << "\n";
	way[x][y] = ct;
	return ct;
}

int main()
{

	way[R][C] = 1;
	int ans = 0;
	/*for (int j = 19; j >= 0; j++)
	{
		for (int k = 19; k >= 0; k++)
			ways(j,k);
	}*/
	while(1)
	{
		ll X, Y;
		sf("%lld%lld", &X, &Y);
		ways(X,Y);
		pf("%lld\n", way[X][Y]);
	}
	cout << way[0][0];
	return 0;
}