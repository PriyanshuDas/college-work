#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define n_max 100001
#define int_max 9999999

using namespace std;

int main()
{
    double n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;
    double K = (n/k);
    int N = n, k1 = k;
    if(N%k1 > 0)
        K++;
    double d = v2*l/(2*v1*K+v2);
    pf("D is : %lf\n", d);
    double T1 = d/v2 + (l-d)/v1;
    double T2 = (l-d)/v2 + d/v1;
    double T3 = l/v1;
    double T = min(T1, min(T2, T3));
    pf("%0.9lf\n", T);
}
