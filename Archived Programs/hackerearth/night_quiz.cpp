#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pf printf
#define sf scanf
#define limit2 1000001

using namespace std;

bool not_prime[limit2+1];		//limit defined in preprocessor directive
vector <int> primes;
vector <int> prime_fac[limit2+1];
vector <int> factors[limit2+1];
int fin_ans[limit2+1];
int ct[limit2+1];

void factorize(int N, int pos, int curr)
{
    if(pos == prime_fac[N].size())
    {
        factors[N].pb(curr);
        return;
    }
    int n2 = N;
    factorize(N, pos+1, curr);
    int c2 = curr;
    while(n2%prime_fac[N][pos] == 0)
    {
        n2 /= prime_fac[N][pos];
        c2 *= prime_fac[N][pos];
        factorize(N, pos+1, c2);
    }
    return;
}

int main()
{
    not_prime[1] = 1;
	for(int i = 2; i < limit2; i++)			// 1 is not considered for prime factorization!
	{
		if(!not_prime[i])
		{
			primes.pb(i);
			for(ll j = 2*i; j < limit2; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				not_prime[j] = 1;
				prime_fac[j].pb(i);
			}
		}
	}
	for(int i = 1; i < limit2; i++)
    {
        factorize(i, 0, 1);
        int n2 = i;
        int ans = 0;
        //pf("Factors for %d are : ", N);
        for(int j = 0; j < factors[i].size(); j++)
        {
            int c = factors[i][j];
            //pf("%d\t", c);
            if(not_prime[c] && not_prime[i/c] && c != i/c)
                ans++;
        }
        //pf("\n");
        ans /= 2;
        fin_ans[i] = ans;
        for(int j = 0; j < prime_fac[i].size(); j++)
        {
            while(n2%prime_fac[i][j] == 0)
            {
                n2 /= prime_fac[i][j];
                ct[i]++;
            }
        }
    }
	int T;  cin >> T;
	for(int t = 0; t < T; t++)
    {
        int N;  sf("%d", &N);
        //factors.clear();
        //factorize(N, 0, 1);
        //pf("count[%d]\t%d\n", N, ct[N]);
        if(ct[N] == 3)
        {
            pf("-1\n");
            continue;
        }
        else
            pf("%d\n", fin_ans[N]);
    }
	return 0;
}
