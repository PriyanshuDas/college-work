#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define ins insert
#define it_set set<ll>::iterator

using namespace std;

ll is_tri(ll A)   // n*n + n - 2*A = 0        n*(n+1)/2 = A
{
    ll c = -2*A, b = 1, a = 1;
    ll sq = b*b - 4*a*c;
    double D = sqrt(sq);
    if(abs(D - (ll)D) < 0.0001)
    {
        ll num = -b + (ll)D;
        if(num > 0 && (num%2 == 0))
            return  (num/2);
    }
    return -1;
}

ll is_penta(ll A)   // 3*n*n - n - 2*A = 0
{
    ll c = -2*A, b = -1, a = 3;
    ll sq = b*b - 4*a*c;
    double D = sqrt(sq);
    if(abs(D - (ll)D) < 0.00001)
    {
        ll num = -b + (ll)D;
        if(num > 0 && (num%6 == 0))
            return (num/6);
    }
    return -1;
}

int main()
{
    //pf("%d %d", is_tri(1), is_penta(40755));
    for(int i = 1; i < 100000; i++)
    {
        ll A = (i*(2*i - 1));
        ll j = is_tri(A), k = is_penta(A);
        if(j > 0 && k > 0)
            pf("Tri[%lld]\tPenta[%lld]\tHexa[%d] == %lld\n", j, k, i, A);
    }
    //pf("%d", is_penta(5));
    return 0;
}

