//https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/a-game-of-stones

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back

using namespace std;

int value[101];

int play(int n)
{
	if(n == 2 || n== 3 || n == 5)
	{
		return 1;
	}
	else if(n < 2)
		return 0;
	if(value[n] != -1)
		return value[n];
	int v1 = play(n-2), v2 = play(n-3), v3 = play(n-5);
	if(v1 == 1 && v2 == 1 && v3 == 1)
	{
		value[n] = 0;
		return 0;
	}
	else
	{
		value[n] = 1;
		return 1;
	}
}

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int n;	cin >> n;
		memset(value, -1, sizeof(value));
		if(play(n) == 1)
			cout << "First\n";
		else
			cout << "Second\n";
	}
	return 0;
}
