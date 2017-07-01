/*	Includes :
1>	Extended Euclid
2>	Inverse Modulo
3>	Permutation (Memorized) % MOD
4>	Combination (Memorized) % MOD
5>  Lucas Theorem
*/

/* Written by Priyanshu Das*/

#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define max_n 10000001

using namespace std;

ull perm[max_n+1];
ull MOD = 1000000007;

vector <ll> Ext_Euclid(ll a, ll b)	//Solve Ax + By = gcd(A, B)
{
	if(b == 0)
	{
		vector <ll> tmp;	tmp.pb(1);	tmp.pb(0);	tmp.pb(a);
		return tmp;
	}
	vector <ll> curr = Ext_Euclid(b, a%b), nu;
	nu.pb(curr[1]);	nu.pb(curr[0] - (a/b)*curr[1]);	nu.pb(curr[2]);
	return nu;
}

ll inverse_mod(ll n)				//find inverse mod of a number
{
	vector <ll> temp = Ext_Euclid(n, MOD);
	if(temp[0] < 0)	temp[0] += MOD;
	return temp[0];
}

void precomp()
{
	ull c = 1;
	perm[0] = 1;
	for(int i = 1; i < max_n; i++)
		perm[i] = c = (c*i)%MOD;
}

ull permute(ll n, ll r)
{
	if(r > n)	return 0;
	ull num = perm[n], den = (perm[r]*perm[n-r])%MOD;
	ull ans = (num*(ull)inverse_mod((ll)den))%MOD;
	return ans;
}

ull combine(ll n, ll r)
{
	ull num = perm[n], den = (perm[r]*perm[n-r])%MOD;
	den = inverse_mod((ll)den);
	ull ans = (num*den)%MOD;
	return ans;
}

ull lucas(ll n, ll r, ll p)
{
	vector <ll> ni, ri;
	ll nx = n, rx = r, ans = 1, o_m = MOD, MOD = p, i = 0;
	while(nx > 0 || rx > 0)
	{
		ni.pb(nx%p);	ri.pb(rx%p);
		nx /= p;	rx /= p;
		if(rx > nx)
			return 0;
		ans = (ans*combine(ni[i], ri[i]))%MOD,	i++;
	}
	MOD = o_m;
	return ans;
}

int main()								//Driver Program
{
	/*int flag=1;
	precomp();
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
				cin >> a;
				pf("%lld inverse is == %lld\n", a, inverse_mod(a));
				cout << "--------------------------------------\n\n";
				break;
			}
			case 3:
			{
				ll n, r;
				cout << "------------Permutations------------\n\nEnter n and r to get nPr % MOD : ";
				cin >> n >> r;
				pf("%lldP%lld == %llu\n", n, r, permute(n, r));
				cout << "------------------------------------\n";
				break;
			}
			case 4:
			{
				ll n, r;
				cout << "-----------Combinations------------\n\nEnter n and r to get nCr % MOD : ";
				cin >> n >> r;
				pf("%lldC%lld == %llu\n", n, r, combine(n, r));
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
	}*/
	precomp();
	ll n, r, p;
	pf("Enter n r p : ");	sf("%lld%lld%lld", &n, &r, &p);
	pf("Ans : %llu\n", lucas(n, r, p));
	return 0;
}
