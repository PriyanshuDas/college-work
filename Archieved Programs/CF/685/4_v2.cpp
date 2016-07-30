#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define mp make_pair
#define pb push_back
#define max_n 300001

using namespace std;
int par[max_n+1];
vector<int> child[max_n+1];
int sz[max_n+1];
int centr[max_n+1];
int heav_ch[max_n+1];

void dfs_sz(int n)
{
    int ans = 1;
    int m_s = 0, m_n = 0;
    for(int i = 0; i < child[n].size(); i++)
    {
        dfs_sz(child[n][i]);
        ans += sz[child[n][i]];
        if(sz[child[n][i]] > m_s)
        {
            m_s = sz[child[n][i]];
            m_n = child[n][i];
        }
    }
    heav_ch[n] = m_n;
    sz[n] = ans;
}

bool is_centroid(int n, int c)
{
    int m_s = sz[heav_ch[c]];
    if(2*m_s <= sz[n] && 2*(sz[n] - sz[c]) <= sz[n])
        return true;
    return false;
}

int centroid(int n)
{
    if(sz[n] == 1)
    {
        centr[n] = n;
        return n;
    }
    int m_s = 0, m_n = n;
    for(int i = 0; i < child[n].size(); i++)
    {
        centroid(child[n][i]);
        if(sz[child[n][i]] > m_s)
        {
            m_s = sz[child[n][i]];
            m_n = child[n][i];
        }
    }
    if(2*m_s <= sz[n])
    {
        centr[n] = n;
        return n;
    }
    int c_cent = centr[m_n];
    while(!is_centroid(n, c_cent))
    {
        c_cent = par[c_cent];
    }
    centr[n] = c_cent;
    return centr[n];
}


int main()
{
    int n, q;   sf("%d%d", &n, &q);
    for(int i = 2; i <= n; i++)
    {
        sf("%d", &par[i]);
        child[par[i]].pb(i);
    }
    dfs_sz(1);
    centroid(1);
    for(int i = 0; i < q; i++)
    {
        int tmp;    sf("%d", &tmp);
        pf("%d\n", centr[tmp]);
    }
    return 0;
}
