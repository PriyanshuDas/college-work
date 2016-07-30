#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int

using namespace std;

int main()
{
	int n, h, ans = 0;	cin >> n >> h;
	for(int i = 0; i < n; i++)
	{
		int tmp;	cin >> tmp;
		if(tmp > h)
			ans++;
		ans++;
	}
	cout << ans;
}
