#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define b_pos 2001

using namespace std;

vector <int> up, rgt;

int m_up[b_pos + 2002][501];
int m_rgt[b_pos + 2002][501];

int up_dp(int y, int pos)
{
    if(pos >= up.size())
        return abs(y -b_pos);
    if(y > b_pos + 2000 || (y < b_pos - 1001))
        return 9999999;
    if(m_up[y][pos] != -1)
        return m_up[y][pos];
    m_up[y][pos] = min(up_dp(y+up[pos], pos+1),up_dp(y-up[pos], pos+1));
    //pf("@Y (%d. %d) == %d\n", y - b_pos, pos, m_up[y][pos]);
    return m_up[y][pos];
}

int rgt_dp(int x, int pos)
{
    if(pos >= rgt.size())
        return abs(x - b_pos);
    if(x > b_pos + 2000 || (x < b_pos - 1001))
        return 9999999;
    if(m_rgt[x][pos] != -1)
        return m_rgt[x][pos];
    m_rgt[x][pos] = min(rgt_dp(x+rgt[pos], pos+1),rgt_dp(x-rgt[pos], pos+1));
    //pf("@X (%d. %d) == %d\n", x - b_pos, pos, m_rgt[x][pos]);
    return m_rgt[x][pos];
}


int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        int tmp;    char c;
        int N;  sf("%d%d", &N, &tmp);
        memset(m_up, -1, sizeof(m_up));
        memset(m_rgt, -1, sizeof(m_rgt));
        up.clear(); rgt.clear();
        pair<int, int> dir = mp(0, 1);
        up.pb(tmp);
        for(int i = 0; i < N; i++)
        {
            cin >> c >> tmp;
            if(c == 'L')
            {
                if(dir.first == 1)
                    dir = mp(0, 1);
                else if(dir.first == -1)
                    dir = mp(0, -1);
                else if(dir.second == 1)
                    dir = mp(1, 0);
                else
                    dir = mp(-1, 0);
            }
            if(c == 'R')
            {
                if(dir.first == 1)
                    dir = mp(0, -1);
                else if(dir.first == -1)
                    dir = mp(0, 1);
                else if(dir.second == 1)
                    dir = mp(-1, 0);
                else
                    dir = mp(1, 0);
            }
            if(dir.first != 0)
                rgt.pb(dir.first*tmp);
            if(dir.second != 0)
                up.pb(dir.second*tmp);
        }
        int up_diff = up_dp(b_pos, 0);
        int rgt_diff = rgt_dp(b_pos, 0);
        int ans = up_diff + rgt_diff;
        cout << ans << endl;
    }
    return 0;
}
