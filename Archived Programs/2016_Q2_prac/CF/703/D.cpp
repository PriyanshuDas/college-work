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

set<int> val;
vector <int> a;
map<int, int> M;
int ct[1000001][33] = {0};

int main()
{
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;  cin >> x;
        a.pb(x);
    }
    for(int i = 0; i < n; i++)
    {
        M[a[i]]++;
        if(M[a[i]]%2 == 0)
        {
            int ct = M[a[i]]/2;
        }
    }
    return 0;
}
