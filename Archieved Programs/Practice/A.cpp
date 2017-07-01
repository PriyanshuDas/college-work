#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define ll long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

ll memo_P[100501][301];

ll find_P(int n, int m)
{
   if(memo_P[n][m] != -1)
        return memo_P[n][m];
    if(m > n)
    {
        memo_P[n][m] = 0;
        return memo_P[n][m];
    }
    if(n == m)
    {
        memo_P[n][m] = 1;
        return 1;
    }
    if(m == 0)
    {
        memo_P[n][m] = 0;
        return 0;
    }
    memo_P[n][m] = (find_P(n-1, m-1) + find_P(n-m,m))%MOD;
    return memo_P[n][m];
}

ll perm(int X)
{
    ll ans = 1;
    for(int i = 0; i < X; i++)
    {
        ans = (ans*(X-i))%MOD;
    }
    return ans;
}

int main()
{
    memset(memo_P, -1, sizeof(memo_P));
    int T;
    sf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int N, M;
        cin >> M >> N;
        ll sum = (M*(M+1))/2;
        if(sum < N)
        {
            N -= sum;
        }
        else if(sum == N)
        {
            pf("1\n");
            continue;
        }
        else
        {
            pf("0\n");
            continue;
        }
        ll ans = 0;
        //cout << "Remaining apples : " << N << endl;
        for(int i = 1; i <= M; i++)
        {
            ll curr_find = find_P(N,i);
            //pf("Arranging %d apples in %d places == %lld\n",N, i, curr_find);
            ans = (ans + curr_find)%MOD;
        }
        if(ans > 0)
            ans= (ans*perm(M))%MOD;
        else
            ans = perm(M);
        pf("%lld\n", ans);
    }
    return 0;
}
