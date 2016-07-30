#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define pb push_back
#define ll long long int

using namespace std;

int B[303];
int mult(int X[303], int Y[303])
{
	int ANS[303] = {0};
	int k = 0;
	for (int i = 0; i < 303; ++i)
	{
		k = i;
		for (int j = 0; j < 303; j++)
		{
			ANS[k]+= X[i]*Y[j];
			if (k < 302)
				ANS[k+1] += ANS[k]/10;
			ANS[k] %= 10;
			k++;
		}
	}
	for (int i = 0; i < 303; i++)
	{
		//pf("%d", ANS[i]);
		B[i] = ANS[i];
	}
	return 0;
}
int main()
{
	ll ans = 1;
	int I = 0;
	int two_50[303] = {0};
	for (int z = 1; z <= 50; z++)
	{
		ans*=2;
	}
	//cout << ans << "\n";
	while(ans >0)
	{
		two_50[I] = ans%10;
		//pf("%d", two_50[I]);
		ans/=10;
		I++;
	}
	/*int sample[303] = {1,2,3};
	mult(sample,sample);
	for (int i = 0; i < 303; i++)
		pf("%d",B[i]);*/
	pf("\n");
	mult(two_50, two_50);
	int two_100[303];
	for (int i = 0; i < 303; i++)
		two_100[i] = B[i];
	pf("\n");
	mult(two_100, two_100);
	int two_200[303];
	for (int i = 0; i < 303; i++)
		two_200[i] = B[i];
	pf("\n");
	mult(two_200, two_200);
	int two_400[303];
	for (int i = 0; i < 303; i++)
		two_400[i] = B[i];
	pf("\n");
	mult(two_400, two_400);
	int two_800[303];
	for (int i = 0; i < 303; i++)
		two_800[i] = B[i];
	pf("\n");
	mult(two_800, two_200);
	int two_1000[303];
	for (int i = 0; i < 303; i++)
		two_1000[i] = B[i];
	pf("\n");
	for (int i =0; i < 303; i++)
	{
		ans+= two_1000[i];
	}	
	pf("%lld\n", ans);
	return 0;
}