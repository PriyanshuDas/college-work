#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define N_max 10000000

using namespace std;
ll l_prime[N_max] = {0};

int main()
{
    vector<ll> primes;
   // pf("%lld\n", N_max);
    for(ll i = 2; i < N_max; i++)
    {
        //pf("%lld\n", i);
        if(l_prime[i] == 0)
            primes.pb(i);
        l_prime[i] = i;
        for(int j = 0; j < primes.size() && primes[j] < l_prime[i] && i*primes[j] < N_max; j++)
        {
            l_prime[i*primes[j]] = primes[j];
        }
    }
    ll q;   cin >> q;
    ll ct = 0;
    ll beg = 0;
    ll lst = 0;
    for(int i = 0; i < primes.size(); i++)
    {
        while(q%primes[i] == 0)
        {
            if(beg == 0)
                beg = primes[i];
            else
                lst = primes[i];
            ct++;
            q /= primes[i];
        }
    }
    if(q > 1)
    {
        lst = q;
        ct++;
    }
    if(ct != 2)
    {
        ll ans = lst*beg;
        cout << 1 << endl << ans;
    }
    else
        cout << 2;
    return 0;
}
