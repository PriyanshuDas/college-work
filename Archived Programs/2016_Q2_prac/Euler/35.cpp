#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 100000000

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <int> primes;

int main()
{
    not_prime[0] = 1;
    not_prime[1] = 1;
	for(int i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			primes.pb(i);
			for(ll j = i; j < limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				not_prime[j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < primes.size(); i++)
    {
        int ct[10] = {0};
        int dig = 0;
        int n = primes[i];
        while(n > 0)
        {
            dig++;
            ct[n%10]++;
            n /= 10;
        }
        int flag = 0;
        for(int j = 1; j <= dig; j++)
        {
            if(ct[j] == 0)
                flag = 1;
        }
        if(flag == 0)
            ans = primes[i];
    }
    cout << "Largest PanDigital Prime is : " << ans << endl;
	return 0;
}
