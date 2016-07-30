#include <bits/stdc++.h>

#define pf printf
#define sf scanf

using namespace std;

int main()
{
	int N;
	cin >> N;
	long long int ANS = 1;
	long long int ans = 1;
	for (int i =2; i < N;)
	{
		printf("%lld + ", ans);
		ans += i;
		ANS += ans;
		printf("%lld + ", ans);
		ans += i;
		ANS += ans;
		printf("%lld + ", ans);
		ans += i;
		ANS += ans;
		printf("%lld + ", ans);
		ans += i;
		ANS += ans;
		i += 2;
	}
	printf("Answer is - %lld\n", ANS); 
	return 0;
}
