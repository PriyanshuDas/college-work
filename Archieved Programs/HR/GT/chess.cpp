#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define ll long long int

using namespace std;

int val[16][16];

int play(int x, int y)
{
	if(x < 1 || y < 1 || x > 15 || y > 15)
		return 1;
	if(val[x][y] != -1)
		return val[x][y];
	int a1 = play(x-2, y+1);
	int a2 = play(x-2, y-1);
	int a3 = play(x+1, y-2);
	int a4 = play(x-1, y-2);
	
	if(a1 == 0 || a2 == 0 || a3 == 0 || a4 == 0)
	{
		val[x][y] = 1;
		return 1;
	}
	val[x][y] = 0;
	return 0;
}

int main()
{
	int T;	cin >> T;
	memset(val, -1, sizeof(val));
	for(int t = 0; t < T; t++)
	{
		int xi, yi;
		cin >> xi >> yi;
		int ans = play(xi, yi);
		if(ans == 1)
			cout << "First\n";
		else
			cout << "Second\n";
	}
	return 0;
}
