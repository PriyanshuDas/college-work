/*	Includes :
1>	Extended Euclid
2>	Inverse Modulo
3>	Permutation (Memorized) % MOD
4>	Combination (Memorized) % MOD
*/

/* Written by Priyanshu Das*/

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define mp make_pair
#define pb push_back

using namespace std;

ll MOD = 1000000007;

ll perm[100000][100];
ll comb[100000][100];

vector <ll> Ext_Euclid(ll a, ll b)	//Solve Ax + By = gcd(A, B)
{
	if(b == 0)
	{
		vector <ll> tmp;	tmp.pb(1);	tmp.pb(0);	tmp.pb(a);
		return tmp;
	}
	vector <ll> curr = Ext_Euclid(b, a%b);
	vector <ll> nu;
	nu.pb(curr[1]);
	nu.pb(curr[0] - (a/b)*curr[1]);
	nu.pb(curr[2]);
	return nu;
}

ll inverse_mod(ll n)				//find inverse mod of a number
{
	vector <ll> temp = Ext_Euclid(n, MOD);
	if(temp[0] < 0)
		temp[0] += MOD;
	return temp[0];
}

ll permute(int n, int r)			//Calculate nPr % MOD
{
	if(perm[n][r] != 0)
		return perm[n][r];
	ll ans = 1;
	for(int i = n; i > n-r; i--)
	{
		ans = (ans*i)%MOD;
	}
	perm[n][r] = ans;
	return ans;
}

ll combine(int n, int r)				//Calculate nCr % MOD
{
	ll num = 1;
	ll den = 1;
	num = permute(n, r);
	den = permute(r, r);
	ll ans = num*(inverse_mod(den));
	return ans;
}

int main()								//Driver Program
{
	int flag=1;
	while(flag)
	{
		pf("Enter Choice of Demo :-\n(1) Extended Euclid\n(2) Inverse Modulo\n(3) Permutation\n(4) Combination\n(5) Quit\nEnter Choice : ");
		int choice;
		cin >> choice;
		switch(choice)
		{
			case 1:
			{
				ll a, b;
				cout << "------------Extended Euclid------------\n\nEnter A and B : ";
				cin >> a >> b;
				vector <ll> ans = Ext_Euclid(a, b);
				pf("(%lld)*%lld + (%lld)*%lld == %lld\n", ans[0], a, 					ans	[1], b, ans[2]);
				cout << "---------------------------------------\n\n";
				break;
			}
			case 2:
			{
				ll a;
				cout << "------------Inverse Modulo------------\n\nEnter A and MOD : ";
				cin >> a >> MOD;
				pf("%lld inverse is == %lld\n", a, inverse_mod(a));
				cout << "--------------------------------------\n\n";
				break;
			}
			case 3:
			{
				int n, r;
				cout << "------------Permutations------------\n\nEnter n and r to get nPr % MOD : ";
				cin >> n >> r;
				pf("%dP%d == %lld\n", n, r, permute(n, r));
				cout << "------------------------------------\n";
				break;
			}
			case 4:
			{
				int n, r;
				cout << "-----------Combinations------------\n\nEnter n and r to get nCr % MOD : ";
				cin >> n >> r;
				pf("%dC%d == %lld\n", n, r, combine(n, r));
				cout << "------------------------------------\n";
				break;
			}
			case 5:
			{
				flag = 0;
				break;
			}
			default:
				break;
		}
	}
	return 0;
}
