#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define ll long long int
using namespace std;

int ct = 1;
int app = 0;

int cont_f(int x, int y, int z)
{
	//pf(" x = %d, y = %d, z = %d\n", x, y, z);
	if (z == 1)
		return ct;
	ct++;
	int irt = sqrt(x);
	int z1 = (x - y*y)/z;
	//int y1 = (z1 - y%z1);
	int y1 = app - (y+app)%z1;
	//pf(" x = %d, y1 = %d, z1 = %d\n", x, y1, z1);
	return cont_f(x, y1, z1);
}

int main()
{
	int ans = 0;
	int inp = 0;
	sf("%d", &inp);
	for(int i = 2; i <= inp; i++)
	{
		ct = 0;
		int p;
		float fsqrt = sqrt(i);
		int isqrt = sqrt(i);
		app = isqrt;
		if(fsqrt == isqrt)
			continue;
		int Z = (i - isqrt*isqrt);
		int Y = (isqrt - (2*isqrt)%Z);
		ct = 1;
		p = cont_f(i, Y, Z);
		if (p%2)
			ans++;
	}
	/*int isrt = sqrt(inp);
	app = isrt;
	int zee = (inp - isrt*isrt);
	int why = (isrt - (isrt + isrt)%zee);
	ans = cont_f(inp, why, zee);*/
	pf("The Ans is - %d\n", ans);
	return 0;
}