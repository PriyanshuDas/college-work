#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define ins insert
#define pb push_back
#define pi2 pair<ll,ll>
#define pi3 pair<ll, pair<ll, ll> >

using namespace std;

int main()
{
    int n;  cin >> n;
    int mis = 0, cris = 0;
    for(int i = 0; i < n; i++)
    {
        int m, c;   cin >> m >> c;
        if(m > c)
            mis++;
        if(c > m)
            cris++;
    }
    if(mis > cris)
        cout << "Mishka";
    if(cris > mis)
        cout << "Chris";
    if(cris == mis)
        cout << "Friendship is magic!^^";
    return 0;
}
