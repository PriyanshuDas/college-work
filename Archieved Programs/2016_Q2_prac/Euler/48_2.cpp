#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back

using namespace std;

int main()
{
    ll M = 10000000000, sum = 0;
    for(int i = 1; i <= 1000; i++)
    {
        ll curr = 1;
        for(int j = 1; j <= i; j++)
        {
            curr = (curr*i)%M;
        }
        if(i == 99)
            cout << curr<<endl;
        sum = (sum+curr)%M;
    }
    pf("%lld\n", sum);
    return 0;
}
