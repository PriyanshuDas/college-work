#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert
#define m_max 1000001
#define n_max 20

using namespace std;

ll dp[m_max+100][n_max+2];
int ct[m_max+100];
int main()
{
    int T;  cin >> T;
    for(int t = 0; t < T; t++)
    {
        int N;  cin >> N;
        vector <int> arr;
        memset(ct, 0, sizeof(ct));
        memset(dp, 0, sizeof(dp));
        for(int n = 0; n < N; n++)
        {
            int tmp;    sf("%d", &tmp);
            arr.pb(tmp);
            ct[tmp]++;
        }
        //dp[mask][n-1] gives answer for mask
        for(int i = 0; i <= m_max; i++)
            dp[i][0] = ct[i];
        for(int i = 1; i <= n_max; i++)
        {
            for(int mask = 0; mask <= m_max; mask++)
            {
                //cout << mask << '\t' << dp[mask][0] << endl;
                if((mask&(1<<(i-1))) == 0)
                {
                    dp[mask][i] = dp[mask][i-1];
                    if((mask^(1<<(i-1))) <= m_max)
                    {
                        dp[mask][i] += dp[(mask^(1<<(i-1)))][i-1];
                    }
                }
                else
                {
                    if((mask^(1<<(i-1))) <= m_max)
                    {
                        dp[mask][i] = dp[(mask^(1<<(i-1)))][i-1];
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            ans += dp[arr[i]][n_max];
        }
        cout << ans << endl;
    }
    return 0;
}
