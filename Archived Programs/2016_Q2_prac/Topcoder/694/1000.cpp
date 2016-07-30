#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pb push_back
#define ll long long int
#define mp make_pair
#define MOD 1000*1000*1000+7

using namespace std;

int f_time = 1;
int dp_ct[51][5001];
int cont(int N, int K)
{
    f_time = 0;
    if(N < 0 || K < 0)
        return 0;
    if(K == 0)
        return 1;
    if(N == 1)
        return 0;
    if(dp_ct[N][K] != -1)
        return dp_ct[N][K];
    if(dp_ct[N][K] == -1)
    {
        dp_ct[N][K] = 0;
        pf("[%d][%d]\n\n", N, K);
        for(int i = 0; i < N; i++)
        {
            pf("%d %d\n", i, dp_ct[N][K]);
            dp_ct[N][K] = (dp_ct[N][K] + cont(N-1, K-i*(N-1-i)))%MOD;
        }
    }
    pf("@(%d, %d) == %d\n", N, K, dp_ct[N][K]);
    return dp_ct[N][K];
    return 0;
}

int main()
{
    int N, K;   cin >> N >> K;
    memset(dp_ct, -1, sizeof(dp_ct));
    int ans = cont(N, K);
    return 0;
}
