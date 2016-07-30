#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair

using namespace std;

int n, m;
vector <int> adj[100001];

int tail[100001];
int process[100001];

int dfs(int pos)
{
    int ans = 0;
    if(tail[pos] != -1)
        return tail[pos];
    process[pos] = -1;
    for(int i = 0; i < adj[pos].size(); i++)
    {
        if(adj[pos][i] < pos)
        {
            int tmp = dfs(adj[pos][i]);
            if(tmp > ans)
                ans = tmp;
        }
    }
    ans++;
    tail[pos] = ans;
    return tail[pos];
}


int main()
{
    cin >> n >> m;
    //memset(spines, -1, sizeof(spines));
    memset(tail, -1, sizeof(tail));
    for(int i = 0; i < m; i++)
    {
        int s1, s2;
        sf("%d%d", &s1, &s2);
        adj[s1].pb(s2);
        adj[s2].pb(s1);
    }
    for(int i = 1; i <= n; i++)
    {
        dfs(i);
    }
    ll max_ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ll tmp = tail[i]*(adj[i].size());
        if(tmp > max_ans)
            max_ans = tmp;
    }
    cout << max_ans;
    return 0;
}
