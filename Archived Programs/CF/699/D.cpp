#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define max_n 200000

using namespace std;

int par[max_n+1];
int g_no[max_n+1];
vector<int> conn[max_n+1];
vector<int> graph[max_n+1];
int is_cyc[max_n+1];
int root[max_n + 1];
int root_g = -1;
int visited[max_n+1];
int curr_g = 0;

void dfs(int n, int p)
{
    //pf("@ %d with g_no %d\n", n, curr_g);
    visited[n] = -1;
    graph[curr_g].pb(n);
    int p_c = 0;
    for(int i = 0; i < conn[n].size(); i++)
    {
        int nxt = conn[n][i];
        if(nxt == n)
        {
            root[curr_g] = n;
        }
        if(nxt == p)
            p_c++;
        if(nxt != n && ((visited[nxt] == -1 && nxt != p) || (nxt == p && p_c == 2)))
        {
            root[curr_g] = nxt;
            is_cyc[curr_g] = 1;
        }
        if(visited[nxt] == 0)
            dfs(nxt, n);
    }
    visited[n] = 1;
}

int main()
{
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)
    {
        sf("%d", &par[i]);
        if(par[i] != i)
            conn[par[i]].pb(i);
        conn[i].pb(par[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i, -1);
            if(is_cyc[curr_g] == 0 && root_g == -1)
                root_g = curr_g;
            curr_g++;
        }
    }
    //pf("Root_Graph is %d, Root Node is %d\n", root_g, root[root_g]);
    if(root_g == -1)
    {
        root_g = 0;
    }
    int ct = 0;
    for(int i = 0; i < curr_g; i++)
    {
        //pf("root of graph[%d] is %d\n", i, root[i]);
        if(par[root[i]] != root[root_g])
        {
            ct++;
            par[root[i]] = root[root_g];
        }
    }
    cout << ct << endl;
    for(int i = 1; i <= n; i++)
        pf("%d ", par[i]);
    return 0;
}
