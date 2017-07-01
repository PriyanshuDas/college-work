
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
		    if(i >= 1000 && i < 10000)
                primes.pb(i);
			for(int j = i*i; j < limit && j > 0; j+= i)	//Every time a prime is found, no of ops = limit/(prime), approx n*(logn)(logn)
			{
				//Factors[j].pb(i);
				not_prime[j] = 1;
			}
		}
	}
	cout << primes.size()<<endl;
	for(int i = 0; i < primes.size(); i++)
    {
        for(int j = i+1; j < primes.size(); j++)
        {
            int A = primes[i], B = primes[j];
            int D = B-A;
            int C = B + D;
            if(not_prime[C] == 0 && C < 10000)
            {
                int ct[3][10] = {0};
                int A_2 = A, B_2 = B, C_2 = C;
                while(A_2 > 0)
                {
                    ct[0][A_2%10]++;   ct[1][B_2%10]++;   ct[2][C_2%10]++;
                    A_2 /= 10;  B_2 /= 10;  C_2 /= 10;
                }
                int flag = 0;
                for(int k = 0; k < 10; k++)
                {
                    if(ct[0][k] != ct[1][k] || ct[0][k] != ct[2][k] || ct[1][k] != ct[2][k])
                        flag = 1;
                }
                if(flag == 0)
                    pf("Diff : %d\n%d %d %d\n", D, A, B, C);
            }
        }
    }
    return 0;
}
