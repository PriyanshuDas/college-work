#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define ins insert

using namespace std;

int ans = 0;
string s, t;
int visited[1001][1001][11];
void dp(int x, int y, int total, int ans_curr)
{
    //pf("(%d, %d),   %d     %d\n", x, y, total, ans_curr);
    if(visited[x][y][total] > ans_curr)
        return;// visited[x][y][total];
    visited[x][y][total] = ans_curr;
    if(x >= s.size() || y >= t.size() || total >= 10)
        return;
    for(int i = 0; i < total; i++)
    {
        if(visited[x][y][i] >= ans_curr)
            return;
    }
    for(int i = 0; x+i < s.size() && y+i < t.size(); i++)
    {
        if(s[x+i] != t[x+i])
            break;
        dp(x+i+1, y+i+1, total+1, ans_curr+i+1);
    }
    dp(x+1, y, total, ans_curr);
    dp(x, y+1, total, ans_curr);
}

int main()
{
    int n, m, k;    cin >> n >> m >> k;
    memset(visited, -1, sizeof(visited));
    cin >> s >> t;
    dp(0, 0, 0, 0);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int l = 0; l <= k+1; l++)
                ans = max(ans, visited[i][j][l]);
        }
    }
    cout << ans;
}
