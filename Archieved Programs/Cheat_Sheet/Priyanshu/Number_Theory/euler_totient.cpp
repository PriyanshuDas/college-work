#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit 10000

using namespace std;

bool not_prime[limit];		//limit defined in preprocessor directive
vector <int> primes;
vector<int> Factors[limit];
ll ans = 0;
void simple_sum(ll N, int pos, ll prod)
{
    if(pos >= Factors[N].size())
    {
        ans += N/prod;
        return;
    }
    ll curr = Factors[N][pos];
    ll temp = 1;
    while(N%(temp*curr) == 0)
    {
        simple_sum(N, pos+1, prod*temp);
        temp *= curr;
    }
}

ll euler_tot(ll N)
{
    ll ans = N;
    for(int i = 0; i < Factors[N].size(); i++)
    {
        ans -= ans/Factors[N][i];
    }
    return ans;
}


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
		else
        {
            Factors[i].pb(i);
        }
	}
    int N;
    cin >> N;
    ans = euler_tot(N);
    cout << ans;
    return 0;
}
