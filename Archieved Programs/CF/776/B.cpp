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
//vector <int> primes;

//vector<int> Factors[limit];

int main()
{
    not_prime[0] = 1;
    not_prime[1] = 1;
	for(ll i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			//primes.pb(i);
			for(ll j = i*i; j < limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				//Factors[j].pb(i);
				not_prime[j] = 1;
			}
		}
	}
	int n;
	cin >> n;
	n++;
	int mx = 1;
	vector <int> Ans;
	for(int i = 2; i <= n; i++)
	{
		if(not_prime[i])
		{
			Ans.pb(2);
			mx = 2;
		}
		else
			Ans.pb(1);
	}
	cout << mx << endl;
	for(int i = 0; i < Ans.size(); i++)
		cout << Ans[i] << ' ';
	cout << endl;
	return 0;
}