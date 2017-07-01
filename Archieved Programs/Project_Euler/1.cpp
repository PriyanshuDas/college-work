#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll ans = 0, i = 3, j = 5;
	for (i; i < 1000; i += 3)
		ans += i;
	printf("%lld\n ", ans);
	for (j; j < 1000; j+= 5)
		ans += j;
	for(int k = 15; k < 1000; k+= 15)
		ans -= k;
	printf("%lld__%lld\n", i, j);
	printf("%lld\n", ans);
	return 0;
}