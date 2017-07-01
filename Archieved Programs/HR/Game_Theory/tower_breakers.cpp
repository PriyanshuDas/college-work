#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define ins insert
#define mp make_pair

using namespace std;

int main()
{
	int T;	cin >> T;
	while(T--)
	{
		int N, M;	sf("%d%d", &N, &M);
		if(N%2 == 0 || M == 1)
			pf("2\n");
		else
			pf("1\n");
	}
	return 0;
}