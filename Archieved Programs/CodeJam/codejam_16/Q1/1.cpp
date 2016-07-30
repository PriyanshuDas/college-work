#include <bits/stdc++.h>

#define ll long long int
#define sf scanf
#define pf printf
#define max_lim 100000000

using namespace std;

int flag = 0;
bool ct[10];

bool decon(ll num)
{
    while(num != 0)
    {
        int tmp = num%10;
        ct[tmp] = true;
        num /= 10;
    }
    int ans = true;
    for(int i = 0; i < 10; i++)
    {
        if(!ct[i])
            ans = false;
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        memset(ct, 0, sizeof(ct));
        int N;
        sf("%d", &N);
        int flag = false;
        ll tmp = N;
        int j = 1;
        for(j = 0; j < max_lim && !flag; j++)
        {
            flag = decon(tmp);
            tmp += N;
        }
        tmp -= N;
        pf("Case #%d: ", t+1);
        if(!flag)
            pf("INSOMNIA\n");
        else
            pf("%lld\n", tmp);
    }
}
