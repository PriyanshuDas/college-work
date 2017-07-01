#include <bits/stdc++.h>

#define ll long long int
#define mp make_pair
#define pb push_back
#define pf printf
#define sf scanf
#define loop(l,n) for(int i = l; i < n; i++)
#define Lim 10001

using namespace std;

bool not_prime[10005] = {0};
vector <int> prime;

template <class T>
void vec_inp(vector<T> *V)
{
    T x;
    cin >> x;
    V->pb(x);
}

int main()
{
    loop(2,Lim)
    {
        if(!not_prime[i])
        {
            prime.pb(i);
            for(ll j = i*i; j < Lim; j+= i)
                not_prime[j] = 1;
        }
    }
    int T;
    cin >> T;
    loop(0, T)
    {
        int N;
        cin >> N;
        vector <int> bucket;
        loop(0, N)
        {
            vec_inp(&bucket);
        }
        s
    }
    return 0;
}
