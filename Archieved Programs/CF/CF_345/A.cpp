#include <bits/stdc++.h>

#define ll long long int
#define sf scanf
#define pf printf
#define mp make_pair
#define pb push_back
#define loop(i, l, r) for(auto i = l; i != r; i++)
#define ins insert

using namespace std;

int main()
{
	int a, b, ans = 0;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	while(a < b && a != 0)
	{
		ans++;
		a ++;	b-= 2;
	}
	while(b > 0 && a > 0)
	{
		if( ( a <= 1 && b <= 1) || (a <= 0 || b <= 0))
			break;
		ans++;
		if(a > b)
			swap(a, b);
		a++;	b -= 2;
	}
	cout << ans;
	return 0;
}
