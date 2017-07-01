
#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 1000001

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <ll> primes;

ll N;
vector <pair<ll, int> > Factors;
vector <ll> ans_f;

ll calc(int pos, ll curr)
{
    //pf("@(%d, %lld)\n", pos, curr);
    ll ans = 0;
    if(curr >= N)
        return ans;
    if(pos == Factors.size())
    {
        if(curr < N && N%curr != 0)
        {
            return 1;
        }
        return 0;
    }
    ll n_c = curr;
    ll c_p = Factors[pos].first;
    for(int i = 0; i <= Factors[pos].second && n_c < N && n_c >= 0; i++)
    {
        ans += calc(pos+1, n_c);
        n_c = n_c*c_p;
    }
    return ans;
}

int main()
{
    not_prime[0] = 1;
    not_prime[1] = 1;
    cin >> N;
	for(int i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			primes.pb(i);
			for(ll j = i*i; j < limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				not_prime[j] = 1;
			}
		}
	}
	ll N2 = N;
	for(int i = 0; i < primes.size(); i++)
    {
        ll c = primes[i];
        int ct = 0;
        while(N2%c == 0)
        {
            ct++;
            N2 /= c;
        }
        if(ct > 0)
        {
            //pf("Pushing (%lld, %d)\n", c, ct);
            Factors.pb(mp(c, 2*ct));
        }
    }
    if(N2 > 1)
        Factors.pb(mp(N2, 1));
    ll ans = calc(0, 1);
    pf("%lld\n", ans);
    return 0;
}
