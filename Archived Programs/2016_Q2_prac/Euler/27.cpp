/* (1)	Prime Generation (Sieve of Erastothenes)

	Written by Priyanshu Das	*/

#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 100000

using namespace std;

bool not_prime[limit + 1];		//limit defined in preprocessor directive
vector <int> primes;

int main()
{
	for(int i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
	    //pf("@%d\n", i);
		if(!not_prime[i])
		{
			primes.pb(i);
			for(ll j = i*i; j <= limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				not_prime[j] = 1;
			}
		}
	}
	//cout << "List of Primes :\n";
	ll ans = 0, a_ans = 0, b_ans = 0;
    ll m_ct = 0;
	for(int a = -999; a < 1000; a++)
    {
        for(int b = -999; b < 1000; b++)
        {
            ll n = 0, ct = 0;
            while (n < limit)
            {
                ll n2 = n*n, n3 = a*n;
                ll num = n2 + n3 + b;
                if(not_prime[num] == 1 || num < 0)
                    break;
                ct++;   n++;
            }
            if(ct >= m_ct)
            {
                //pf("(%d, %d) => %lld consecutive primes\n", a, b, ct);
                m_ct = ct;
                ans = a*b;
                a_ans = a, b_ans = b;
            }
        }
    }
    pf("%lld * %lld == %lld gives %lld consecutive primes\n", a_ans, b_ans, ans, m_ct);
	return 0;
}
