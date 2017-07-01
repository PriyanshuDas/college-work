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

ll gcd (ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int T;  cin >> T;
    for(int t = 0; t < T; t++)
    {
        ll A, B, C, D;  cin >> A >> B >> C >> D;
        ll diff = abs(B-A), g = gcd(C, D);
        ll fin = diff%g;
        ll fin2 = abs(fin-g);
        cout << min(fin, fin2) << endl;
    }
    return 0;
}


