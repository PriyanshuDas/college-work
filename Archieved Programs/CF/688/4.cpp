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
#define limit 1000001

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <int> primes;
int ct[limit+1] = {0};
vector<int> Factors[limit];

int main()
{
	for(int i = 2; i < limit; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			primes.pb(i);
			Factors[i].pb(i);
			for(int j = i; j < limit; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				Factors[j].pb(i);
				not_prime[j] = 1;
			}
		}
	}

	int n, k;   cin >> n >> k;
    vector <int> c;
    for(int i = 0; i < n; i++)
    {
        int tmp;    sf("%d", &tmp);
        c.pb(tmp);
    }
	for(int i = 0; i < n; i++)
    {
        int curr = c[i];
        for(int i = 0; i < Factors[curr].size(); i++)
        {
            int c_f = Factors[curr][i];
            while(curr%c_f == 0)
            {
                curr /= c_f;
                ct[c_f]++;
            }
        }
    }
    int flag = 0;
    for(int i = 0; i < Factors[k].size(); i++)
    {
        int c_f = Factors[k][i];
        int t = 0;
        while(k%c_f == 0)
        {
            t++;
            k /= c_f;
        }
        if(ct[c_f] < t)
            flag = 1;
    }
    /*for(int i = 0; i < limit+1; i++)
    {
        if(ct[i] > 0)
            pf("ct[%d] == %d\n", i, ct[i]);
    }*/
    if(flag == 1)
        cout << "No";
    else
        cout << "Yes";
	return 0;
}
