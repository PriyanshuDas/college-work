#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define MIL 1000000
#define limit 1000000

using namespace std;

int not_prime[limit+1];
vector <int> primes;

string rev_str(string s)
{
    string t = s;
    //cout << s;
    for(int i = 0; i < t.size()/2; i++)
    {
        swap(t[i], t[t.size() - 1 - i]);
    }
    //cout << "Reversed is " << t << endl;
    return t;
}

string int_to_str(int I)
{
    string str;
    while(I > 0)
    {
        str += ((I%10) + '0');
        I /= 10;
    }
    return rev_str(str);
}

int str_to_int(string s)
{
    int num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        num *= 10;
        num += (s[i] - '0');
    }
    return num;
}

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
    ll ct = 0, ans = 0;
	for(int i = 4; i < primes.size(); i++)
    {
        int P = primes[i];
        int flag = 0;
        int mod = 1;
        while(P != 0)
        {
            if(not_prime[P])
                flag = 1;
            P /= 10;
            mod *= 10;
        }
        P = primes[i];
        while(P != 0)
        {
            if(not_prime[P])
                flag = 1;
            P = P%mod;
            mod /= 10;
        }
        if(flag == 1)
            continue;
        pf("%d\n", primes[i]);
        ct++;
        ans += primes[i];
    }
    pf("There are %lld Truncatable Primes.\nTheir sum is : %lld\n", ct, ans);
}
