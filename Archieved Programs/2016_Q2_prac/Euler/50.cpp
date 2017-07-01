
#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 1000000
#define MIL 1000000

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <int> primes;

vector<int> Factors[limit];

int main()
{
    not_prime[0] = 1;
    not_prime[1] = 1;
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
	int m_pos = 1000;
	int ans = 0, ct = 0;
	for(int no = 21; no < m_pos; no++)
    {
        ll sum = 0;
        for(int i = 0; i < no; i++)
        {
            sum += primes[i];
        }
        if(not_prime[sum] == 0 && sum < MIL && sum > 953 && no > ct)
        {
            ct = no, ans = sum;
            //pf("%lld\twith %d consecutive primes\n", sum, no);
        }
        for(int pos = no; pos < m_pos; pos++)
        {
            sum += primes[pos];
            sum -= primes[pos-no];
            if(not_prime[sum] == 0 && sum < MIL && sum > 953)
            {
                ct = no, ans = sum;
                //pf("%lld\twith %d consecutive primes\n", sum, no);
            }
            if(sum > MIL)
                break;
        }
    }
    pf("The prime is : %d\twith %d consecutive primes", ans, ct);
    return 0;
}
