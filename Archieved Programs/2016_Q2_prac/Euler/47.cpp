/*	Prime Numbers Part I
	Includes :
(1)	Prime Generation (Sieve of Erastothenes)
(2) Prime Factorisation (No powers)

	Written by Priyanshu Das	*/

#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 1000000

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
			for(ll j = i; j < limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				Factors[j].pb(i);
				not_prime[j] = 1;
			}
		}
	}
    for(int i = 2; i < limit; i++)
    {
        if(Factors[i].size() == 4 && Factors[i+1].size() == 4 && Factors[i+2].size() == 4 && Factors[i+3].size() == 4)
            cout << i << '\t';
    }

	/*for(int i = 2; i < limit; i++)
	{
		pf("Prime Factors for %d : \n", i);
		for(int j = 0; j < Factors[i].size(); j++)
		{
			pf("%d ", Factors[i][j]);
		}
		pf("\n");
	}*/
	return 0;
}
