#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define ins insert
#define it_set set<ll>::iterator

using namespace std;

set <ll> pent_n;
vector <ll> penta;

bool is_penta(ll n)
{
    ll num = 2*n;   //num = 3(n*n) - n
    ll a = 3, b = -1, c = -num;
    double D = b*b - 4*a*c;
    double rt = sqrt(D);
    //cout << rt << endl;
    if(abs(rt - (ll)rt) < 0.001)
    {
        ll num = -b + (ll)rt;
        //cout << num << endl;
        if(num%(2*a) == 0)
            return true;
    }
    return false;
}

int main()
{
    for(int i = 1; i < 100000; i++)
    {
        ll A = (i*(3*i - 1))/2;
        for(int j = 1; j < i; j++)
        {
            ll B = (j*(3*j-1))/2;
            if(is_penta(A-B) && is_penta(A+B))
            {
                pf("%lld\n", (A-B));
            }
        }
    }
    //pf("%d", is_penta(5));
    return 0;
}
