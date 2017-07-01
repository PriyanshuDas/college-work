#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define m_size 100001
#define mp make_pair
#define pb push_back

using namespace std;
vector<int> conn[m_size + 1];
int visited[m_size+1] = {0};
int flag = 0;

void bfs(int n)
{
    queue<pair<int, int> > q;
    q.push(mp(n, 1));
    while(!(q.empty()))
    {
        int curr = q.front().first;
        int col = q.front().second;
        //pf("@%d\t%d\n", curr, col);
        q.pop();
        for(int i = 0; i < conn[curr].size(); i++)
        {
            int nex = conn[curr][i];
            if(visited[nex] == col)
                flag = 1;
            if(visited[nex] == 0 && col == 1)
            {
                visited[nex] = 2;
                q.push(mp(nex, 2));
            }
            else if(visited[nex] == 0 && col == 2)
            {
                visited[nex] = 1;
                q.push(mp(nex, 1));
            }
        }
    }
}

int main()
{
    int n, m;   cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;   cin >> u >> v;
        conn[u].pb(v);  conn[v].pb(u);
    }
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
            bfs(i);
    }
    if(flag == 1)
    {
        cout << -1;
        return 0;
    }
    vector<int> c1, c2;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 1)
            c1.pb(i);
        if(visited[i] == 2)
            c2.pb(i);
    }
    pf("%d\n", c1.size());
    for(int i = 0; i < c1.size(); i++)
        pf("%d ", c1[i]);
    pf("\n%d\n", c2.size());
    for(int i = 0; i < c2.size(); i++)
        pf("%d ", c2[i]);
    return 0;
}
