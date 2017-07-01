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
#define limit 10000000

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <int> primes;

vector<int> Factors[limit];

int main()
{
	for(int i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			primes.pb(i);
			for(int j = i; j < limit; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				Factors[j].pb(i);
				not_prime[j] = 1;
			}
		}
	}
	
	cout << "List of Primes :\n";
	for(int i = 0; primes[i] < 300; i++)
	{
		cout << primes[i]<< " ";
	}
	cout << endl;
	
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
