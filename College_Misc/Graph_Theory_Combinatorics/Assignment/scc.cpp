<<<<<<< HEAD
#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define max_size 1000000

using namespace std;
vector <int> conn[max_size];
stack <int> S;
int visited[max_size];
vector<pair<int, int> > edges;
void dfs(int node)
{
    visited[node] = 1;
    for(int i = 0; i < conn[node].size(); i++)
        if(!visited[conn[node][i]])
            dfs(conn[node][i]);
    S.push(node);
}

vector <int> curr_comp;

void dfs_2(int node)
{
    visited[node] = 1;
    curr_comp.pb(node);
    for(int i = 0; i < conn[node].size(); i++)
    {
        if(!visited[conn[node][i]])
            dfs_2(conn[node][i]);
    }
}
int main()
{
    int n;
    int m;
    cout << "Enter number of nodes and number of edges : ";
    cin >> n >> m;
    cout << "Enter (a b) if edge from a to b :\n";
    for(int i = 0; i < m; i++)
    {
        int a, b;
        sf("%d%d", &a, &b);
        conn[a].pb(b);
        edges.pb(mp(a, b));
    }
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        conn[i].clear();
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].first, b = edges[i].second;
        conn[b].pb(a);
    }
    cout << "The strongly connected components are :\n";
    while (!S.empty())
    {
        int node = S.top();
        S.pop();
        if(!visited[node])
        {
            dfs_2(node);
            cout << "{ ";
            for(int i = 0; i < curr_comp.size(); i++)
                pf("%d ", curr_comp[i]);
            cout << "}\n";
        }
        curr_comp.clear();
    }
    return 0;
}
=======
#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define ll long long int
#define pb push_back
#define mp make_pair
#define max_size 1000000

using namespace std;
vector <int> conn[max_size];
stack <int> S;
int visited[max_size];
vector<pair<int, int> > edges;
void dfs(int node)
{
    visited[node] = 1;
    for(int i = 0; i < conn[node].size(); i++)
        if(!visited[conn[node][i]])
            dfs(conn[node][i]);
    S.push(node);
}

vector <int> curr_comp;

void dfs_2(int node)
{
    visited[node] = 1;
    curr_comp.pb(node);
    for(int i = 0; i < conn[node].size(); i++)
    {
        if(!visited[conn[node][i]])
            dfs_2(conn[node][i]);
    }
}
int main()
{
    int n;
    int m;
    cout << "Enter number of nodes and number of edges : ";
    cin >> n >> m;
    cout << "Enter (a b) if edge from a to b :\n";
    for(int i = 0; i < m; i++)
    {
        int a, b;
        sf("%d%d", &a, &b);
        conn[a].pb(b);
        edges.pb(mp(a, b));
    }
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        conn[i].clear();
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].first, b = edges[i].second;
        conn[b].pb(a);
    }
    cout << "The strongly connected components are :\n";
    while (!S.empty())
    {
        int node = S.top();
        S.pop();
        if(!visited[node])
        {
            dfs_2(node);
            cout << "{ ";
            for(int i = 0; i < curr_comp.size(); i++)
                pf("%d ", curr_comp[i]);
            cout << "}\n";
        }
        curr_comp.clear();
    }
    return 0;
}
>>>>>>> d41c9ab97132aeab1446e831c5d1dfa0a46f1203
