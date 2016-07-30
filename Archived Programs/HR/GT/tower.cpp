//https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/tower-breakers

#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define mp make_pair
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
	int T;	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N, M;	cin >> N >> M;
		if(M == 1)
		{
			cout << 2 << endl;
		}
		else
		{
			cout << (N+1)%2 + 1 << endl;
		}
	}
}
