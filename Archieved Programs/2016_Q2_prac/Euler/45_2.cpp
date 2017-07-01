#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define ins insert
#define it_set set<ll>::iterator

using namespace std;
vector<ll> tri, penta, hexa;

int main()
{
    ll i = 1, j = 1, k = 1;
    for(i = 1; i < 100000; i++)
    {
        ll hexa = i*(2*i - 1);
        ll tri = 0;
        ll penta = 0;
        while(penta < hexa)
        {
            j++;
            penta = (j*(3*j - 1))/2;
        }
        while (tri < hexa)
        {
            k++;
            tri = (k*(k+1))/2;
        }
        if((tri == penta) && (penta == hexa))
        {
            cout << tri << endl;
        }
    }
}
