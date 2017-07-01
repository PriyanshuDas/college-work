#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define ins insert
#define limit 1000000000

using namespace std;

bool penta[limit+1] = {0};
vector <int> p_chill;
int main()
{
    for(int i = 1; i < limit; i++)
    {
        ll pent = (i*(3*i - 1))/2;
        if(pent > limit || pent < 0)
            break;
        penta[pent] = 1;
        p_chill.pb(pent);
    }
    sort(p_chill.begin(), p_chill.end());
    //cout << "Haah!\n";
    ll ans = 0;
    for(int i = 0; i < p_chill.size(); i++)
    {
        //cout << p_chill[i] << endl;
        for(int j = i+1; j < p_chill.size(); j++)
        {
            //cout << '\t' << p_chill[j] << endl;
            ll a = p_chill[i];
            ll b = p_chill[j];
            ll p = (a+b)/2;
            ll m = abs(a-b)/2;
            if((a+b)%2 == 0 && (a+b) > 0 && penta[p] == 1 && penta[m])
            {
                cout << a << ' ' << b << ' ' << m << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
