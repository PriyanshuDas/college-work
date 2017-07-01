#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[101] = {0}, memo[101][4] = {0}, fin_ans = 999;

int dp(int pos, int prev)
{
    //pf("(%d, %d, %d)\n", pos, prev, tot);
    if(pos == n)
    {
        return 0;
    }
    if(pos > 0 && memo[pos][prev] != -1)
    {
        return memo[pos][prev];
    }
    memo[pos][prev] = 9999;
    if((a[pos] == 1 || a[pos] == 3) && prev != 1)
        memo[pos][prev] = min(memo[pos][prev], dp(pos+1, 1));
    if((a[pos] == 2 || a[pos] == 3) && prev != 2)
        memo[pos][prev] = min(memo[pos][prev], dp(pos+1, 2));
    memo[pos][prev] = min(memo[pos][prev], 1 + dp(pos+1, 0));
    return memo[pos][prev];
}

int main()
{
    cin >> n;
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++)
    {
        sf("%d", &a[i]);
    }
    fin_ans = dp(0, -1);
    cout << fin_ans;
    return 0;
}
