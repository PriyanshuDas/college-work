#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define ull unsigned ll
#define MOD 1000000007
using namespace std;
//********** Careful when mod > 10^9, Might Overflow*************
ull expon(ull num, ull p)
{
	ull ans = 1;
	if(p == 0)	return ans;
	if(p%2 == 0)
	{
		ans = (expon(num, p/2));	return (ans*ans)%MOD;
	}
	ans = (num*expon(num, p-1))%MOD;
	return ans;
}

int main()
{
	ull n, p;	sf("%llu%llu", &n, &p);	pf("%llu\n", expon(n,p));
	return 0;
}
