#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define pii pair<int, int>
#define pi3 pair<int, pair<int, int> >

using namespace std;

int main()
{
    ll n, x, ct = 0;    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        char c; cin >> c;
        ll d;  cin >> d;
        if(c == '+')
            x += d;
        else if(x >= d)
            x -= d;
        else
            ct++;

    }
    cout << x << ' ' << ct;
    return 0;
}
