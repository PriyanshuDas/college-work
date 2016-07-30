#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		long long int ans = 0;
		for(int i = 0; i < N; i++)
		{
			long long int tmp = 0;
			cin >> tmp;
			ans |= tmp;
		}
		for(int i = 1; i < N; i++)
		{
			ans = (ans*2)%MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
